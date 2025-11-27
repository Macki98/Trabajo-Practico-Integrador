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
	Vector2 posEnemigo = {1024 / 2, 768 / 2 };

	//Color del enemigo
	Color colEnemigo = WHITE;
	
	//Cantidad de textura que se visualiza
	Rectangle sourceEnemigo = { 0,0,(float)enemigo.width,(float)enemigo.height };

	//Rectangulo que funciona como hitbox del enemigo
	Rectangle hitEnemigo = { posEnemigo.x, posEnemigo.y, (float)enemigo.width/4,(float)enemigo.height/4 };

	//Origen (centro) del enemigo
	Vector2 origenEnemigo = { (float)enemigo.width / 2, (float)enemigo.height / 2 };

	//velocidad del enemigo
	Vector2 velocidad = { 500.0f, 50.0f };

	//escalado enemigo
	float escala = 0.15f;


public:

	Enemigo();
	~Enemigo();

	void dibujarEnemigo();

	void patrullaje(float _deltaTime);




};

