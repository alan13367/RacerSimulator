//
// Created by Alan on 6/20/2020.
//


#include "Option2.h"


//Procedure that shows the welcome message at each GP we start
void textGPstart(SortedList *gplist) {
    //Paint background in black
    LS_allegro_clear_and_paint(BLACK);
    //Show the Gp we are on
    al_draw_textf(LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(WHITE), 350, 100, 0, "Welcome to %s",
                  (*gplist).head->element.GpName);
    //Show the appropiate stats for this GP and the Letter to start the race
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 500, 200, 0, "Speed: %d", (*gplist).head->element.appspeed);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 500, 250, 0, "Acceleration: %d", (*gplist).head->element.appacceleration);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 500, 300, 0, "Consumption: %d", (*gplist).head->element.appconsumption);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 500, 350, 0, "Reliability: %d", (*gplist).head->element.appreliability);
    al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(YELLOW),400,500,0,"Press R to start the race");

}

//Procedure that shows the traffic lights before starting the race
void trafficLights() {
    //Define variables that are being used in the program
    int winexit = 0;
    int drawcircles = 0;
    int firstsec = 0;
    //Create both time variables
    float time0,time1;
    //Set initial time
    time0 = (float) clock();
    //infinite loop of the window
    while(!winexit){
        //Paints the background in white
        LS_allegro_clear_and_paint(WHITE);
        //Drawing of all the traffic lights
        al_draw_filled_rectangle(250,50,400,650,LS_allegro_get_color(BLACK));
        al_draw_filled_circle(325,150,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(325,275,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(325,400,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(325,525,50,LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(450,50,600,650,LS_allegro_get_color(BLACK));
        al_draw_filled_circle(525,150,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(525,275,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(525,400,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(525,525,50,LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(650,50,800,650,LS_allegro_get_color(BLACK));
        al_draw_filled_circle(725,150,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(725,275,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(725,400,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(725,525,50,LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(850,50,1000,650,LS_allegro_get_color(BLACK));
        al_draw_filled_circle(925,150,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(925,275,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(925,400,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(925,525,50,LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(1050,50,1200,650,LS_allegro_get_color(BLACK));
        al_draw_filled_circle(1125,150,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(1125,275,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(1125,400,50,LS_allegro_get_color(GRAY));
        al_draw_filled_circle(1125,525,50,LS_allegro_get_color(GRAY));
        //Set time1
        time1 = (float) clock();
        //Check the time has passed
        if( (time1-time0) / (float) CLOCKS_PER_SEC >= 2.0 && drawcircles < 6){
            //Add one to draw the circles
            drawcircles++;
            time0 = (float) clock();
        }
        //Exit window when all the circles has been drawn and they are all gray
        if( (time1-time0) / (float) CLOCKS_PER_SEC >= 0.5 && drawcircles >= 6){
            //Exit window
            winexit++;
            //Set initial time to 0
            time0 = (float) clock();
        }

        //Conditioning of the red lights to be drawn depending on time passed
        if(drawcircles>=1 && drawcircles !=6){
            //Draw  red circles
            al_draw_filled_circle(325,400,50,LS_allegro_get_color(RED));
            al_draw_filled_circle(325,525,50,LS_allegro_get_color(RED));
        } else if (drawcircles == 6){
            //Draw circles in gray
            al_draw_filled_circle(325,400,50,LS_allegro_get_color(GRAY));
            al_draw_filled_circle(325,525,50,LS_allegro_get_color(GRAY));
        }
        if(drawcircles>=2 && drawcircles !=6){
            //Draw  red circles
            al_draw_filled_circle(525,400,50,LS_allegro_get_color(RED));
            al_draw_filled_circle(525,525,50,LS_allegro_get_color(RED));
        }else if (drawcircles == 6){
            //Draw circles in gray
            al_draw_filled_circle(525,400,50,LS_allegro_get_color(GRAY));
            al_draw_filled_circle(525,525,50,LS_allegro_get_color(GRAY));
        }
        if(drawcircles>=3 && drawcircles !=6){
            //Draw  red circles
            al_draw_filled_circle(725,400,50,LS_allegro_get_color(RED));
            al_draw_filled_circle(725,525,50,LS_allegro_get_color(RED));
        }else if (drawcircles == 6){
            //Draw circles in gray
            al_draw_filled_circle(725,400,50,LS_allegro_get_color(GRAY));
            al_draw_filled_circle(725,525,50,LS_allegro_get_color(GRAY));
        }
        if(drawcircles>=4 && drawcircles !=6 ){
            //Draw  red circles
            al_draw_filled_circle(925,400,50,LS_allegro_get_color(RED));
            al_draw_filled_circle(925,525,50,LS_allegro_get_color(RED));
        }else if (drawcircles == 6){
            //Draw circles in gray
            al_draw_filled_circle(925,400,50,LS_allegro_get_color(GRAY));
            al_draw_filled_circle(925,525,50,LS_allegro_get_color(GRAY));
        }
        if(drawcircles>=5 && drawcircles !=6){
            //Draw  red circles
            al_draw_filled_circle(1125,400,50,LS_allegro_get_color(RED));
            al_draw_filled_circle(1125,525,50,LS_allegro_get_color(RED));

        } else if (drawcircles == 6) {
            //Draw circles in gray
            al_draw_filled_circle(1125, 400, 50, LS_allegro_get_color(GRAY));
            al_draw_filled_circle(1125, 525, 50, LS_allegro_get_color(GRAY));
        }

    }

}

//Configuration of the race window
void windowConfigRace(Carconfig *config, const Racers *racers, Racer *racer) {
    //Paint background in white
    LS_allegro_clear_and_paint(WHITE);

    //Rectangles of the menu of the race
    al_draw_filled_rectangle(1000, 0, 1300, 720, LS_allegro_get_color(BLACK));
    al_draw_filled_rectangle(0,600,998,720,LS_allegro_get_color(BLACK));

    //Racers numbers and their respective lines
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 60, 0, "%d", (*racer).drivernumb);
    al_draw_line(100,(float)68.75,900,(float)68.75,LS_allegro_get_color(BLACK),4);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, (float)128.75, 0, "%d",racers[0].drivernumb);
    al_draw_line(100,(float)137.5,900,(float)137.5,LS_allegro_get_color(BLACK),4);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, (float)197.5, 0, "%d",racers[1].drivernumb);
    al_draw_line(100,(float)206.25,900,(float)206.25,LS_allegro_get_color(BLACK),4);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, (float)266.25, 0, "%d",racers[2].drivernumb);
    al_draw_line(100,275,900,275,LS_allegro_get_color(BLACK),4);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 335, 0, "%d",racers[3].drivernumb);
    al_draw_line(100,(float)343.75,900,(float)343.75,LS_allegro_get_color(BLACK),4);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, (float)403.75, 0, "%d",racers[4].drivernumb);
    al_draw_line(100,(float)412.5,900,(float)412.5,LS_allegro_get_color(BLACK),4);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, (float)472.5, 0, "%d",racers[5].drivernumb);
    al_draw_line(100,(float)481.25,900,(float)481.25,LS_allegro_get_color(BLACK),4);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, (float)541.25, 0, "%d",racers[6].drivernumb);
    al_draw_line(100,550,900,550,LS_allegro_get_color(BLACK),4);

    //Menu text button for radio call and Pit stop
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 20, 650, 0, "RADIO(R)");
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 750, 650, 0, "PIT STOP(P)");

    //Our driver information and stats
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1020, 25, 0, "Pilot");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1030, 75, 0, "Name");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1035, 100, 0, "%s", (*racer).drivername);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1030, 125, 0, "Team Name");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1035, 150, 0, "%s", (*racer).teamname);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1030, 175, 0, "Driver Number");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1035, 200, 0, "%d", (*racer).drivernumb);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1020, 250, 0, "Car");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1030, 300, 0, "Speed");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1030, 325, 0, "%d", (*config).carstats.speed);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1030, 350, 0, "Acceleration");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1030, 375, 0, "%d", (*config).carstats.acceleration);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1030, 400, 0, "Consumption");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1030, 425, 0, "%d", (*config).carstats.consumption);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1030, 450, 0, "Reliability");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1030, 475, 0, "%d", (*config).carstats.reliability);
}

