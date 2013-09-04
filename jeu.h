#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <FMOD/fmod.h>

#include "constantes.h"
#include "gererClics.h"
#include "linkedList.h"
#include "affichageText.h"
#include "save.h"
#include "messageBox.h"

void jouer(SDL_Surface* ecran, FMOD_SOUND* soundClick, FMOD_SYSTEM* system,TypeJeu typeJeu);

void chargerTableImages(SDL_Surface** fond, SDL_Surface* trous[], SDL_Surface* trousKalah[], SDL_Surface* buttonJouer[]);

void remplirPosition(SDL_Rect* positionFond, SDL_Rect* positionTrous, SDL_Rect* positionTrousKalah, SDL_Rect* positionButtonJouer);

#endif // JEU_H_INCLUDED
