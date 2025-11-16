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
    // Ventana de 1024x768 píxeles con un título personalizado
    //InitWindow(1024, 768, "¡Despierta, Mavis! - Leonel Tomas Mc Cormack");
    
    // Iniciamos el dispocitivo de audio
    InitAudioDevice();

    Game* partida = new Game();
  

    // Color del Boton
    Color colorBoton = BLACK;

    // Radio del Boton
    float r = 50;

    // Boton para cambiar de color el fondo
    Vector2 Boton = { 970, 50 };





    // Configuracion framerate
    SetTargetFPS(60);
    
    partida->nivel1();
    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    //while (!WindowShouldClose()) {}

    // Descargamos la imagen para liberar recursos
    //UnloadTexture(imagen);

    // Descargamos el sonido para liberar recursos
    //UnloadSound(jump);

    // Cerramos la ventana
    //CloseWindow();

    return 0;
}

