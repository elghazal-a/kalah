#ifndef AFFICHAGETEXT_H_INCLUDED
#define AFFICHAGETEXT_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "constantes.h"
#include "linkedList.h"

SDL_Surface* numberToSurface(int nombre, TTF_Font* police, SDL_Color color);

void blitSurfaceText(SDL_Surface* ecran, ListTrous* racine, SDL_Rect positionText[NOMBRE_TROUS], TTF_Font* police, SDL_Color color);

void calculerPosText(SDL_Rect positionText[NOMBRE_TROUS]);

#endif // AFFICHAGETEXT_H_INCLUDED
