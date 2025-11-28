#pragma once

#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>

class Plataforma
{
private:

	Texture2D plataforma = LoadTexture("Assets/plataforma.png");

	Vector2 posPlataforma = Vector2Zero();

	Color colPlataforma = WHITE;


	Rectangle hitPlataforma = { 0,0,(float)plataforma.width,(float)plataforma.height };

	float escPlataforma = 0.15f;


public:

	Plataforma();
	~Plataforma();

	void dibujarPlataforma();


};

