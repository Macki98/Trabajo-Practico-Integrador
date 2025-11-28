#include "Plataforma.h"

Plataforma::Plataforma()
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::dibujarPlataforma()
{
	DrawTextureEx(plataforma, posPlataforma, 0, escPlataforma, colPlataforma);
}
