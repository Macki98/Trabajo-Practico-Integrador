#pragma once

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

class Enemigo
{
private:

	//Textura del enemigo
	Texture2D enemigo = LoadTexture("Assets/Obstaculo 1.png");

	//posicion del enemigo
	Vector2 posEnemigo;

	//Color del enemigo
	Color colEnemigo = WHITE;


	//Rectangulo que funciona como hitbox del enemigo
	Rectangle hitEnemigo = { posEnemigo.x, posEnemigo.y, (float)enemigo.width / escala,(float)enemigo.height / escala};

	//Origen (centro) del enemigo
	Vector2 origenEnemigo = { (float)enemigo.width / 2, (float)enemigo.height / 2 };

	//velocidad del enemigo
	Vector2 velocidad = { 150.0f, 50.0f };

	//escalado enemigo
	float escala = 0.15f;


public:

	Enemigo(float _x, float _y);
	~Enemigo();

	void dibujarEnemigo();

	void patrullaje(float _deltaTime);




};

