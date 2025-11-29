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



class Plataforma
{
private:

	Texture2D plataforma = LoadTexture("Assets/plataforma.png");

	Vector2 posPlataforma = {SCREEN_WIDTH/2,SCREEN_HEIGHT/2};

	Color colPlataforma = WHITE;

	float escPlataforma = 0.10f;

	 
	//Total de la imagen a dibujar
	Rectangle sourcePlataforma = { 0,0, (float)plataforma.width, (float)plataforma.height};


	//Ubicacion y escalado de la imagen de la plafaorma
	Rectangle destPlataforma = { posPlataforma.x, posPlataforma.y, 100, 50 };
	
	//Centro de la plataforma
	Vector2 centroPlataforma = { (float)destPlataforma.width / 2, (float)destPlataforma.height / 2 };


	//Hitbox plataforma
	Rectangle hitPlataforma = { (destPlataforma.x - (destPlataforma.width/2)), (destPlataforma.y - (destPlataforma.height/2)),destPlataforma.width,destPlataforma.height};


public:

	Plataforma(float _x, float _y);
	~Plataforma();


	Rectangle GetRect();
	void dibujarHitboxP();
	void dibujarPlataforma();


};

