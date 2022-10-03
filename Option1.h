//
// Created by Alan on 6/17/2020.
//

#ifndef P2FINAL_OPTION1_H
#define P2FINAL_OPTION1_H

#include "Menu.h"


/*Checks inputs for option 1 parameters, both inputs are the strings of the parameters that are being entered itself
it will return the integer with the correct format*/
int datacheck(char* string, char* string1);

//Procedure that sets all the text of the configurator window of the car.
void textConfigurator(Carconfig *config,Category *category, int i,int numcategories);

//Procedure that checks which arrow key was pressed and moves arround the categories and parts.
void keyPressed(Category *category, int numcategories, Carconfig *config, int *i, int *k);

//Function that gets the total stats of the car when the configurator window is closed.
Carconfig carStats(Carconfig *config, const Category *category, int i, int numcategories);

//Procedure that perfoms everything about the window of configuration
void configWindow(Category* category,const int numcategories, Carconfig* config);

//Procedure that shows the images of the categories we are configuring
void imagesCategories( ALLEGRO_BITMAP* neumaticos, ALLEGRO_BITMAP* motor, ALLEGRO_BITMAP* gasolina,Category* category,int i);

#endif //P2FINAL_OPTION1_H
