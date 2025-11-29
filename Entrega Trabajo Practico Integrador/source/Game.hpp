#pragma once

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

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class Game
{

public:


	//Parametros fondo
	Texture2D fondo = LoadTexture("Assets/Fondo castillo.png");

	Rectangle pantallaFondo = { 0, 0, 1024, 768 };

	Color fondoCol = WHITE;

	//funciones del mouse
	Vector2 posicionCursor = GetMousePosition();

	// Contador de veces presionada la tecla M para mostrar/ocultar msj de sistema
	int contador = 1;


	Game();
	~Game();

	void mensajeSistma();

	void dibujarFondo();

	void nivel1();

};

