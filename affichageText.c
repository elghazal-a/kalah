#include "affichageText.h"


SDL_Surface* numberToSurface(int nombre, TTF_Font* police, SDL_Color color)
{
    char chaine[3] = "";

    sprintf(chaine, "%d", nombre);

    return TTF_RenderText_Solid(police, chaine, color);
}

void blitSurfaceText(SDL_Surface* ecran, ListTrous* racine, SDL_Rect positionText[NOMBRE_TROUS], TTF_Font* police, SDL_Color color)
{
    int i = 0;
    ListTrous* tmp = racine->next;

    while(tmp != racine)
    {
        SDL_BlitSurface(numberToSurface(tmp->pieces, police, color), NULL, ecran, &positionText[i]);
        tmp = tmp->next;
        i++;
    }
}

void calculerPosText(SDL_Rect positionText[NOMBRE_TROUS])
{
    int i;

    for (i = 0; i < 6; i++)
    {
        positionText[i].x = TEXT_TROU_J1_START_X + i*TEXT_AERATION;
        positionText[i].y = TEXT_TROU_J1_START_Y;
    }

    positionText[i].x = TEXT_KALAH_J1_X;
    positionText[i].y = TEXT_TROU_J1_START_Y;

    for (i = 7; i < 13; i++)
    {
        positionText[i].x = TEXT_TROU_J2_START_X - (i-7)*TEXT_AERATION;
        positionText[i].y = TEXT_TROU_J2_START_Y;
    }

    positionText[i].x = TEXT_KALAH_J2_X;
    positionText[i].y = TEXT_TROU_J2_START_Y;

}
