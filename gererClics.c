#include "gererClics.h"

int whatGButtonPushed(SDL_Event event)
{
    if(event.button.x >= BUTTON_MAIN_START_X && event.button.x <= BUTTON_MAIN_FINISH_X &&
       event.button.y >= BUTTON_MAIN_START_Y && event.button.y <= BUTTON_MAIN_FINISH_Y)
   {
       if (event.button.y <= BUTTON_MAIN_START_Y + BUTTON_G_HEIGHT)
       {
           return B_JOUER;
       }
       else if (event.button.y >= BUTTON_MAIN_START_Y + BUTTON_G_HEIGHT + AERATION_BUT_G &&
                event.button.y <= BUTTON_MAIN_START_Y + 2*BUTTON_G_HEIGHT + AERATION_BUT_G)
       {
           return B_CHARGER;
       }
       else if(event.button.y >= BUTTON_MAIN_START_Y + 2*(BUTTON_G_HEIGHT + AERATION_BUT_G) &&
                event.button.y <= BUTTON_MAIN_START_Y + 3*BUTTON_G_HEIGHT + 2*AERATION_BUT_G)
       {
           return B_OPTIONS;
       }
       else if(event.button.y >= BUTTON_MAIN_START_Y + 3*(BUTTON_G_HEIGHT + AERATION_BUT_G) &&
                event.button.y <= BUTTON_MAIN_START_Y + 4*BUTTON_G_HEIGHT + 3*AERATION_BUT_G)
       {
           return B_QUITTER;
       }
       else return -1;
   }

    return -1;

}



int whatPButtonPushed(SDL_Event event, int* buttonPlayPushed)
{
    //bouton de haut
    if(event.button.x >= P_BUTTONS_START_X && event.button.x <= P_BUTTONS_START_X + NBR_P_BUTTONS*P_BUTTON_WIDTH &&
       event.button.y >= P_BUTTONS_START_Y && event.button.y <= P_BUTTONS_START_Y + P_BUTTON_HEIGHT)
    {
        return event.button.x/P_BUTTON_WIDTH;
    }
    else
   {
       //bouton next turn

       if(event.button.x >= B_NEXT_TURN_START_X && event.button.x <= B_NEXT_TURN_START_X + B_NEXT_TURN_WIDTH
          && event.button.y >= B_NEXT_TURN_START_Y && event.button.y <= B_NEXT_TURN_START_Y + B_NEXT_TURN_HEIGHT)
       {
           return B_NextTurn;
       }

       else
       {
           //bouton bas
            if(event.button.x >= PLAY_BUTTON_START_X &&
           event.button.y >= PLAY_BUTTON_START_Y && event.button.y <= PLAY_BUTTON_START_Y + P_BUTTON_HEIGHT)
           {
               if (event.button.x <= PLAY_BUTTON_START_X + P_BUTTON_WIDTH)
               {
                   *buttonPlayPushed = 1;
                   return B_PLAY;
               }
               else if(event.button.x >= PLAY_BUTTON_START_X + P_BUTTON_WIDTH + AERATION_PLAY_BUT &&
                        event.button.x <= PLAY_BUTTON_START_X + 2*P_BUTTON_WIDTH + AERATION_PLAY_BUT)
               {
                   *buttonPlayPushed = 2;
                   return B_PLAY;
               }
               else if(event.button.x >= PLAY_BUTTON_START_X + 2*P_BUTTON_WIDTH + 2*AERATION_PLAY_BUT &&
                        event.button.x <= PLAY_BUTTON_START_X + 3*P_BUTTON_WIDTH + 2*AERATION_PLAY_BUT)
               {
                   *buttonPlayPushed = 3;
                   return B_PLAY;
               }
               else if(event.button.x >= PLAY_BUTTON_START_X + 3*P_BUTTON_WIDTH + 3*AERATION_PLAY_BUT &&
                        event.button.x <= PLAY_BUTTON_START_X + 4*P_BUTTON_WIDTH + 3*AERATION_PLAY_BUT)
               {
                   *buttonPlayPushed = 4;
                   return B_PLAY;
               }
               else if(event.button.x >= PLAY_BUTTON_START_X + 4*P_BUTTON_WIDTH + 4*AERATION_PLAY_BUT &&
                        event.button.x <= PLAY_BUTTON_START_X + 5*P_BUTTON_WIDTH + 4*AERATION_PLAY_BUT)
               {
                   *buttonPlayPushed = 5;
                   return B_PLAY;
               }
               else if(event.button.x >= PLAY_BUTTON_START_X + 5*P_BUTTON_WIDTH + 5*AERATION_PLAY_BUT &&
                        event.button.x <= PLAY_BUTTON_START_X + 6*P_BUTTON_WIDTH + 5*AERATION_PLAY_BUT)
               {
                   *buttonPlayPushed = 6;
                   return B_PLAY;
               }

               else return -1;
           }
       }

       return -1;

   }

}
