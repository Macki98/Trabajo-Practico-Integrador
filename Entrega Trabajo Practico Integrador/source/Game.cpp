
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>

#include "Game.hpp"

Game::Game()
{

}

Game::~Game()
{
}

void Game::mensajeSistma()
{
	
	// Buffer de teclado que muestra y oculta mensaje del sistema
	if (IsKeyPressed(KEY_M)) {
		contador++;
	}
	// Mensaje de sistema
	if (contador % 2 == 0) {
		DrawText("Caballero", 2, 0, 25, BLACK);
		DrawText("Llega al final para ganar", 2, 25, 15, BLACK);
		DrawText(TextFormat("Posicion del caballero: %.1f, %.1f", J1->obtenerPos()), 2, 70, 15, BLACK);
		DrawText(TextFormat("Posicion del mouse: X: %.2f Y: %.2f", posicionCursor.x, posicionCursor.y), 2, 50, 15, BLACK);
	}
}



void Game::nivel1()
{
	
	InitWindow(ancho, alto, "Nivel 1 - Alcanza la zona");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{

	//Todas las funciones por fuera del dibujo(Eventos, condicionales, etc)
		
		if (IsKeyPressed(KEY_ESCAPE))
		{
			CloseWindow();
		}

		mensajeSistma();

		//Funciones para el jugador
		J1->caminar();
		J1->saltar();

		J1->obtenerPos();

		//Iniciamos el dibujo
		BeginDrawing();

		ClearBackground(fondolvl1);

		mensajeSistma();

		

		EndDrawing();

	}

}
