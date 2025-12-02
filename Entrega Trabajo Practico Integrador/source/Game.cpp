
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
	UnloadTexture(menu);
	UnloadTexture(winFlag);

}


void Game::dibujarMenu()
{
	DrawTexturePro(menu, menuInicio, menuInicio, Vector2Zero(), 0, menuCol);
	SetTextureFilter(menu, TEXTURE_FILTER_BILINEAR);

	DrawRectangle(iniciar.x,iniciar.y,iniciar.width,iniciar.height, Fade(DARKBROWN, 0.5f));
	DrawRectangle(tutorial.x,tutorial.y,tutorial.width,tutorial.height, Fade(DARKBROWN, 0.5f));
	

	DrawText("INICIAR", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 75, 50, BLACK);
	DrawText("Llega hasta el cofre de los tesoros.",255 , SCREEN_HEIGHT / 2 + 75, 25, BLACK);
	DrawText("Utiliza las flechas direccionales para moverte y la barra espaciadora para saltar.",5, SCREEN_HEIGHT / 2 + 150, 25, BLACK);
	DrawText("Mucha suerte!",400, SCREEN_HEIGHT / 2 + 225, 25, BLACK);
	
}

void Game::dibujarFondo()
{
	DrawTexturePro(fondo, pantallaFondo, pantallaFondo, Vector2Zero(), 0, fondoCol);
	SetTextureFilter(fondo, TEXTURE_FILTER_BILINEAR);

}


void Game::iniciarJuego()
{

	estaEnMenu = true;

	gameOver = false;
	win = false;

	

}

void Game::actualizarJuego(float _deltaTime)
{


	cerrarMenu();

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

	if (CheckCollisionRecs(J1->GetRecJ(), getRectFlag()))
	{
		win = true;
	}
}

void Game::dibujarJuego()
{
	dibujarFondo();
	J1->dibujarPos();

	for (int i = 0; i < 6; i++)
	{	
		//descomentar para visualizar hitbox
		//plataforma[i].dibujarHitboxP();
		plataforma[i].dibujarPlataforma();
	}


	for (int i = 0; i < 4; i++)
	{
		bola[i].dibujarEnemigo();
		//descomentar para visualizar hitxbox
		//bola[i].dibujarHitboxE();
	}

	dibujarFlag();

	J1->dibujarPersonaje();
	//descomentar para visualizar hitbox
	//J1->dibujarHitboxJug();

}

void Game::dibujarGameOver()
{
	DrawText("Perdiste", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 25, RED);
	DrawText("Presiona R para volver a intentar", SCREEN_WIDTH / 2 - 100, (SCREEN_HEIGHT/2) + 25, 25,RED);
	
	if (IsKeyPressed(KEY_R))
	{
		iniciarJuego();
		J1->reiniciarPos();
	}
}

void Game::dibujarFlag()
{
	DrawTextureEx(winFlag, posFlag, 0, escFlag, flagCol);
	SetTextureFilter(winFlag, TEXTURE_FILTER_BILINEAR);
}

Rectangle Game::getRectFlag()
{
	return Rectangle{posFlag.x,posFlag.y, (float)winFlag.width * escFlag, (float)winFlag.height * escFlag};
}

void Game::dibujarWin()
{

	DrawText("GANASTE!", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 25, RED);
	DrawText("Presiona R para volver a iniciar", SCREEN_WIDTH / 2 - 100, (SCREEN_HEIGHT / 2) + 25, 25, RED);
	
	if (IsKeyPressed(KEY_R))
	{
		iniciarJuego();
		J1->reiniciarPos();
	}
}

void Game::cerrarMenu()
{

	if (CheckCollisionPointRec(posicionCursor, iniciar) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		estaEnMenu = false;

	}
}



