
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp"

//Construimos al jugador
Jugador::Jugador(float _deltaTime)
{
    frameTime = _deltaTime;
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
        posJugador.x -= velJugador.x * frameTime;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        posJugador.x += velJugador.x * frameTime;
    }
}

// Aplicamos salto simple
void Jugador::saltar()
{
    if (IsKeyPressed(KEY_SPACE)) {
        //PlaySound(jump);
        posJugador.y -= velJugador.y;
    }
    else if (posJugador.y <= (768 / 2)) {

        posJugador.y += velJugador.y; //* deltaTime;
    }
}

// Reiniciamos la pos del jugador para su punto de partida
void Jugador::reiniciarPos()
{
    posJugador = velJugador;
}
