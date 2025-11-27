#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp" 
#include "Game.hpp"

#include "raymath.h"


int main(void)
{


    Rectangle pantalla = { 0,0,1024, 768 };

    InitWindow(pantalla.width, pantalla.height, "Nivel 1 - Alcanza la zona");

    SetTargetFPS(60);

    Game* partida = new Game();
    Jugador* J1 = new Jugador();


    // Iniciamos el dispocitivo de audio
    InitAudioDevice();
  

    // Color del Boton
    Color colorBoton = BLACK;

    // Radio del Boton
    float r = 50;

    // Boton para cambiar de color el fondo
    Vector2 Boton = { 970, 50 };

    
  
    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose()) 
    {
        float deltaTime = GetFrameTime();
        J1->caminar();
        J1->saltar(deltaTime);
        J1->obtenerPos();
        J1->reiniciarPos();

        BeginDrawing();

        ClearBackground(WHITE);

        partida->dibujarFondo();
        J1->dibujarPersonaje();
       

        EndDrawing();

    }
    
    // Descargamos la imagen para liberar recursos
    

    // Descargamos el sonido para liberar recursos
    //UnloadSound(jump);

    // Cerramos la ventana
    CloseWindow();

    return 0;
}

