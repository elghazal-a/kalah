#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <FMOD/fmod.h>

#include "constantes.h"
#include "gererClics.h"
#include "jeu.h"
#include "messageBox.h"




int main(int argc, char *argv[])
{
    int i = 0;

    SDL_Surface *ecran = NULL, *fond = NULL;
    SDL_Surface* buttons[NBR_G_BUTTON] = {NULL};
    SDL_Rect positionFond;
    SDL_Rect positionButtons[NBR_G_BUTTON];
    SDL_Event event;

    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_WM_SetIcon(IMG_Load("./images/icone.png"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("KaLah", NULL);

    fond = IMG_Load("./images/fond.png");
    positionFond.x = 0;
    positionFond.y = 0;

    buttons[0] = IMG_Load("./images/bJouerNormal.png");
    buttons[1] = IMG_Load("./images/bChargerNormal.png");
    buttons[2] = IMG_Load("./images/bOptionsNormal.png");
    buttons[3] = IMG_Load("./images/bQuitterNormal.png");


    for (i = 0; i < NBR_G_BUTTON; i++)
    {
        positionButtons[i].x = BUTTON_MAIN_START_X;
        positionButtons[i].y = BUTTON_MAIN_START_Y + i * (BUTTON_G_HEIGHT + AERATION_BUT_G);
    }

    FMOD_SYSTEM *system;
    FMOD_SOUND *click;

    /* Création et initialisation d'un objet système */
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL);

    /* Chargement du son et vérification du chargement */
    FMOD_System_CreateSound(system, "./sounds/click.wav", FMOD_CREATESAMPLE, 0, &click);


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:

                        switch(whatGButtonPushed(event))
                        {
                            case B_JOUER:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, click, 0, NULL);
                                jouer(ecran, click, system,NEW_GAME);
                                break;
                            case B_CHARGER:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, click, 0, NULL);
                                jouer(ecran, click, system,LOAD_GAME);
                                break;
                            case B_OPTIONS:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, click, 0, NULL);
                                //afficherMsg(ecran);
                                break;
                            case B_QUITTER:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, click, 0, NULL);
                                continuer = 0;
                                break;
                            default:
                                break;
                        }

                        break;
                    default:
                        break;
                }
                break;

                default:
                    break;
        }

        // Effacement de l'écran
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(fond, NULL, ecran, &positionFond);
        for (i = 0; i < NBR_G_BUTTON; i++)
        {
        	SDL_BlitSurface(buttons[i], NULL, ecran, &positionButtons[i]);
        }
        SDL_Flip(ecran);
    }

    TTF_Quit();

    SDL_FreeSurface(fond);
    SDL_Quit();

    FMOD_Sound_Release(click);
    FMOD_System_Close(system);
    FMOD_System_Release(system);

    return EXIT_SUCCESS;
}
