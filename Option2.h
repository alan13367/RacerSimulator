//
// Created by Alan on 6/20/2020.
//

#ifndef P2FINAL_OPTION2_H
#define P2FINAL_OPTION2_H

#include <time.h>
#include <math.h>
#include "Option1.h"


//Procedure that shows the welcome message at each GP we start
void textGPstart(SortedList *gplist);

//Procedure that will show the traffic lights before the start of the race
void trafficLights();

//Configuration of the race window
void windowConfigRace(Carconfig *config, const Racers *racers, Racer *racer);

//Function that will calculate the time our racer takes to do the current race without the pits stops
float racerTime(SortedList * gplist,Racer racer,Carconfig config);

//Function that will return the number of pitstops we have to do base on our consumption and the GP consumption we are on
int getMaxPitStops(int consumption, SortedList *gplist);

//Function that will return the time of a racer we enter, taking into account the pitstops they have to do
float racersTime( Racers racers,SortedList* gplist);

//Function that will return the number of pixels our driver will move in the race
float pixelsperSec(float racertime, int pixels);

//Procedure that will take care of simulating the entire race
void simRace(Racers *racers, SortedList *gplist, Carconfig *config, Racer *racer);

//Function that will show our drivers final position on the race
void showPos(int j,SortedGp gpscores,Racer racer);

//Function that will create a structure of the Leaderboards depending of the number of GP we have
LeaderBoards * createLeaderboards(int numgp);

//Procedure that will add to the leader board after each race is completed
void addToleaderboards(LeaderBoards* leaderboards, int j, SortedGp gpscore,SortedList* gplist);

//Function used to store the standings in each Gp in a list in order
SortedGp storeScores(Carconfig *config,float* racerstime,Racers *racers,int j,Racer * racer,SortedGp gpscores);

//Procedure that will create leaderboard when you have done all the GPs
void finalScore(LeaderBoards *leaderboards,int j);

void gpStart(SortedList *gplist);

#endif //P2FINAL_OPTION2_H
