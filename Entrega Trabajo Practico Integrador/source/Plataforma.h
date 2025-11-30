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

	Vector2 posPlataforma;

	Color colPlataforma = WHITE;

	float escPlataforma = 0.10f;

	 


public:

	Plataforma(float _x, float _y);
	~Plataforma();


	Rectangle GetRect();
	void dibujarHitboxP();
	void dibujarPlataforma();


};

