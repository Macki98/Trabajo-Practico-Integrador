
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

void Game::nivel1()
{
	
	InitWindow(ancho, alto, "Nivel 1 - Alcanza la zona");


		J1->caminar();
		J1->saltar();

}