//Function that will calculate the time our racer takes to do the current race without the pits stops
float racerTime(SortedList * gplist,Racer racer,Carconfig config){
    //Variable we will return
    float totaltime;

    //We add the base time of the Gp
    totaltime = gplist->head->element.basetime ;
    //Do the calculations regarding our car stats comparing them with the GP ones
    totaltime += (float)abs((gplist->head->element.appspeed - config.carstats.speed));
    totaltime += (float)abs((gplist->head->element.appacceleration - config.carstats.acceleration));
    totaltime += (float)abs((gplist->head->element.appconsumption - config.carstats.consumption));
    totaltime += (float)abs((gplist->head->element.appreliability - config.carstats.reliability));

    //Add our physical stats of the driver
    totaltime += ((float)(racer.reflexes + racer.physicalcond + racer.temperament + racer.tiremanagement)/4) / 2;

    //Return the time
    return totaltime;
}

//Function that will return the time of a racer we enter, taking into account the pitstops they have to do
float racersTime(Racers racers,SortedList* gplist){
    //Variables to be used in the function
    float totaltime;
    int pitstops;
    //Base time of the gp
    totaltime = gplist->head->element.basetime ;
    //Difference between the stats of the racer and the appropiate ones
    totaltime += (float)abs((gplist->head->element.appspeed - racers.speed));
    totaltime += (float)abs((gplist->head->element.appacceleration - racers.acceleration));
    totaltime += (float)abs((gplist->head->element.appconsumption - racers.consumption));
    totaltime += (float)abs((gplist->head->element.appreliability - racers.reliability));

    //We make the calculations with the physical stats
    totaltime += ((float)(racers.reflexes + racers.physicalcond + racers.temperament + racers.tiremanage)/4) / 2;
    //Get the pitstops they will have to do
    pitstops = getMaxPitStops(racers.consumption,gplist);

    //Add to the total time the pitstops we have to do
    totaltime += (float)pitstops * (float)gplist->head->element.pittime;

    //Return the totaltime
    return totaltime;
}

