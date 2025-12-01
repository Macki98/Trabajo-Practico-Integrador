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

	Jugador* J1 = new Jugador(30, 600);

	Enemigo* bola = new Enemigo[4]{ Enemigo(130, 500),
								   Enemigo(SCREEN_WIDTH / 3, 250),
								   Enemigo((SCREEN_WIDTH / 3) * 2, 300),
								   Enemigo(850,90)
	};

	Plataforma* plataforma = new Plataforma[6]{ Plataforma(20,700),
											  Plataforma(200,550),
											  Plataforma(100,350),
											  Plataforma(420,230),
											  Plataforma(640,500),
											  Plataforma(910,315)
	};

	//Parametros fondo
	Texture2D fondo = LoadTexture("Assets/Fondo castillo.png");

	Rectangle pantallaFondo = { 0, 0, 1024, 768 };

	Color fondoCol = WHITE;

	//funciones del mouse
	Vector2 posicionCursor = GetMousePosition();

	// Contador de veces presionada la tecla M para mostrar/ocultar msj de sistema
	//int contador = 1;

	bool gameOver = false;
	

	Game();
	~Game();


	void dibujarFondo();

	void iniciarJuego();

	void actualizarJuego(float _deltaTime);

	void dibujarJuego();

	void dibujarGameOver();


	

};

