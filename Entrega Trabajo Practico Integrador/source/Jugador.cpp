
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

void Jugador::dibujarHitBoxJ()
{
    DrawRectangleLinesEx(GetRecJ(), 5, RED);
}

// Funcion que nos dibuja el personaje en pantalla
void Jugador::dibujarPersonaje()
{
    DrawTextureEx(personaje, posJugador, rotJugador, escJugador, colJugador);
}


// Aplicamos movimiento horizontal  (izq y der ) sobre el pesonaje utilizando flecha izquierda y derecha 
void Jugador::caminar()
{
    if (IsKeyDown(KEY_LEFT)) {
        posJugador.x -= velJugador.x;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        posJugador.x += velJugador.x;
    }
}

// Aplicamos salto simple
void Jugador::saltar(float _deltaTime)
{
    if (IsKeyPressed(KEY_SPACE)) {
        PlaySound(jump);
        posJugador.y -= velJugador.y;
    }
    else if (posJugador.y <= (768 / 2)) {

        posJugador.y += velJugador.y * _deltaTime;
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