//Function that will return the number of pitstops we have to do base on our consumption and the GP consumption we are on
int getMaxPitStops(int consumption, SortedList *gplist) {
    //Define variable to be returned
    int maxpitstops;

    //If lower that the gp one
    if (consumption < (*gplist).head->element.appconsumption) {
        //We substract one from the pitstops number
        maxpitstops = (*gplist).head->element.numpit - 1;
    }   else{
        //If its higher than the appropiate one of the GP
        if (consumption > (*gplist).head->element.appconsumption) {
            //We will add one to the appropiate number of pitstops
            maxpitstops = (*gplist).head->element.numpit + 1;
        }   else{
            //If not of the other conditions will be same as the appropiate number of pitstops
            maxpitstops = (*gplist).head->element.numpit;
        }
    }
    //Return the number of pitstops we got
    return maxpitstops;
}

//Function that will create a structure of the Leaderboards depending of the number of GP we have
LeaderBoards * createLeaderboards(int numgp){
    //Index to be used in the function
    int i;

    //Create malloc
    LeaderBoards *leaderboards = (LeaderBoards*) malloc(sizeof(LeaderBoards)*(numgp+1));
    if(NULL== leaderboards){
        printf("\nError creating the leaderboards.\n");
    }else{
        //The number of times +1 for the final leaderboards
        for(i=0;i<(numgp+1);i++){
            //Create a dynamic array inside each leaderboard with 8 postions one for each racer in the race
            leaderboards[i].racerspos = (ScoreRacers*) malloc(sizeof(ScoreRacers)*8);
        }
    }
    // Return the dynamic array
    return leaderboards;
}

