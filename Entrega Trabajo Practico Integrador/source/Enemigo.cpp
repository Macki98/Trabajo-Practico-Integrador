
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

void Enemigo::patrullaje1(float _deltaTime)
{
	posEnemigo.y += velocidad.y * _deltaTime;

	if (posEnemigo.y + ((float)enemigo.width * escala) <= 470 )
	{
		velocidad.y *= -1;
	}

	if (posEnemigo.y + ((float)enemigo.height * escala) >= SCREEN_HEIGHT)
	{
		posEnemigo.y = SCREEN_HEIGHT - ((float)enemigo.height * escala);
		velocidad.y *= -1;
	}

}

void Enemigo::patrullaje2(float _deltaTime)
{
	posEnemigo.y += velocidad.y * _deltaTime;
	
	if (posEnemigo.y + ((float)enemigo.width * escala) <= 150)
	{
		velocidad.y *= -1;
	}

	if (posEnemigo.y + ((float)enemigo.width * escala) >= 450)
	{
		velocidad.y *= -1;
	}
}

void Enemigo::patrullaje3(float _deltaTime)
{
	posEnemigo.x += velocidad.x * _deltaTime;

	if (posEnemigo.x + ((float)enemigo.width * escala) <= 500)
	{
		velocidad.x *= -1;
	}

	if (posEnemigo.x + ((float)enemigo.width * escala) >= 900)
	{
		velocidad.x *= -1;
	}

}

void Enemigo::patrullaje4(float _deltaTime)
{
	posEnemigo.x += velocidad.x * _deltaTime;

	if (posEnemigo.x + ((float)enemigo.width * escala) <= 800)
	{
		velocidad.x *= -1;
	}

	if (posEnemigo.x + ((float)enemigo.width * escala) >= SCREEN_WIDTH)
	{
		posEnemigo.x = SCREEN_WIDTH - ((float)enemigo.width * escala);
		velocidad.x *= -1;
	}

}

//funcion que devuelve el rectangulo que envuelve al enemigo y funciona como hitbox
Rectangle Enemigo::GetRecE()
{
	return Rectangle{posEnemigo.x, posEnemigo.y, enemigo.width*escala, enemigo.height*escala};
}

//funcion que permite ver la hitbox enemiga
void Enemigo::dibujarHitboxE()
{
	DrawRectangleLinesEx(GetRecE(), 5, RED);
}

void Enemigo::dibujarEnemigo()
{
	DrawTextureEx(enemigo, posEnemigo, 0, escala, colEnemigo);
	SetTextureFilter(enemigo, TEXTURE_FILTER_BILINEAR);
}





