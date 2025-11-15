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
    InitWindow(1024, 768, "¡Despierta, Mavis! - Leonel Tomas Mc Cormack");
    
    // Iniciamos el dispocitivo de audio
    InitAudioDevice();

    Game* partida = new Game();


    // Cargamos el sonido para el salto
    Sound jump = LoadSound("Assets/jump.wav");


    
    // Cargamos la textura del cursor, aplicamos filtro y ocultamos el cursor del sistema
    Texture2D cursor = LoadTexture("Assets/crosshair.png");
    SetTextureFilter(cursor, TEXTURE_FILTER_BILINEAR);
    HideCursor();

    // Aplicamos el origen del cursor para que responda a la posicion actual del mouse
    Rectangle cursorRectangle = { 0,0, cursor.width, cursor.height};
    Vector2 cursorCenter = { cursor.width / 2, cursor.height / 2 };


    // Color del fondo
    Color fondo = RAYWHITE;

    // Color del Boton
    Color colorBoton = BLACK;

    // Radio del Boton
    float r = 50;

    // Boton para cambiar de color el fondo
    Vector2 Boton = { 970, 50 };





    // Configuracion framerate
    SetTargetFPS(60);
 
    // Bucle principal del juego (se repite hasta que se cierre la ventana)
    while (!WindowShouldClose())
    {

        partida->nivel1();

        // Buffer de teclado que muestra y oculta mensaje del sistema
        if (IsKeyPressed(KEY_M)) {
            contador++;
        }

        // Captura de eventos del mouse
            
            // Devuelve la posicion del mouse
        Vector2 windowPosition = GetMousePosition();
            // Booleano que chequea la posicion del mouse con la del boton
        bool collision = CheckCollisionPointCircle(windowPosition, Boton, r);
            // Funcion que permite cambiar el color del fondo
        if (collision && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            fondo.r = GetRandomValue(0, 255);
            fondo.g = GetRandomValue(0, 255);
            fondo.b = GetRandomValue(0, 255);
            
        }
     
        // Iniciamos la etapa de dibujo
        BeginDrawing();

        // Limpiamos la pantalla 
        ClearBackground(fondo);
        
        // Mensaje de sistema
        if (contador % 2 == 0) {
            DrawText("Caballero", 2, 0, 25, BLACK);
            DrawText("Haz click izquierdo sobre el circulo negro para cambiar el color del fondo", 2, 25, 15, BLACK);
            //DrawText(TextFormat("Posicion del caballero: %.1f, %.1f", posJugador.x, posJugador.y), 2, 70, 15, BLACK);
            DrawText(TextFormat("Posicion del mouse: X: %.2f Y: %.2f", windowPosition.x, windowPosition.y), 2, 50, 15, BLACK);
        }

        // Dibujamos la imagen para el caballero con sus parametros personalizados
        J1->dibujarPersonaje();

        // Dibujamos el boton para cambiar el color del fondo
        DrawCircle(Boton.x, Boton.y, r, colorBoton);

        // Dibujamos el cursor con la posicion del mouse
        DrawTexturePro(cursor, cursorRectangle, {windowPosition.x, windowPosition.y, cursorRectangle.width, cursorRectangle.height}, cursorCenter, 0, WHITE);


        // Finalizamos el dibujo
        EndDrawing();
    }

    // Descargamos la imagen para liberar recursos
    //UnloadTexture(imagen);

    // Descargamos el sonido para liberar recursos
    UnloadSound(jump);

    // Cerramos la ventana
    CloseWindow();

    return 0;
}

