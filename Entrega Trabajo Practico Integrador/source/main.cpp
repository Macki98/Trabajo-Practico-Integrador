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
    // Iniciamos el dispocitivo de audio
    InitAudioDevice();

    Game* partida = new Game();
    partida->iniciarJuego();
    
    SetTargetFPS(60);



    /*
    Jugador* J1 = new Jugador(30, 600);

    Enemigo* bola = new Enemigo[4]{Enemigo(130, 500),
                                   Enemigo(SCREEN_WIDTH / 3, 250),
                                   Enemigo((SCREEN_WIDTH / 3) * 2, 300),
                                   Enemigo(850,90)};

    Plataforma* plataforma = new Plataforma[6]{Plataforma(20,700),
                                              Plataforma(200,550), 
                                              Plataforma(100,350), 
                                              Plataforma(420,230), 
                                              Plataforma(640,500),
                                              Plataforma(910,315)};

    */
    

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
        Vector2 windowPosition = GetMousePosition();
        
        partida->actualizarJuego(deltaTime);

        /*
        for (int i = 0; i < 3; i++) {
            bool gameOver = (J1->obtenerPosY() >= SCREEN_HEIGHT) || CheckCollisionRecs(J1->GetRecJ(), bola[i].GetRecE());
            
        }

        J1->caminar(deltaTime);
        J1->saltar(deltaTime);
        J1->reiniciarPos();

        for (int i = 0; i < 6; i++)
        {
            bool colisiona = CheckCollisionRecs(J1->GetRecJ(), plataforma[i].GetRect()) && J1->GetVelocidad()>0;
            J1->checkColisionesPlat(colisiona);
        }

        for (int i = 0; i < 3; i++)
        {
            bool gameOver = CheckCollisionRecs(J1->GetRecJ(), bola[i].GetRecE());
            
        }

        bola[0].patrullaje1(deltaTime);
        bola[1].patrullaje2(deltaTime);
        bola[2].patrullaje3(deltaTime);
        bola[3].patrullaje4(deltaTime);

        */

        BeginDrawing();

        ClearBackground(WHITE);


        //partida->dibujarFondo();

        if (partida->gameOver)
        {
            partida->dibujarGameOver();
        }
        else {
            partida->dibujarJuego();
        }
        
        /*
        J1->dibujarPos();
        
        for (int i = 0; i < 6; i++)
        {
            plataforma[i].dibujarHitboxP();
            plataforma[i].dibujarPlataforma();
        }

        for (int i = 0; i < 4; i++)
        {
            bola[i].dibujarEnemigo();
            bola[i].dibujarHitboxE();
        }

        J1->dibujarPersonaje();
        */

        EndDrawing();
    }
    
    // Descargamos la imagen para liberar recursos
    

    // Descargamos el sonido para liberar recursos
    //UnloadSound(jump);

    // Cerramos la ventana
    CloseWindow();

    return 0;
}

