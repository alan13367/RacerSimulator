//
// Created by Alan on 6/17/2020.
//

#include "Option1.h"



//Function that will check inputs for our racer stats and return the wanted input
int datacheck(char* string, char* string1){
    //Variabhles to be used in the function
    int finalnumb;
    int found;
    char stringtoint[MAX];
    char aux;

    //Printsf asking for things in console

    printf("%s",string);
    //Scans the string
    scanf("%s",stringtoint);
    scanf("%c",&aux);

    //Transforms atoi into number
    finalnumb = atoi(stringtoint);
    //Set to 0 found flag
    found = 0;
    //Checks if number accomplishes conditions
    if(finalnumb <= 10 && finalnumb >=1){
        //If true sets flag to 1 and the function will proceed to return number
        found = 1;
    }
    //If after checking the condition we still didnt find it we keep searching for a valid number
    while (!strcmp(stringtoint, "0") == 0 && found ==0) {
        //Prints the stat to be reentered and also an error indicating that the first entered wasnt correct
        printf("%s",string1);
        printf("%s",string);
        scanf("%s", stringtoint);
        scanf("%c", &aux);

        //Transform string into an integer
        finalnumb = atoi(stringtoint);

        //Checks if accomplishes condition if so turns flag into 1 and returns number
        if (finalnumb <= 10 && finalnumb >= 1) {
            found = 1;
        }
    }
    //Returns the correct number
    return finalnumb;
}

//Procedure that will be used to configure the images of our configurator
void interfaceConfigurator(ALLEGRO_BITMAP* garageimg,ALLEGRO_BITMAP* arrowup, ALLEGRO_BITMAP*arrowleft,ALLEGRO_BITMAP*arrowright, ALLEGRO_BITMAP*arrowdown) {


    //Set all the ifs to the images so while inside the window loop will always show them in screen same for all images.
    if (garageimg) {
        al_draw_scaled_bitmap(garageimg, 0, 0,
                              (float)al_get_bitmap_width(garageimg),
                              (float)al_get_bitmap_height(garageimg), 0, 0, 850,
                              720, 0);
    }
    if (arrowup) {
        al_draw_scaled_bitmap(arrowup, 0, 0, (float)al_get_bitmap_width(arrowup),
                              (float)al_get_bitmap_height(arrowup), 925, 90, 100,
                              70, 0);
    }
    if (arrowleft) {
        al_draw_scaled_bitmap(arrowleft, 0, 0,
                              (float)al_get_bitmap_width(arrowleft),
                              (float)al_get_bitmap_height(arrowleft), 860, 150, 80,
                              100, 0);

    }
    if (arrowright) {
        al_draw_scaled_bitmap(arrowright, 0, 0,
                              (float)al_get_bitmap_width(arrowright),
                              (float)al_get_bitmap_height(arrowright), 1010, 150,
                              80, 100, 0);

    }
    if (arrowdown) {
        al_draw_scaled_bitmap(arrowdown, 0, 0,
                              (float)al_get_bitmap_width(arrowdown),
                              (float)al_get_bitmap_height(arrowdown), 924, 225,
                              105, 80, 0);
    }

}

//Procedure that will handle everything about the configurator
void configWindow( Category* category,const int numcategories, Carconfig* config){
    //Sets flag of the window to 0
    int winexit = 0;
    //Initialize variables to 0 . These are the category and parts index
    int i = 0;
    int k = 0;
    //Allegro Bitmap Variables
    ALLEGRO_BITMAP* garageimg = al_load_bitmap("boxes.png");
    ALLEGRO_BITMAP* arrowup = al_load_bitmap("arrowup.png");
    ALLEGRO_BITMAP* arrowleft = al_load_bitmap("arrowleft.png");
    ALLEGRO_BITMAP* arrowright = al_load_bitmap("arrowright.png");
    ALLEGRO_BITMAP* arrowdown = al_load_bitmap("arrowdown.png");
    ALLEGRO_BITMAP * neumaticos = al_load_bitmap("neumaticos.png");
    ALLEGRO_BITMAP * motor = al_load_bitmap("motor.png");
    ALLEGRO_BITMAP * gasolina = al_load_bitmap("gasolina.png");

    //Infinite loop of the window.
    while (!winexit) {

        //Function that includes all the configuration of the images added to the window.
        interfaceConfigurator(garageimg, arrowup,arrowleft,arrowright,arrowdown);

        imagesCategories(neumaticos,motor,gasolina,category,i);
        //Listen if esc is pressed
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            winexit = 1;
        }
        //Function used to check if you pressed any arrow key and swaping in between the categories and parts.
        keyPressed(category, numcategories, config, &i, &k);

        //Text configuration of the allegro window
        textConfigurator(config, category, i,numcategories);

    }

}

