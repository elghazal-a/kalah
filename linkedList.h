#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"

typedef struct ListTrous ListTrous;

struct ListTrous
{
    int pieces;
    int JoueurID;
    TypeTrou typeTrou;
    struct ListTrous* prev;
    struct ListTrous* next;
};

ListTrous* createList();

void addAfter(ListTrous* element, int pieces, TypeTrou typeTrou, int joueurID);

void ajouterEnTete(ListTrous* racine, int pieces, TypeTrou typeTrou, int joueurID);

void initialiserList(ListTrous* racine, int initialPieces);

int howManyPiecesIn(ListTrous* racine, int position);

ListTrous* searchByPosTrou(ListTrous* racine, int posTrou);

int distributePieces(ListTrous* racine, ListTrous* from, int positionFrom, int nbrPieces);

ListTrous* changeTurnPlaying(ListTrous* racine);

int jeuFini(ListTrous* racine);

int whoIsWinner(ListTrous* racine);



#endif // LINKEDLIST_INCLUDED
