//
// Created by Alan on 6/26/2020.
//


#ifndef P2FINAL_MENU_H
#define P2FINAL_MENU_H

//Includes we will need in the header
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "LS_allegro.h"
#include "sortedlist.h"
#include "sortedgplist.h"


#define MAX 25

//Struct used to store the information about our racer
typedef struct{
    char drivername[MAX];
    char teamname[MAX];
    int drivernumb;
    int reflexes;
    int physicalcond;
    int temperament;
    int tiremanagement;
}Racer;

//Struct to store the information of a part
struct Part{
    char partname[MAX];
    int speed;
    int acceleration;
    int consumption;
    int reliability;
};
//Struct to store the information of the category and its parts
typedef struct{
    char categoryname[MAX];
    struct Part* part;
    int numparts;
    int selected;
}Category;

//Struct used to store the stats of our car
typedef struct{
    int speed;
    int acceleration;
    int consumption;
    int reliability;
}Stats;
//Struct to store the stats structure and the time of the races
typedef struct{
    Stats carstats;
    float* times;
}Carconfig;

//Struct to store all the information about our racers
typedef struct{
    char name[MAX];
    int drivernumb;
    char teamname[MAX];
    int speed;
    int acceleration;
    int consumption;
    int reliability;
    int reflexes;
    int physicalcond;
    int temperament;
    int tiremanage;
}Racers;

//Structure define for saving the leaderboards in each race
typedef struct{
    char gpname[25];
    ScoreRacers* racerspos;
}LeaderBoards;



//Function that stores all the content of the GP file into a Sorted List
SortedList storeGP(SortedList gplist, FILE* gpfile,int* error,Carconfig* config,int * numgp);

//This function will load all the information of the parts file to a Dynamic Array, its input is the file containing the info.
Category* loadparts(FILE* fileparts,int* numcategories,int* error);

//This procedure shows the menu when called and the input is the string that will be returned with the instrusction given by the user.
void showMenu(char* instruction);

//Function that checks if the arguments are valid
int checkarguments(int argnum);

//Function that will load all the drivers from the binary file
Racers* loadRacers(FILE* file,int* error);

//Procedure that loads the data from the base file into a structure
void baseLoad(FILE* file, Racers* racers,int * error);

//Procedure that will free all the memory that has been used in the program
void freeMem(Category * category,Racers *racers,LeaderBoards *leaderBoards,SortedGp *gpscores,int numcategories);

#endif //P2FINAL_MENU_H
