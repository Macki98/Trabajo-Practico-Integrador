#pragma once

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include <cstdlib>
#include <time.h>
#include "Jugador.hpp"

class Game
{

public:

	Color fondolvl1 = WHITE;



	Texture2D fondo = LoadTexture("Assets/fondo castillo.png");

	float escFondo = 0.5f;

	Vector2 posicionCursor = GetMousePosition();

	// Contador de veces presionada la tecla M para mostrar/ocultar msj de sistema
	int contador = 1;


	Game();
	~Game();

	void mensajeSistma();

	void dibujarFondo();

	void nivel1();

};

