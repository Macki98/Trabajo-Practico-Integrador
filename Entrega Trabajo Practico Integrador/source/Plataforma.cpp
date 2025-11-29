
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>
#include "Plataforma.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

Plataforma::Plataforma(float _x, float _y)
{
	posPlataforma.x = _x;
	posPlataforma.y = _y;

}

Plataforma::~Plataforma()
{
}

Rectangle Plataforma::GetRect()
{
	return Rectangle{hitPlataforma.x, hitPlataforma.y, hitPlataforma.width, hitPlataforma.height};
}

void Plataforma::dibujarHitboxP()
{
	DrawRectangleLinesEx(GetRect(),5, RED);
}

void Plataforma::dibujarPlataforma()
{
	DrawTexturePro(plataforma,sourcePlataforma,destPlataforma,centroPlataforma,0,WHITE);
}
