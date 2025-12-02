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

    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT, "Leonel Mc Cormack - TP Integrador Nº1");
    // Iniciamos el dispocitivo de audio
    InitAudioDevice();

    Game* partida = new Game();


    partida->iniciarJuego();
   
    SetTargetFPS(60);


    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose()) 
    {
        float deltaTime = GetFrameTime();

        partida->actualizarJuego(deltaTime);

        BeginDrawing();

        ClearBackground(WHITE);

        if (partida->estaEnMenu)
        {
            partida->dibujarMenu();

        }
       
        else if (partida->gameOver)
        {
            partida->dibujarGameOver();
        }
        else if (partida->win)
        {
            partida->dibujarWin();
        }

        else
        {
            partida->dibujarJuego();
        
        }


        EndDrawing();
    
    }

    // Cerramos la ventana
    CloseWindow();

    return 0;
}

