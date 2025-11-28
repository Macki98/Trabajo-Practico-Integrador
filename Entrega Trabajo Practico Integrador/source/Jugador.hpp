#pragma once

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

class Jugador
{
private:
	
    //sonido para el salto
    Sound jump = LoadSound("Assets/jump.wav");

    // textura del personaje
    Texture2D personaje = LoadTexture("Assets/Knight.png");

    // Posicion predeterminada del personaje
    const Vector2 posInicial = { 150, (768 / 2) };

    // Posicion del personaje
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

    
    bool estaVivo;
    //pendiente para agregar al constructor e inicializar las variables cuando se llama a Game();
	Jugador();
	~Jugador();

    void caminar();
    void saltar(float _deltaTime);
    void recibirDaño();
    void dibujarPersonaje();
    void reiniciarPos();
    float obtenerPos();
  

};

