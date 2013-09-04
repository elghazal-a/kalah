#include "save.h"


void sauvegarder_jeu(ListTrous* game)
{
    FILE *flot;
    ListTrous* actuel = game->next;
    int i;
    int tab[NOMBRE_TROUS];
    flot = fopen("save", "wb");

    for(i=1; i <= NOMBRE_TROUS ;i++)
    {
        tab[i-1]=actuel->pieces;
        actuel=actuel->next;
    }


    for(i=0; i < NOMBRE_TROUS ;i++)
    fwrite (&tab[i], sizeof(tab[i]),1, flot);

    fclose(flot);
}



ListTrous* charger_jeu(ListTrous* game)
{
    printf("open\n");
    FILE *flot;
    if(game == NULL)
    game = createList();

    initialiserList(game, INITIAL_PIECES);
    ListTrous* actuel = game->next;
    int i;

    flot =fopen("save", "rb");

    for(i=1; i <= NOMBRE_TROUS; i++)
    {
        fread (&actuel->pieces, sizeof( actuel->pieces),1, flot);
        actuel=actuel->next;
    }
    return game;
}



