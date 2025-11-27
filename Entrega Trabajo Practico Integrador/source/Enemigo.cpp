
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>
#include "Enemigo.h"

Enemigo::Enemigo()
{
}

Enemigo::~Enemigo()
{
}

void Enemigo::patrullaje(float _deltaTime)
{

	posEnemigo.x += velocidad.x * _deltaTime;
	

}

void Enemigo::dibujarEnemigo()
{
	DrawTextureEx(enemigo, posEnemigo, 0, escala, colEnemigo);
}





