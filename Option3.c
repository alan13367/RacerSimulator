//
// Created by Alan on 7/4/2020.
//

#include "Option3.h"

//Procedure that shows the leaderboards of each race and the end of season ranking
void showLeaderboards(const LeaderBoards *leaderBoards, int j, int numgp) {
    //Start allegro window
    LS_allegro_init(1300, 720, "Leaderboards");
    //Create variables to be used in procedure
    int winexit = 0;
    int i;
    //Define l as j-1 , because j is de next gp we will do so we would appear at the gp we just did
    int l=j-1;

    //Infinite loop of the window
    while(!winexit){
        //Paint background in black
        LS_allegro_clear_and_paint(BLACK);

        //Draw text of what ranking we are currently showing
        al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(WHITE), 100, 50, 0, "Leaderboards of %s",leaderBoards[l].gpname);

        //Check if we pressed escape if so we exit the window
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            //Set winexit to 1
            winexit = 1;
        }
        //Condition to make sure you cant move more than gps simulated
        if(l+1 < j || l+1 == numgp){
            //Check if key d is pressed
            if(LS_allegro_key_pressed(ALLEGRO_KEY_D)){
                //Go to next position
                l++;

            }
        }
        //Condition to make sure you wont get to unwanted positions of the dynamic array
        if(l-1 != -1){
            //Check if a is pressed
            if(LS_allegro_key_pressed(ALLEGRO_KEY_A)){
                //Go to position before
                l--;
            }
        }
        //Check if we are not in the final ranking
        if(l<numgp) {
            for (i = 0; i < 8; i++) {
                //First position yellow
                if (i == 0) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(YELLOW), 200,
                                  (float) 150 + (float) (50 * i), 0,
                                  "%d. %s (%.f S) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].time,
                                  leaderBoards[l].racerspos[i].points);
                }
                //Second position gray
                if (i == 1) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(GRAY), 200,
                                  (float) 150 + (float) (50 * i), 0,
                                  "%d. %s (%.f S) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].time,
                                  leaderBoards[l].racerspos[i].points);
                }
                //Third position red
                if (i == 2) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(RED), 200,
                                  (float) 150 + (float) (50 * i), 0,
                                  "%d. %s (%.f S) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].time,
                                  leaderBoards[l].racerspos[i].points);
                }
                //All the other positions in white
                if (i > 2) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(WHITE), 200,
                                  (float) 200 + (float) (50 * i), 0,
                                  "%d. %s (%.f S) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].time,
                                  leaderBoards[l].racerspos[i].points);
                }
            }
        }
        else {
            //If you reached to the final position of the array the ranking of the end of season
            for (i = 0; i < 8; i++) {
                //First position color yellow
                if (i == 0) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(YELLOW), 200,
                                  (float) 150 + (float) (50 * i), 0,
                                  "%d. %s (#%d) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].drivernumb,
                                  leaderBoards[l].racerspos[i].points);
                }
                //Second position color gray
                if (i == 1) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(GRAY), 200,
                                  (float) 150 + (float) (50 * i), 0,
                                  "%d. %s (#%d) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].drivernumb,
                                  leaderBoards[l].racerspos[i].points);
                }
                //Third position color red
                if (i == 2) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(RED), 200,
                                  (float) 150 + (float) (50 * i), 0,
                                  "%d. %s (#%d) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].drivernumb,
                                  leaderBoards[l].racerspos[i].points);
                }
                //All the others in white
                if (i > 2) {
                    al_draw_textf(LS_allegro_get_font(LARGE),
                                  LS_allegro_get_color(WHITE), 200,
                                  (float) 200 + (float) (50 * i), 0,
                                  "%d. %s (#%d) - %d", i + 1,
                                  leaderBoards[l].racerspos[i].name,
                                  leaderBoards[l].racerspos[i].drivernumb,
                                  leaderBoards[l].racerspos[i].points);
                }
            }
        }
    }
    //Exit the allegro window
    LS_allegro_exit();
}