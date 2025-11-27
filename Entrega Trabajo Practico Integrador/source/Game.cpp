
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp"
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
		DrawText(TextFormat("Posicion del caballero: %.1f, %.1f"), 2, 70, 15, BLACK);
		DrawText(TextFormat("Posicion del mouse: X: %.2f Y: %.2f", posicionCursor.x, posicionCursor.y), 2, 50, 15, BLACK);
	}

}

void Game::dibujarFondo() 
{
	DrawTexturePro(fondo, pantallaFondo, pantallaFondo, Vector2Zero(), 0, fondoCol);

}

void Game::nivel1()
{

		//Todas las funciones por fuera del dibujo(Eventos, condicionales, etc)
		mensajeSistma();

	//}

}
