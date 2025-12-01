
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
	UnloadTexture(plataforma);
}

Rectangle Plataforma::GetRect()
{
	return Rectangle{posPlataforma.x,posPlataforma.y, (float)plataforma.width*escPlataforma, (float)plataforma.height*escPlataforma};
}

void Plataforma::dibujarHitboxP()
{
	DrawRectangleLinesEx(GetRect(),5, RED);
}

void Plataforma::dibujarPlataforma()
{
	DrawTextureEx(plataforma,posPlataforma,0,escPlataforma,colPlataforma);
}
