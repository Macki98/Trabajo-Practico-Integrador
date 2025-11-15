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

	Jugador* J1 = new Jugador(deltaTime);
	float deltaTime = GetFrameTime();

	// Contador de veces presionada la tecla M para mostrar/ocultar msj de sistema
	int contador = -1;


	Game();
	~Game();

	void nivel1();

};

