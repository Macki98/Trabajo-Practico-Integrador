
#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector, útil en modo Debug para detectar fugas de memoria
#endif

#include "raylib.h"
#include "raymath.h"
#include <cstdlib>
#include <time.h>
#include "Enemigo.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

Enemigo::Enemigo(float _x, float _y)
{
	posEnemigo.x = _x;
	posEnemigo.y = _y;

}

Enemigo::~Enemigo()
{
	UnloadTexture(enemigo);
}

void Enemigo::patrullaje(float _deltaTime)
{

	posEnemigo.x += velocidad.x * _deltaTime;
	//formula milagrosa para detectar colisiones con entorno
	if (posEnemigo.x + ((float)enemigo.width * escala) >= 1024) {
		posEnemigo.x = 1024 - ((float)enemigo.width*escala);
		velocidad.x *= -1;
	}
	

}

Rectangle Enemigo::GetRecE()
{
	return Rectangle{posEnemigo.x, posEnemigo.y, enemigo.width*escala, enemigo.height*escala};
}

void Enemigo::dibujarHitboxE()
{
	DrawRectangleLinesEx(GetRecE(), 5, RED);
}

void Enemigo::dibujarEnemigo()
{
	DrawTextureEx(enemigo, posEnemigo, 0, escala, colEnemigo);
}





