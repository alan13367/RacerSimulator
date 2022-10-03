#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include "Menu.h"
#include "Option2.h"
#include "Option3.h"
#include "Option4.h"

int main(int argc, char* argv[]){
    //Structs and Types defined
    Carconfig config;
    Racer racer;
    Category * category;
    Racers * racers;
    SortedList gplist;
    SortedGp * gpscores;
    LeaderBoards * leaderBoards;

    //Files
    FILE* partsfile;
    FILE* gpfile;
    FILE* racersfile;
    FILE* basefile;

    //Variables
    char instruction[MAX]={'\0'};
    char aux;
    char stringtoint[MAX];

    int exit = 0;
    int numbopt;
    int option1before = 0;
    int option2before = 0;
    int i = 0;
    int k;
    int j = 0;
    int numcategories;
    int error = 0;
    int numgp = 0;
    int finished = 0;

    float racerstime[7];




    //Check if we have all arguments
    if(checkarguments(argc)== 0){
        printf("\nError. The program should have 4 arguments\n");
    }
    else {
        //Open parts file
        partsfile = fopen(argv[1], "r");
        if (NULL == partsfile) {
            printf("\nError. An error occurred during the processing of the files.\n");
        } else {
            //Load all categories and parts
            category = loadparts(partsfile, &numcategories,&error);
            //Open the GP file
            gpfile = fopen(argv[2], "r");
            if (NULL == gpfile) {
                printf("\nError. An error occurred during the processing of the files.\n");
                fclose(partsfile);
            } else {
                //Creates list
                gplist = SORTEDLIST_create();
                //Adds to list
                gplist = storeGP(gplist,gpfile,&error,&config,&numgp);
                //Creates a dynamic structure based on numgp
                gpscores = (SortedGp*) malloc(sizeof(SortedGp)*numgp);
                //Creates the leaderboards
                leaderBoards = createLeaderboards(numgp);
                //Open racers file
                racersfile = fopen(argv[3], "rb");
                if (NULL == racersfile) {
                    printf("\nError. An error occurred during the processing of the files.\n");
                    fclose(partsfile);
                    fclose(gpfile);
                } else {
                    //Store racers info
                    racers = loadRacers(racersfile,&error);
                    //Open base file
                    basefile = fopen(argv[4], "rb");
                    if (NULL == basefile) {
                        printf("\nError. An error occurred during the processing of the files.\n");
                        fclose(partsfile);
                        fclose(gpfile);
                        fclose(racersfile);
                    } else {
                        //Use base file data
                        baseLoad(basefile,racers,&error);
                        if(error==0){
                            //Welcome message
                            printf("Welcome to LS Racing !\n\n");
                            do {
                                //Procedure to show  the menu
                                showMenu(instruction);
                                if (strcmp(instruction, "exit") == 0) {
                                    exit = 1;
                                    printf("\nSee you soon!");
                                } else {
                                    numbopt = atoi(instruction);

                                    switch (numbopt) {

                                        case 1:
                                            if (option1before == 0) {
                                                printf("\nDriver name?");
                                                fgets(racer.drivername, MAX, stdin);
                                                racer.drivername[strlen(racer.drivername) - 1] = '\0';

                                                printf("Team name?");
                                                fgets(racer.teamname, MAX, stdin);
                                                racer.teamname[strlen(racer.teamname) - 1] = '\0';

                                                //Scanning for a Driver number
                                                printf("Driver number?");
                                                scanf("%s", stringtoint);
                                                scanf("%c", &aux);

                                                //We convert the string into a number
                                                racer.drivernumb = atoi(stringtoint);

                                                //We will enter the loop if the number is lower than 1 or higher that 99 or its an invalid input
                                                while (racer.drivernumb < 1 || racer.drivernumb > 99) {
                                                    //It will keep printing this error until you enter a valid input.
                                                    printf("\nError , the number has to be an integer between 1 and 99\n\n");
                                                    printf("Driver number?");
                                                    //Scan for the number as string
                                                    scanf("%s", stringtoint);
                                                    scanf("%c", &aux);

                                                    //Converting string into a number with the function atoi()
                                                    racer.drivernumb = atoi(stringtoint);

                                                }
                                                //Filling rest of information of drivers checking them with a function implemented
                                                racer.reflexes = datacheck("Reflexes?",
                                                                           "\nError , the reflexes has to be an integer between 0 and 10, inclusive.\n\n");

                                                racer.physicalcond = datacheck("Physical Condition?",
                                                                               "\nError , the physical condition has to be an integer between 0 and 10, inclusive.\n\n");

                                                racer.temperament = datacheck("Temperament?",
                                                                              "\nError , the temperament has to be an integer between 0 and 10, inclusive.\n\n");

                                                racer.tiremanagement = datacheck("Tire management?",
                                                                                 "\nError , the tire management has to be an integer between 0 and 10, inclusive.\n\n");

                                                //We change this flag to indicate we alredy configured the basic stats of the racer and so you wont have to do it again.
                                                option1before++;
                                            }

                                            printf("\nLoading Configurator... \n\n");


                                            LS_allegro_init(1380, 720, "Configurator");
                                            configWindow(category,numcategories,&config);
                                            LS_allegro_exit();
                                            //Function that returns a struct of Carconfig type that will include the total stats of the car as well as the names of all the parts.
                                            config = carStats(&config, category, i, numcategories);
                                            break;
                                        case 2:
                                            //We check if you already configured the car, if not you will have to do so at least once.
                                            if(!option1before){
                                                printf("\nError. You have to configure the car before doing the race.\n\n");

                                            }
                                            else {
                                                //We check if there are no more Grand Prix to do and show an error if you alredy did all
                                                if (NULL == gplist.head->next) {
                                                    printf("\nYou've alredy finished the season.\n\n");
                                                }
                                                else {
                                                    //Go to next GP
                                                    SORTEDLIST_nextGP(&gplist);

                                                    //Display GP Starting Text
                                                    gpStart(&gplist);

                                                    //Procedure to represent the traffic lights window and all its functionalities
                                                    trafficLights();

                                                    //Start race simulation
                                                    simRace(racers, &gplist,&config, &racer);

                                                    //Function that returns a list with the standings
                                                    gpscores[j] = storeScores(&config,racerstime,racers,j,&racer,gpscores[j]);

                                                    //Shows a window with the final position of our driver
                                                    showPos(j,gpscores[j],racer);

                                                    //We add the standings to the leaderboards and order them
                                                    addToleaderboards(leaderBoards,j,gpscores[j],&gplist);
                                                    j++;
                                                    //If we alredy did all the GPs we will create the end of season leaderboard
                                                    if(j == numgp){
                                                        //Creates the end of season leaderboard
                                                        finalScore(leaderBoards,j);
                                                    }
                                                    //We change this value to know we started the season
                                                    option2before = 1;
                                                    //Next GP in the list
                                                    SORTEDLIST_next(&gplist);
                                                }

                                            }
                                            printf("\n");
                                            break;
                                        case 3:
                                            //Check if we have done at least one GP before
                                            if(option2before == 0){
                                                //If we havent done any we go back to the menu
                                                printf("\nThe season hasn't started yet.\n\n");
                                            }else{
                                                //If we at least did one we open the leaderboards
                                                showLeaderboards(leaderBoards, j, numgp);
                                            }
                                            printf("\n");

                                            break;
                                        case 4:
                                            //We check if we have finished the season
                                            if(j!=numgp){
                                                //If we havent we end program and return to menu
                                                printf("\nYou haven't finished the season\n");
                                            }
                                            else{
                                                //If we have we generate a log with the standings
                                                generateLog(leaderBoards,numgp);
                                                //We change this flag to know if we have finished everything
                                                finished = 1;
                                            }
                                            break;



                                    }

                                    if (numbopt < 1 || numbopt > 4) {
                                        printf("\nError. Option is not valid.\n\n");
                                    }
                                }

                            } while (!exit);
                        }
                    }
                }
            }
            //Close files opened
            fclose(partsfile);
            fclose(gpfile);
            fclose(basefile);
            fclose(racersfile);
        }
    }
    //If we have arrived to last option and succesfully completed everything we can proceed to free the memory
    if(finished == 1){
        //Procedure that will free the memory
        freeMem(category,racers,leaderBoards,gpscores,numcategories);
    }

    return 0;
}