//Procedure that will draw the images depending of the category of the car we are configuring
void imagesCategories( ALLEGRO_BITMAP* neumaticos,ALLEGRO_BITMAP* motor,ALLEGRO_BITMAP* gasolina,Category* category,int i){

    //Depending of the category we are currently on will show a different image
    if(strcmp(category[i].categoryname,"Neumaticos")==0){
        al_draw_scaled_bitmap(neumaticos,0,0,(float)al_get_bitmap_width(neumaticos),(float)al_get_bitmap_height(neumaticos),940,160,65,65,0);
    }
    if(strcmp(category[i].categoryname,"Motor")==0){
        al_draw_scaled_bitmap(motor,0,0,(float)al_get_bitmap_width(motor),(float)al_get_bitmap_height(motor),940,160,65,65,0);
    }
    if(strcmp(category[i].categoryname,"Gasolina")==0){
        al_draw_scaled_bitmap(gasolina,0,0,(float)al_get_bitmap_width(gasolina),(float)al_get_bitmap_height(gasolina),940,160,65,65,0);
    }


}

//Procedure that will check whick key was pressed in order to change parts and categories
void keyPressed(Category *category, int numcategories, Carconfig *config, int *i, int *k) {
    //Check if key up is pressed and go to next category
    if (LS_allegro_key_pressed(ALLEGRO_KEY_UP)) {
        (*i)++;
        //If you reached to the last category and try to add more you will go back to the first
        if ((*i) == numcategories) {
            //Sets the category index to 0
            *i = 0;
        }
        //Changes the part selected in that category
        (*k) = category[(*i)].selected;
    }
    //Check if key down is pressed and go to next category
    if (LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)) {
        //Substracts one category
        (*i)--;

        (*k) = 0;
        if ((*i) == -1) {
            (*i) = numcategories - 1;
        }
        //Changes to the part selected in that category
         (*k) = category[(*i)].selected;
    }
    //Checks if right key pressed
    if (LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)) {
        //Goes to nex part
        (*k)++;
        //If reached to the last part goes to first one.
        if ((*k) == category[(*i)].numparts) {
            (*k) = 0;
        }
        //Sets the selected part of that category to the current one.
        category[(*i)].selected = (*k);
    }
    //Checks if left key is pressed
    if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)) {
        //Substracts one category
        (*k)--;
        //If reachs to -1 goes back to last part
        if ((*k) == -1) {
            (*k) = category[(*i)].numparts - 1;
        }
        //Sets the selected part to the current K
        category[(*i)].selected = (*k);
    }
}

//Procedure that configurates the entire text in the configurator window
void textConfigurator(Carconfig *config,  Category *category, int i,int numcategories) {
    int j;
    //Shows text about the category and part displaying at that moment
    al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(WHITE), 900, 40, 0, "%s", category[i].categoryname);

    al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),1100,125,0,"%s",category[i].part[category[i].selected].partname);
    // Text that shows current part values
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),1100,185,0,"%s %d","Speed : ",category[i].part[category[i].selected].speed);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),1100,230,0,"%s %d","Acceleration : ",category[i].part[category[i].selected].acceleration);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),1100,275,0,"%s %d","Consumption : ",category[i].part[category[i].selected].consumption);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),1100,320,0,"%s %d","Reliability : ",category[i].part[category[i].selected].reliability);

    al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),875,400,0,"%s","Current Configuration");

    //Will draw text as many categories as there are making it dynamic
    for(j = 0 ; j<numcategories;j++){
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 875, 450 + j*50, 0, "%s : %s", category[j].categoryname,category[j].part[category[j].selected].partname);
    }
    //Paint background in black
    LS_allegro_clear_and_paint(BLACK);
}

//Function that will return the stats of our car after configuring it with the parts selected
Carconfig carStats(Carconfig *config, const Category *category, int i, int numcategories) {

    //Set car stats to 0
    config->carstats.speed =0;
    config->carstats.acceleration = 0;
    config->carstats.consumption = 0;
    config->carstats.reliability =  0;

    //Calculate current configuration from the parts selected in all categories
    for(i = 0;i<numcategories;i++){
        config->carstats.speed += category[i].part[category[i].selected].speed;
        config->carstats.acceleration += category[i].part[category[i].selected].acceleration;
        config->carstats.consumption += category[i].part[category[i].selected].consumption;
        config->carstats.reliability += category[i].part[category[i].selected].reliability;
    }

    //Returns the structure of the configuration
    return (*config);
}
