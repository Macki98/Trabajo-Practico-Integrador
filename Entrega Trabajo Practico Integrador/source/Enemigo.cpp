
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
	//formula para detectar colisiones con entorno
	if (posEnemigo.x + ((float)enemigo.width * escala) >= 1024) {
		posEnemigo.x = 1024 - ((float)enemigo.width*escala);
		velocidad.x *= -1;
	}
	

}

void Enemigo::dibujarEnemigo()
{
	DrawTextureEx(enemigo, posEnemigo, 0, escala, colEnemigo);
}





