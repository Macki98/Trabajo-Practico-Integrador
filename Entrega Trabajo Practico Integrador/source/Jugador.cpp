
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
    UnloadTexture(personaje);
    UnloadSound(jump);
}

Rectangle Jugador::GetRecJ()
{
    return Rectangle{ posJugador.x, posJugador.y,(float)personaje.width * escJugador, (float)personaje.height * escJugador };
}

float Jugador::GetVelocidad()
{
    return velJugador.y;
}



//Detectar colisiones con plataforma
void Jugador::checkColisionesPlat(bool _colisiona)
{
    
    //Color colorLinea = _colisiona ? RED : GREEN;
    //DrawRectangleLinesEx(GetRecJ(), 5, colorLinea);
    
    if (_colisiona) {
         
        velJugador.y = 0;
    }
   
}

void Jugador::checkColisionesEne(bool _colisiona)
{
    Color colorLinea = _colisiona ? RED : GREEN;
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
        if (posJugador.x <= 0){
            posJugador.x = 0;
        }
    }

    if (IsKeyDown(KEY_RIGHT)) {
        posJugador.x += velJugador.x * _deltaTime;
        if (posJugador.x + ((float)personaje.width*escJugador) >= SCREEN_WIDTH)
        {
            posJugador.x = SCREEN_WIDTH - ((float)personaje.width * escJugador);
        }
    }
}

// Aplicamos salto 
void Jugador::saltar(float _deltaTime)
{
    posJugador.y += velJugador.y * _deltaTime;

    if (IsKeyPressed(KEY_SPACE) && velJugador.y == 0){
        PlaySound(jump);
        velJugador.y = jumpForce;
        posJugador.y += velJugador.y * _deltaTime;
    }
    
    velJugador.y += gravedad * _deltaTime;

    if (posJugador.y <= 0)
    {
        posJugador.y = 0;

    }
    
}

float Jugador::obtenerPosY()
{
    return posJugador.y + ((float)personaje.height*escJugador);
}


// Reiniciamos la pos del jugador para su punto de partida
void Jugador::reiniciarPos()
{
    if (IsKeyPressed(KEY_R)) {
        posJugador = posInicial;
    }
}

void Jugador::dibujarPos()
{
    DrawText(TextFormat("Posicion del jugador: X: %.2f Y: %.2f", posJugador.x, posJugador.y), 2, 50, 25, BLACK);
}
