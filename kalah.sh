#!/bin/bash

cd ./Developpement/tpEnsias/Projet-C/kalah

gcc -o kalah main.c jeu.c jeu.h gererClics.c gererClics.h constantes.h linkedList.h linkedList.c affichageText.h affichageText.c save.h save.c messageBox.h messageBox.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lfmodex

