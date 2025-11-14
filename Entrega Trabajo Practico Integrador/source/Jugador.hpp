#pragma once

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>

class Jugador
{
private:
	
    bool estaVivo = true;

    Texture2D personaje = LoadTexture("Assets/knight.png");

    // Posicion inicial del personaje
    Vector2 posJugador = { 150, (768 / 2) };

    // velocidad que se le asignara al personaje
    Vector2 velJugador = { 5.0f, 100.0f };

    // Color del personaje
    Color colJugador = WHITE;

    // Rotacion del personaje
    float rotJugador = 0.0f;

    // Escalado del personaje
    float escJugador = 0.15f;

public:
	Jugador();
	~Jugador();

    void caminar();
    void saltar();
    void recibirDaño();
    void dibujarPersonaje();

};