//Procedure that will add to the leader board after each race is completed
void addToleaderboards(LeaderBoards* leaderboards, int j, SortedGp gpscore,SortedList* gplist){
    //Variables and flags to be used in procedure
    int i;
    int k;
    int found;
    //Create a sortedlist to sort by points
    SortedGp pointscores;

    //Copy name of the gp to the name of the leaderboard
    strcpy(leaderboards[j].gpname,gplist->head->element.GpName);
    //Go to next
    SORTEDGP_nextGP(&gpscore);
    //Loop for the 8 racers
    for(i= 0;i<8;i++){
        //Set found to 0
        found = 0;
        //Copy name of racer
        strcpy(leaderboards[j].racerspos[i].name,gpscore.head->element.name);
        //Copy time of racer
        leaderboards[j].racerspos[i].time = gpscore.head->element.time;
        //Copy number of racer
        leaderboards[j].racerspos[i].drivernumb = gpscore.head->element.drivernumb;

        //Check in which position he ended up and give respective points with the switch
        switch(i){
            case 0:
                leaderboards[j].racerspos[i].points = 25;
                //If its not the first one we will check previous score and add the points gotten
                if(j!= 0) {
                    //Loop for entire array until find the racer
                    for (k = 0; k < 8 && found==0; k++) {
                        //Compare name to find the racer
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            //Set found to 1
                            found =1;
                            //Add the points
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }
                }
                break;
            case 1:
                leaderboards[j].racerspos[i].points = 18;
                if(j!= 0) {
                    for (k = 0; k < 8 && found==0; k++) {
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            found =1;
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }

                }
                break;
            case 2:
                leaderboards[j].racerspos[i].points = 15;
                if(j!= 0) {
                    for (k = 0; k < 8 && found==0; k++) {
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            found =1;
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }

                }
                break;
            case 3:
                leaderboards[j].racerspos[i].points = 10;
                if(j!= 0) {
                    for (k = 0; k < 8 && found==0; k++) {
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            found =1;
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }

                }
                break;
            case 4:
                leaderboards[j].racerspos[i].points = 8;
                if(j!= 0) {
                    for (k = 0; k <  8 && found==0; k++) {
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            found =1;
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }

                }
                break;
            case 5:
                leaderboards[j].racerspos[i].points = 6;
                if(j!= 0) {
                    for (k = 0; k < 8 && found==0; k++) {
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            found =1;
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }

                }
                break;
            case 6:
                leaderboards[j].racerspos[i].points = 5;
                if(j!= 0) {
                    for (k = 0; k < 8 && found==0; k++) {
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            found =1;
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }

                }
                break;
            case 7:
                leaderboards[j].racerspos[i].points = 3;
                if(j!= 0) {
                    for (k = 0; k < 8 && found==0; k++) {
                        if(strcmp(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[k].name)==0){
                            found =1;
                            leaderboards[j].racerspos[i].points += leaderboards[j-1].racerspos[k].points;
                        }
                    }

                }
                break;
        }

        //Go to next
        SORTEDGP_nextGP(&gpscore);
    }
    //Create a list to sort by points
    pointscores = SORTEDGP_create();
    //Add all elements to the list sorted by points
    for(i = 0;i<8;i++){
        SORTEDGP_sortedAddPoints(&pointscores,leaderboards[j].racerspos[i]);
    }
    //Next element on the list
    SORTEDGP_nextGP(&pointscores);
    //Add them to the leaderboards array
    for(i=0;i<8;i++){
        //Copy name
        strcpy(leaderboards[j].racerspos[i].name,pointscores.head->element.name);
        //Copy time
        leaderboards[j].racerspos[i].time = pointscores.head->element.time;
        //Copy driver number
        leaderboards[j].racerspos[i].drivernumb = pointscores.head->element.drivernumb;
        //Copy the points
        leaderboards[j].racerspos[i].points = pointscores.head->element.points;
        //Go to next element in the list
        SORTEDGP_nextGP(&pointscores);
    }
    //Destroy list created
    SORTEDGP_destroy(&pointscores);

}

