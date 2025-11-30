#pragma once

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class Jugador
{
private:
	
    //sonido para el salto
    Sound jump = LoadSound("Assets/jump.wav");

    // textura del personaje
    Texture2D personaje = LoadTexture("Assets/Knight.png");

    // Posicion del personaje
    Vector2 posJugador;

    // Posicion predeterminada del personaje
    const Vector2 posInicial = { 150, (768 / 2) };

    // velocidad que se le asignara al personaje
    Vector2 velJugador = {250.0f,0.0f };

    //Gravedad
    float gravedad = 300;

    //Jump force
    float jumpForce = -350.0f;

    // Color del personaje
    Color colJugador = WHITE;

    // Rotacion del personaje
    float rotJugador = 0.0f;

    // Escalado del personaje
    float escJugador = 0.07f;


    //Hitbox del personaje
    Rectangle hitBoxJ = {posJugador.x,posJugador.y, (float)personaje.width * escJugador, (float)personaje.height * escJugador };
    

public:

    
    //pendiente para agregar al constructor e inicializar las variables cuando se llama a Game();
	Jugador(float _x, float _y);
	~Jugador();


   
    void dibujarHitBoxJ(bool colisiona, float _deltaTime);
    void dibujarPersonaje();
    Rectangle GetRecJ();
    float GetVelocidad();
    float SetVelocidad();


    void caminar(float _deltaTime);
    void saltar(float _deltaTime);



    void recibirDaño();
   

    void reiniciarPos();
    float obtenerPos();

  

};

