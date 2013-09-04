#ifndef MESSAGEBOX_H_INCLUDED
#define MESSAGEBOX_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "constantes.h"


void afficherMsg(SDL_Surface* ecran, char* textAafficher);

#endif // MESSAGEBOX_H_INCLUDED