//Function that will return the number of pixels our driver will move in the race
float pixelsperSec(float racertime, int pixels){
    //Define a variable we will return
    float number;

    //Number of pixels divided by the time will give us pixels/sec
    number = (float)pixels / racertime;

    //Return the number we got
    return number;
}

//Procedure that will take care of simulating the entire race
void simRace(Racers *racers, SortedList *gplist, Carconfig *config, Racer *racer) {

    //Create the variables we are going to use
    int i;
    ALLEGRO_BITMAP* car;
    float carposition = 70;
    float pixelscarssec[7];
    float racerscars[7];

    //Calculate our racer time
    float racertime = racerTime(gplist,*racer,*config);

    //We calculate the pixels our driver will move per second
    float pixelsec = pixelsperSec(racertime,800);
    //Set all the racers cars to the initial position
    for(i= 0;i<7;i++){
        //Set to 70
        racerscars[i] = 70.00;
    }
    //For all the racers calculate their time
    float racerstime[7];
    for(i=0 ; i < 7 ; i++){
        racerstime[i] = racersTime(racers[i],gplist);
    }
    //Calculate the pixels the drivers will move per second
    for(i=0;i < 7;i++){
        //Function that will calculate how much pixels they mover per second based in a time
        pixelscarssec[i] = pixelsperSec(racerstime[i],800);
    }
    //Variables for the pitstops
    int currentpit = 0;
    int radio =0;
    int stop =0;
    int changestop = 0;
    int ablepit = 1;
    int totalpit = 0;
    int maxpitstops;
    //Variables for movement of the car and time of the racer
    int k;
    float totaltime = 0;
    float racetime = racertime;
    //We get the max pitstops our driver is able to do
    maxpitstops = getMaxPitStops(config->carstats.consumption,gplist);

    //Variables to be used for working with time
    float time0, time1;

    //Define the bitmap of the car we are going to use
    car = al_load_bitmap("cotxe.png");

    //Set initial time
    time0 = (float) clock();

    //Loop that will end when the racer has reached the time
    while(totaltime < racetime){

        //Procedure with the design of the window and the information of the driver
        windowConfigRace(config, racers, racer);

        //Conditions to check when the race is going to end if the racer will end in the proper position
        if(totaltime + 1 == racertime || totaltime == racertime){
            al_draw_scaled_bitmap(car, 0, 0, (float)al_get_bitmap_width(car), (float)al_get_bitmap_height(car), 870, 45, 75, 50, 0);
        }
        else{
            //We will draw the position of the car for each second
            al_draw_scaled_bitmap(car, 0, 0, (float)al_get_bitmap_width(car), (float)al_get_bitmap_height(car), carposition, 45, 75, 50, 0);

        }
        //Position of the racers cars that will vary depending of the time each 1 second
        al_draw_scaled_bitmap(car,0,0,(float)al_get_bitmap_width(car),(float)al_get_bitmap_height(car),racerscars[0],(float)113.75,75,50,0);
        al_draw_scaled_bitmap(car,0,0,(float)al_get_bitmap_width(car),(float)al_get_bitmap_height(car),racerscars[1],(float)182.5,75,50,0);
        al_draw_scaled_bitmap(car,0,0,(float)al_get_bitmap_width(car),(float)al_get_bitmap_height(car),racerscars[2],(float)251.25,75,50,0);
        al_draw_scaled_bitmap(car,0,0,(float)al_get_bitmap_width(car),(float)al_get_bitmap_height(car),racerscars[3],320,75,50,0);
        al_draw_scaled_bitmap(car,0,0,(float)al_get_bitmap_width(car),(float)al_get_bitmap_height(car),racerscars[4],(float)388.75,75,50,0);
        al_draw_scaled_bitmap(car,0,0,(float)al_get_bitmap_width(car),(float)al_get_bitmap_height(car),racerscars[5],(float)457.5,75,50,0);
        al_draw_scaled_bitmap(car,0,0,(float)al_get_bitmap_width(car),(float)al_get_bitmap_height(car),racerscars[6],(float)526.25,75,50,0);

        //Text that shows the total time elapsed in the race and the stops we made and the maximum we are able to do
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1125, 525, 0, "%.f",totaltime);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1020, 650, 0, "Stops: %d / %d",currentpit,maxpitstops);

        //Check if we pressed the radio with R
        if(LS_allegro_key_pressed(ALLEGRO_KEY_R) && radio != 1){
            //if pressed turn radio to 1
            radio = 1;
        }
        //Check if we are able to pitstop and if P is pressed and we are in the middle of another pit stop
        if(LS_allegro_key_pressed(ALLEGRO_KEY_P ) && ablepit == 1 && changestop == 0){
            //If we pit stop we will add the pitstop time to the total time of the race
            racetime += (float) (*gplist).head->element.pittime;
            //We set the stop to 1
            stop = 1;
            //We add one to the totalpitstops we made in the race
            totalpit++;
            //If we made a radio call before doing the pitstop and we still didnt make the maxpitstops
            if(radio == 1 && currentpit < maxpitstops){
                //We add one to the current "radio pitstops"
                currentpit++;
                //Check if we reached the maximum pitstops
                if(currentpit == maxpitstops){
                    //If we did we turn able pit to 0 so we cant make any other pitstop
                    ablepit = 0;
                }
                //Set radio to 0 again
                radio = 0;
            }

        }
        //Check the time it has elapsed
        time1 = (float) clock();
        //If 1 second has been elapsed
        if((time1-time0) / (float) CLOCKS_PER_SEC >= 1.00 ){
            //We add the time to the totaltime elapsed
            totaltime += (time1-time0) / (float) CLOCKS_PER_SEC;
            //Check if we are on a pitstop
            if(stop == 0) {
                //If we arent we add the pixels we should advance per second
                carposition += pixelsec;
            }
            else{
                //If we are on a pitstop we add one to the seconds that has elapsed on that pitstop
                changestop++;
            }
            //We add the pixels per second that the racers advance every second elapsed
            for(k=0;k<7;k++){
                if(racerscars[k] < 870) {
                    //We keep adding them their pixels per second to their position
                    racerscars[k] += pixelscarssec[k];
                    //If the final position would be higher than the last point we set that to that position
                    if(racerscars[k] > 870){
                        racerscars[k] = 870;
                    }
                }
            }
            //If we reached the time of the pitstop
            if(changestop == (*gplist).head->element.pittime){
                //We let the car move again by setting stop to 0
                stop = 0;
                //And we set the current pit time to 0 again so if needed we can start another pit stop
                changestop = 0;
            }
            //Set initial time again
            time0 = (float) clock();
        }

    }
    //When race ended we check if we did the pitstop required
    if(maxpitstops == currentpit){
        //If we did the pitstops we had to do the time of the race will be the elapsed in the simulation
        config->times[gplist->head->element.position - 1] = racertime + (float)(totalpit*gplist->head->element.pittime) ;
    }else{
        //Otherwise if we didnt do the pitstops required we will add the penalization to the time of the race
        config->times[gplist->head->element.position - 1] = racertime + (float)(5*gplist->head->element.pittime);
    }
    //Exit window
    LS_allegro_exit();
}

