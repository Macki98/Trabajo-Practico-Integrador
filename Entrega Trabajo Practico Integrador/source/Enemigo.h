#pragma once

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class Enemigo
{
private:

	//Textura del enemigo
	Texture2D enemigo = LoadTexture("Assets/Obstaculo 1.png");

	//posicion del enemigo
	Vector2 posEnemigo;

	//Color del enemigo
	Color colEnemigo = WHITE;

	//velocidad del enemigo
	Vector2 velocidad = { 150.0f, 150.0f };

	//escalado enemigo
	float escala = 0.15f;


	//Rectangulo que funciona como hitbox del enemigo
	Rectangle hitEnemigo = { posEnemigo.x,posEnemigo.y, (float)enemigo.width*escala,(float)enemigo.height*escala };


public:

	Enemigo(float _x, float _y);
	~Enemigo();

	Rectangle GetRecE();
	void dibujarHitboxE();
	void dibujarEnemigo();
	
	

	void patrullaje1(float _deltaTime);
	void patrullaje2(float _deltaTime);
	void patrullaje3(float _deltaTime);
	void patrullaje4(float _deltaTime);



};

