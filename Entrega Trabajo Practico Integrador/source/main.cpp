#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp" 
#include "Game.hpp"




int main(void)
{
    const int anchoPantalla = 1024;
    const int altoPantalla = 768;

    InitWindow(anchoPantalla, altoPantalla, "Nivel 1 - Alcanza la zona");

    SetTargetFPS(60);

    
    
    // Iniciamos el dispocitivo de audio
    InitAudioDevice();

    Game* partida = new Game();
  

    // Color del Boton
    Color colorBoton = BLACK;

    // Radio del Boton
    float r = 50;

    // Boton para cambiar de color el fondo
    Vector2 Boton = { 970, 50 };

    
  
    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose()) 
    {
        
        partida->nivel1();
    }
    
    // Descargamos la imagen para liberar recursos
    

    // Descargamos el sonido para liberar recursos
    //UnloadSound(jump);

    // Cerramos la ventana
    CloseWindow();

    return 0;
}