//Function used to store the standings in each Gp in a list in order
SortedGp storeScores(Carconfig *config,float* racerstime,Racers *racers,int j,Racer* racer,SortedGp  scoregp) {
    //Index to be used
    int i;
    //Create dynamic array to store the information
    ScoreRacers *scores = (ScoreRacers *) malloc(sizeof(ScoreRacers) * 8);

    //Loop to store the information about the drivers in the array as well as their time in the simulated race
    for (i = 0; i < 7; i++) {
        //Name of the racer
        strcpy(scores[i].name, racers[i].name);
        //Time in the race
        scores[i].time = racerstime[i];
        //Their number
        scores[i].drivernumb = racers[i].drivernumb;
        //Initialize points to 0
        scores[i].points = 0;
    }
    //Name of the driver
    strcpy(scores[7].name, racer->drivername);
    //Our driver's number
    scores[7].drivernumb = racer->drivernumb;
    //The final time our driver lasted on the race
    scores[7].time = config->times[j];
    //Initialize points to 0
    scores[7].points = 0;

    //We create a list
    scoregp = SORTEDGP_create();

    //We add them sorted by their time
    for (i = 0; i < 8; i++) {
        SORTEDGP_sortedAdd(&scoregp, scores[i]);
    }
    SORTEDGP_goToHead(&scoregp);

    //Return the list
    return scoregp;
}

