#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

    #define LARGEUR_FENETRE         640
    #define HAUTEUR_FENETRE         480

    //Main page

    #define NBR_G_BUTTON            4
    #define BUTTON_G_WIDTH          134
    #define BUTTON_G_HEIGHT         44

    #define BUTTON_MAIN_START_X     LARGEUR_FENETRE/2 - BUTTON_G_WIDTH/2
    #define BUTTON_MAIN_START_Y     HAUTEUR_FENETRE/3

    #define AERATION_BUT_G          30

    #define BUTTON_MAIN_FINISH_X     BUTTON_MAIN_START_X + BUTTON_G_WIDTH
    #define BUTTON_MAIN_FINISH_Y     BUTTON_MAIN_START_Y + NBR_G_BUTTON*BUTTON_G_HEIGHT + (NBR_G_BUTTON-1)*AERATION_BUT_G

    //Page de jeu

    #define NOMBRE_TROUS            14

    #define INITIAL_PIECES          6

    //les boutons de haut
    #define NBR_P_BUTTONS           5
    #define P_BUTTONS_START_X       0
    #define P_BUTTONS_START_Y       0

    //bouton "passer la main"

    #define B_NEXT_TURN_WIDTH       160
    #define B_NEXT_TURN_HEIGHT      34
    #define B_NEXT_TURN_START_X     239
    #define B_NEXT_TURN_START_Y     107

    //les boutons de bas
    #define P_BUTTON_WIDTH          42
    #define P_BUTTON_HEIGHT         41

    #define PLAY_BUTTON_START_X     99
    #define PLAY_BUTTON_START_Y     428

    #define  AERATION_PLAY_BUT      38

    //les textes
    #define TEXT_TROU_J1_START_X    115
    #define TEXT_TROU_J1_START_Y    382

    #define TEXT_TROU_J2_START_X    515
    #define TEXT_TROU_J2_START_Y    171

    #define TEXT_AERATION           80

    #define TEXT_KALAH_J1_X         602
    #define TEXT_KALAH_J2_X         27

    //Message box

    #define MESSAGE_BOX_WIDTH       450
    #define MESSAGE_BOX_HEIGHT      385



enum {B_JOUER, B_CHARGER, B_OPTIONS, B_QUITTER};

enum {B_UNDO, B_INFO, B_SAVE, B_SETTINGS, B_QUIT, B_PLAY, B_NextTurn};

enum {NEXT_TURN_ACTIF, NEXT_TURN_GRIS};

typedef enum TypeTrou
{
    TROU_NORMAL,
    TROU_KALAH
} TypeTrou;

typedef enum TypeJeu
{
    NEW_GAME,
    LOAD_GAME
} TypeJeu;

#endif
