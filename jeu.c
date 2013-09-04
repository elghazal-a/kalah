#include "jeu.h"

void jouer(SDL_Surface* ecran, FMOD_SOUND* soundClick, FMOD_SYSTEM* system, TypeJeu typeJeu)
{
    freopen ("debug.txt","a+",stdout);

    int continuer = 1;
    int buttonPlayPushed = -1, buttonNextTurnState = NEXT_TURN_GRIS;
    ListTrous* actualTrou = NULL;
    //--------------------
    SDL_Event event;

    SDL_Surface *fond = NULL, *buttNextTurnGris = NULL, *buttNextTurn = NULL;

    SDL_Rect positionFond;
    SDL_Rect positionButtNextTurn;
    SDL_Rect positionTexts[NOMBRE_TROUS];

    calculerPosText(positionTexts);

    TTF_Font *police = NULL;

    SDL_Color colorNbrPieces = {0, 0, 0};
    police = TTF_OpenFont("./fonts/arial.ttf", 20);

    fond = IMG_Load("./images/table.png");
    buttNextTurnGris = IMG_Load("./images/nextTurnGris.png");
    buttNextTurn = IMG_Load("./images/nextTurn.png");

    positionFond.x = 0;
    positionFond.y = 0;

    positionButtNextTurn.x = B_NEXT_TURN_START_X;
    positionButtNextTurn.y = B_NEXT_TURN_START_Y;

    // initialiser la table de jeu
    ListTrous* racine = NULL;

    if (typeJeu == NEW_GAME)
    {
        racine = createList();
        initialiserList(racine, INITIAL_PIECES);
    }
    else
    {
    	racine = charger_jeu(racine);
    }

    FMOD_SOUND *bonus;
    FMOD_SOUND *alert;
    FMOD_SOUND *app;

    /* Chargement du son et vérification du chargement */
    FMOD_System_CreateSound(system, "./sounds/bonus.wav", FMOD_CREATESAMPLE, 0, &bonus);
    FMOD_System_CreateSound(system, "./sounds/alert.aiff", FMOD_CREATESAMPLE, 0, &alert);
    FMOD_System_CreateSound(system, "./sounds/app.wav", FMOD_CREATESAMPLE, 0, &app);



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
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        switch(whatPButtonPushed(event, &buttonPlayPushed))
                        {
                            case B_UNDO:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, soundClick, 0, NULL);

                                break;
                            case B_INFO:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, soundClick, 0, NULL);

                                break;
                            case B_SETTINGS:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, soundClick, 0, NULL);
                                //options(ecran);
                                break;
                            case B_SAVE:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, soundClick, 0, NULL);
                                sauvegarder_jeu(racine);

                                break;
                            case B_QUIT:
                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, soundClick, 0, NULL);
                                continuer = 0;
                                break;
                            case B_PLAY:

                                if(buttonNextTurnState == NEXT_TURN_GRIS)
                                {
                                    actualTrou = searchByPosTrou(racine, buttonPlayPushed);
                                    if(actualTrou->pieces > 0)
                                    {
                                        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, soundClick, 0, NULL);


                                        int posLastTrou =  distributePieces(racine, actualTrou->next,buttonPlayPushed, actualTrou->pieces);
                                        actualTrou->pieces = 0;

                                        if(posLastTrou <= 6 && posLastTrou >=1)
                                        {

                                            ListTrous* lastTrou = searchByPosTrou(racine, posLastTrou);

                                            if(lastTrou->pieces == 1)
                                            {

                                                ListTrous* monKalah = searchByPosTrou(racine, 7);
                                                ListTrous* TrouEnface = searchByPosTrou(racine, NOMBRE_TROUS - posLastTrou);

                                                monKalah->pieces += TrouEnface->pieces;
                                                TrouEnface->pieces = 0;

                                                //Jouer son (bonus)
                                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, bonus, 0, NULL);


                                            }
                                            buttonNextTurnState = NEXT_TURN_ACTIF;
                                        }
                                        else if(posLastTrou == 7) //7 position de mon Kalah
                                        {
                                            //Jouer son bonus

                                            buttonNextTurnState = NEXT_TURN_GRIS;
                                        }
                                        else
                                            buttonNextTurnState = NEXT_TURN_ACTIF;

                                        if(jeuFini(racine) == 1)
                                            {
                                                switch(whoIsWinner(racine))
                                                {
                                                    case 0:
                                                        afficherMsg(ecran, "Egalite.");
                                                    break;
                                                    case 1:
                                                        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, app, 0, NULL);
                                                        afficherMsg(ecran, "Joueur 1 a gagne.");
                                                    break;
                                                    case 2:
                                                        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, app, 0, NULL);
                                                        afficherMsg(ecran, "Joueur 1 a gagne.");
                                                    break;
                                                    default:
                                                    break;
                                                }

                                                continuer = 0;

                                            }
                                    }
                                    else
                                        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, alert, 0, NULL);




                                }
                                else
                                    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, alert, 0, NULL);


                                break;

                            case B_NextTurn:

                                if(buttonNextTurnState == NEXT_TURN_ACTIF)
                                {
                                    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, soundClick, 0, NULL);

                                    racine = changeTurnPlaying(racine);
                                    buttonNextTurnState = NEXT_TURN_GRIS;
                                }
                                else
                                    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, alert, 0, NULL);



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

        if (buttonNextTurnState == NEXT_TURN_ACTIF)
        {
        	SDL_BlitSurface(buttNextTurn, NULL, ecran, &positionButtNextTurn);
        }
        else
        {
        	SDL_BlitSurface(buttNextTurnGris, NULL, ecran, &positionButtNextTurn);
        }


        blitSurfaceText(ecran, racine, positionTexts, police, colorNbrPieces);




        SDL_Flip(ecran);
    }

    SDL_FreeSurface(buttNextTurnGris);
    SDL_FreeSurface(buttNextTurn);
    SDL_FreeSurface(fond);

}
