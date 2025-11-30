
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

//Construimos al jugador
Jugador::Jugador(float _x, float _y)
{

    posJugador.x = _x;
    posJugador.y = _y;

}

Jugador::~Jugador()
{
}

Rectangle Jugador::GetRecJ()
{
    return Rectangle{posJugador.x, posJugador.y,(float)personaje.width*escJugador, (float)personaje.height*escJugador};
}

void Jugador::dibujarHitBoxJ(bool colisiona)
{
    Color colorLinea = colisiona ? RED : GREEN;
    DrawRectangleLinesEx(GetRecJ(), 5, colorLinea);
}

// Funcion que nos dibuja el personaje en pantalla
void Jugador::dibujarPersonaje()
{
    DrawTextureEx(personaje, posJugador, rotJugador, escJugador, colJugador);
}


// Aplicamos movimiento horizontal  (izq y der ) sobre el pesonaje utilizando flecha izquierda y derecha 
void Jugador::caminar(float _deltaTime)
{
    if (IsKeyDown(KEY_LEFT)) {
        posJugador.x -= velJugador.x * _deltaTime;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        posJugador.x += velJugador.x * _deltaTime;
    }
}

// Aplicamos salto 
void Jugador::saltar(float _deltaTime)
{
    if (IsKeyPressed(KEY_SPACE) && velJugador.y == 0) {
        PlaySound(jump);
        velJugador.y = jumpForce;
    }
    else
    {
        velJugador.y += gravedad * _deltaTime;
    }

    posJugador.y += velJugador.y * _deltaTime;


    //Condional para que el jugador no se salga de la pantalla.
    if (posJugador.y + ((float)personaje.height * escJugador) >= SCREEN_HEIGHT) {
        posJugador.y = SCREEN_HEIGHT - ((float)personaje.height * escJugador);
    }
}



void Jugador::recibirDaño()
{
}

// Reiniciamos la pos del jugador para su punto de partida
void Jugador::reiniciarPos()
{
    if (IsKeyPressed(KEY_R)) {
        posJugador = posInicial;
    }
}

float Jugador::obtenerPos()
{
    return posJugador.x,posJugador.y;
}
