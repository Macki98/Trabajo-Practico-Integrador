#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp" 
#include "Enemigo.h"

#include "Plataforma.h"

#include "Game.hpp"

#include "raymath.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

int main(void)
{


    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "Nivel 1 - Alcanza la zona");

    SetTargetFPS(60);

    // Iniciamos el dispocitivo de audio
    InitAudioDevice();

    Game* partida = new Game();
    Jugador* J1 = new Jugador(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    Enemigo* bola = new Enemigo(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    Plataforma* plataforma = new Plataforma(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

  

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
        bola->patrullaje(deltaTime);

        BeginDrawing();

        ClearBackground(WHITE);

        partida->dibujarFondo();

        plataforma->dibujarPlataforma();
        plataforma->dibujarHitboxP();

        bola->dibujarEnemigo();
        bola->dibujarHitboxE();


        J1->dibujarPersonaje();
        J1->dibujarHitBoxJ();
       

        EndDrawing();

    }
    
    // Descargamos la imagen para liberar recursos
    

    // Descargamos el sonido para liberar recursos
    //UnloadSound(jump);

    // Cerramos la ventana
    CloseWindow();

    return 0;
}