//Function that will show our drivers final position on the race
void showPos(int j, SortedGp gpscores, Racer racer) {
        //Variables used
        int i;
        int found = 0;
        int winexit = 0;

        //Go to head of the list
        SORTEDGP_goToHead(&gpscores);
        //Looping through the list until we find our driver
        for (i = 0; i < 8 && found == 0; i++) {
            if (strcmp(racer.drivername, gpscores.previous->next->element.name) == 0) {
                //If the name is the same means we found it so we exit loop
                found = 1;
            } else {
                //If we didnt find it we keep searching for it
                SORTEDGP_next(&gpscores);
            }
        }
        //Start window
        LS_allegro_init(1300, 720, "Racer Result");

        //Infinite loop of the window
        while (!winexit) {
            //Paint background in black
            LS_allegro_clear_and_paint(BLACK);
            //If we press enter we will exit the window therefore return to the menu
            if (LS_allegro_key_pressed(ALLEGRO_KEY_ENTER)) {
                //Set winexit to 1 so the loop will end
                winexit = 1;
            }
            //Draw the text with the drivers name and the position we found he ended in
            al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 400, 360, 0,
                          "%s has finished in %d position", racer.drivername, i);
            //Message telling the user to return menu with enter
            al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 400, 500, 0,
                          "Press enter to return to menu");

        }
        //Exit allegro window
        LS_allegro_exit();


}

//Procedure that will create leaderboard when you have done all the GPs
void finalScore(LeaderBoards *leaderboards,int j){
    //Index used
    int i;
    //As name of the leaderboard we set as end of season
    strcpy(leaderboards[j].gpname,"End of Season");
    //Loop to save all the racers info
    for(i=0;i<8;i++){
        //Copy name
        strcpy(leaderboards[j].racerspos[i].name,leaderboards[j-1].racerspos[i].name);
        //Copy the points
        leaderboards[j].racerspos[i].points = leaderboards[j-1].racerspos[i].points;
        //Copy driver number
        leaderboards[j].racerspos[i].drivernumb = leaderboards[j-1].racerspos[i].drivernumb;
    }
}

void gpStart(SortedList *gplist){
    //Initialize variable to exit the next window that is gonna be opened
    int winexit = 0;
    //We initialize the window for the grand prix start
    LS_allegro_init(1300, 720, "RaceSim");
    //Infinite loop of the window
    while (!winexit) {
        //Listening to the keyboard in order to exit the window and proceed to the next one
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            winexit = 1;
        }
        //Function used to display the start menu of a Grand Prix which is given by the list position
        textGPstart(gplist);
    }
    //Exit the window
    LS_allegro_clear_and_paint(WHITE);
}
