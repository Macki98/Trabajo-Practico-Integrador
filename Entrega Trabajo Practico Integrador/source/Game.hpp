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

	Rectangle pantallaFondo = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	Color fondoCol = WHITE;

	//parametros menu de inicio
	Texture2D menu = LoadTexture("Assets/menu de inicio.png");

	Rectangle menuInicio = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };

	Color menuCol = WHITE;


	//parametros bandera de victoria
	Texture2D winFlag = LoadTexture("Assets/goal.png");

	Color flagCol = WHITE;

	Vector2 posFlag = {930,258};

	float escFlag = 0.1f;


	//Botones de menu de incio
	Rectangle iniciar = { SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100, 200, 100 };
	Rectangle tutorial = { 5, SCREEN_HEIGHT / 2 + 50, 1015, 200 };
	Rectangle salir = { SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2 + 270, 200, 100 };
	
	//funciones del mouse
	Vector2 posicionCursor = GetMousePosition();

	//condicionales para checkear estado de juego (victoria y derrota)
	bool gameOver = false;
	
	bool win = false;

	bool estaEnMenu = true;

	


	Game();
	~Game();


	void dibujarMenu();

	void dibujarFondo();

	

	void iniciarJuego();

	void actualizarJuego(float _deltaTime);

	void dibujarJuego();

	void dibujarGameOver();

	void dibujarFlag();

	Rectangle getRectFlag();

	void dibujarWin();
	
	void cerrarMenu();
};

