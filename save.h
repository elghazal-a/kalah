#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "linkedList.h"

void sauvegarder_jeu(ListTrous* game);

ListTrous* charger_jeu(ListTrous* game);


#endif // SAVE_H_INCLUDED
