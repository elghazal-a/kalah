#ifndef GENERALFUNCTIONS_H_INCLUDED
#define GENERALFUNCTIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "constantes.h"

int whatGButtonPushed(SDL_Event event);

int whatPButtonPushed(SDL_Event event, int* buttonPlayPushed);

#endif // GENERALFUNCTIONS_H_INCLUDED
