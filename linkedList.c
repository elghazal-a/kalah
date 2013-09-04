#include "linkedList.h"


ListTrous* createList()
{
    ListTrous* racine = malloc ( sizeof *racine );
    if ( racine != NULL )
    {
        racine->pieces = -1;
        racine->prev = racine;
        racine->next = racine;
    }
    return racine;
}

void addAfter(ListTrous* element, int pieces, TypeTrou typeTrou, int joueurID)
{
    ListTrous* nvElmt = malloc ( sizeof *nvElmt );
    if ( nvElmt != NULL )
    {
        nvElmt->pieces = pieces;
        nvElmt->typeTrou = typeTrou;
        nvElmt->JoueurID = joueurID;

        nvElmt->prev = element;
        nvElmt->next = element->next;

        element->next->prev = nvElmt;
        element->next = nvElmt;
    }
}

void ajouterEnTete(ListTrous* racine, int pieces, TypeTrou typeTrou, int joueurID)
{
    addAfter(racine, pieces, typeTrou, joueurID);
}

void initialiserList(ListTrous* racine, int initialPieces)
{
    int i;
    TypeTrou quelTrou = TROU_KALAH;

    ajouterEnTete(racine, 0, quelTrou, 2);

    quelTrou = TROU_NORMAL;
    for (i = 1; i <= 6; i++)
    {
    	ajouterEnTete(racine, initialPieces, TROU_KALAH, 2);
    }

    quelTrou = TROU_KALAH;
    ajouterEnTete(racine, 0, quelTrou, 1);

    quelTrou = TROU_NORMAL;
    for (i = 1; i <= 6; i++)
    {
    	ajouterEnTete(racine, initialPieces, TROU_KALAH, 1);
    }


}

int howManyPiecesIn(ListTrous* racine, int position)
{
    int i;
    ListTrous* tmp = racine->next;

    for (i = 1; i < position; i++)
    {
        tmp = tmp->next;
    }

    return tmp->pieces;
}

ListTrous* searchByPosTrou(ListTrous* racine, int posTrou) //le 1er trou est de position 1
{
    int i;
    ListTrous* tmp = racine->next;

    for (i = 1; i < posTrou; i++)
    {
        tmp = tmp->next;
    }

    return tmp;
}

int distributePieces(ListTrous* racine, ListTrous* from, int positionFrom,int nbrPieces)
{
    ListTrous* tmp = from;
    int numTrou = positionFrom;

    while (nbrPieces > 0)
    {
    	if (tmp->next == racine)
    	{
    		tmp = tmp->next->next;
    		numTrou = 0;
    	}
    	else
    	{
    	    tmp->pieces++;
    	    tmp = tmp->next;
    		nbrPieces--;
    		numTrou++;
    	}
    }
    return numTrou;
}

ListTrous* changeTurnPlaying(ListTrous* racine)
{
    ListTrous* trou2emeJoueur = searchByPosTrou(racine, 8); // 8 est la position du 1er trou de l'adversaire

    racine->prev->next = racine->next;
    racine->next->prev = racine->prev;

    racine->next = trou2emeJoueur;
    racine->prev = trou2emeJoueur->prev;
    trou2emeJoueur->prev->next = racine;
    trou2emeJoueur->prev = racine;

    return racine;

}


int jeuFini(ListTrous* racine)
{
    ListTrous* MonKalah = searchByPosTrou(racine, 7);

    if(MonKalah->pieces > (INITIAL_PIECES*12)/2)
        return 1;

    ListTrous* tmp = racine->next;

    int i;
    for(i = 1; i <= 6; i++)
    {
        if(tmp->pieces > 0) return 0;
        tmp = tmp->next;
    }
    //l'autre joueur recupere ses propres pieces

    ListTrous* kalahAutreJoueur = searchByPosTrou(racine, 14); // 14 est la position de son kalah
    int piecesAajoute = 0;

    tmp = searchByPosTrou(racine, 8);
    for(i = 1; i <= 6; i++)
    {
        piecesAajoute += tmp->pieces;
        tmp = tmp->next;
    }
    kalahAutreJoueur->pieces += piecesAajoute;
    return 1;

}

int whoIsWinner(ListTrous* racine)
{
    ListTrous* kalah1 = searchByPosTrou(racine, 7);
    ListTrous* kalah2 = searchByPosTrou(racine, 14);

    if (kalah1->pieces > kalah2->pieces)
    {
        return kalah1->JoueurID;
    }
    else if (kalah1->pieces < kalah2->pieces)
    {
        return kalah2->JoueurID;
    }
    else
    {
    	//egalite
    	return 0;
    }
}










