
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

#include "Jugador.hpp"

#include "Enemigo.h"
#include "Plataforma.h"

#include "Game.hpp"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
Game::Game()
{


}

Game::~Game()
{
	UnloadTexture(fondo);

}

/*void Game::mensajeSistma()
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
*/

void Game::dibujarFondo() 
{
	DrawTexturePro(fondo, pantallaFondo, pantallaFondo, Vector2Zero(), 0, fondoCol);

}

void Game::iniciarJuego()
{

	gameOver = false;

}

void Game::actualizarJuego(float _deltaTime)
{
	J1->caminar(_deltaTime);
	J1->saltar(_deltaTime);
	J1->reiniciarPos();

	bola[0].patrullaje1(_deltaTime);
	bola[1].patrullaje2(_deltaTime);
	bola[2].patrullaje3(_deltaTime);
	bola[3].patrullaje4(_deltaTime);

	for (int i = 0; i < 6; i++)
	{
		bool colisiona = CheckCollisionRecs(J1->GetRecJ(), plataforma[i].GetRect()) && J1->GetVelocidad() > 0;
		J1->checkColisionesPlat(colisiona);
	}

	for (int i = 0; i < 4; i++) {
		if (J1->obtenerPosY() > SCREEN_HEIGHT || CheckCollisionRecs(J1->GetRecJ(), bola[i].GetRecE()))
		{
			gameOver = true;
		}
	}
}

void Game::dibujarJuego()
{
	dibujarFondo();
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

}

void Game::dibujarGameOver()
{
	DrawText("Perdiste", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 25, RED);
	DrawText("Presiona R para volver a intentar", SCREEN_WIDTH / 2, (SCREEN_HEIGHT/2) + 25, 25,RED);
	
	if (IsKeyPressed(KEY_R))
	{
		iniciarJuego();
		J1->reiniciarPos();
	}
}

