
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp"

//Construimos al jugador
Jugador::Jugador()
{
    
}

Jugador::~Jugador()
{
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
    posJugador = posInicial;
}

float Jugador::obtenerPos()
{
    return posJugador.x,posJugador.y;
}
