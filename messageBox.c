#include "messageBox.h"


void afficherMsg(SDL_Surface* ecran, char* textAafficher)
{
    int continuer = 1;

    SDL_Event event;

    SDL_Surface *fondMsgBox = NULL;

    SDL_Rect positionFondMsgBox, positionText;


    TTF_Font *police = NULL;

    SDL_Color color = {0, 0, 0};
    police = TTF_OpenFont("./fonts/arial.ttf", 25);
    SDL_Surface* surfTexte = TTF_RenderText_Blended(police, textAafficher, color);

    fondMsgBox = IMG_Load("./images/fondMsgBox.png");

    positionFondMsgBox.x = ( LARGEUR_FENETRE - MESSAGE_BOX_WIDTH )/2;
    positionFondMsgBox.y = ( HAUTEUR_FENETRE - MESSAGE_BOX_HEIGHT )/2;

    positionText.x = positionFondMsgBox.x + 100;
    positionText.y = positionFondMsgBox.y + 150;

    //Blitter
    SDL_BlitSurface(fondMsgBox, NULL, ecran, &positionFondMsgBox);
    SDL_BlitSurface(surfTexte, NULL, ecran, &positionText);

    SDL_Flip(ecran);

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
                    case SDLK_RETURN:
                        continuer = 0;
                        break;
                    default:
                        break;
                }
                break;
            default:
            break;

        }


    }

    SDL_FreeSurface(fondMsgBox);

}

