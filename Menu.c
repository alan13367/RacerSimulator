//
// Created by Alan on 6/26/2020.
//

#include "Menu.h"

//Procedure that shows the menu with the option and also get the inputo of the instruction
void showMenu(char* instruction){
    char aux;
    //Prints Menu
    printf("\t1. Configure Car\n");
    printf("\t2. Race\n");
    printf("\t3. See Standings\n");
    printf("\t4. Save Season\n\n");
    printf("Which option do you want to execute ? ");
    //Gets instruction and removes auxiliar \n
    scanf("%s", instruction);
    scanf("%c", &aux);
}

//Function that returns an integer that will tell us
int checkarguments(int argnum){
    int check = 0;
    //Check if all arguments are right, there should be 4 plus the executable of the program 5
    if(argnum == 5){
        //Change the integer to 1 if we found 4 arguments
        check = 1;
    }
    //We will return the integer
    return check;
}

//Function that will have as an output a Dynamic Array with all the parts available for the configuration of the car
Category* loadparts(FILE* file,int* numcategories,int* error){
    //Define variables that are going to be used in the function
    int categoriesnum,i,partnum,k;
    char auxstring[15];
    //Scan for first element
    fgets(auxstring, 25,file);
    //Check if file is empty
    if(feof(file)){
        //Notify that the file is empty
        printf("The parts file is empty.\n");
        //Set error to 1
        *error = 1;
    }else{
        categoriesnum = atoi(auxstring);
        //Change them value of numcategories
        *numcategories = categoriesnum;
        //Create a malloc with size of categoriesnum
        Category* category =(Category*) malloc(sizeof(Category)*categoriesnum);
        //Check error in malloc
        if(NULL == category){
            //Notify if error
            printf("\nAn error occured during the processing of the parts files.\n\n");
            //Change error to 1
            *error = 1;
        } else{
            //We will do this loop as many times as categories we got
            for(i=0;i<categoriesnum;i++){
                //Scan for category name and remove \n
                fgets(category[i].categoryname, 25,file);
                category[i].categoryname[strlen(category[i].categoryname)-1]='\0';
                //Scan for number of parts
                fgets(auxstring, 25,file);
                partnum = atoi(auxstring);
                //Set the number of parts inside de dynamic array
                category[i].numparts = partnum;
                //Create malloc with number of parts
                category[i].part =(struct Part*) malloc(sizeof(struct Part)*partnum);
                //Set the part selected to 0 as th fisrt to show
                category[i].selected = 0;
                //Do this loop as many parts as there are
                for(k=0; k < partnum; k++){
                    //Scan pat name
                    fgets(category[i].part[k].partname, 25,file);
                    category[i].part[k].partname[strlen(category[i].part[k].partname)-1]='\0';
                    //Get speed stat of this part
                    fgets(auxstring, 25,file);
                    category[i].part[k].speed = atoi(auxstring);
                    //Get acceleration stat of this part
                    fgets(auxstring, 25,file);
                    category[i].part[k].acceleration = atoi(auxstring);
                    //Get consumption of this part
                    fgets(auxstring, 25,file);
                    category[i].part[k].consumption = atoi(auxstring);
                    //Get reliability of this part
                    fgets(auxstring, 25,file);
                    category[i].part[k].reliability = atoi(auxstring);
                }
            }




        }

        //Finally we return the dynamic array
        return category;
    }

}

//Function that will return a sorted list with the GP to do on this season
SortedList storeGP(SortedList gplist, FILE* gpfile,int* error,Carconfig* config,int* numgp){
    //Define variables we are going to use in this function
    char auxstring[25];
    int numbgp;
    int i;

    //Scan for number of grandprix we will have
    fgets(auxstring,25,gpfile);
    //Check if file is empty
    if(feof(gpfile)){
        //Notify if file is empty
        printf("\nGrand Prix file is empty.\n");
        //Set error to 1
        *error=1;
    }else{
        //We atoi the string of number of categories into an integer
        numbgp = atoi(auxstring);
        //We changed the value we passed as a pointer to have the number of grandprix
        *numgp = numbgp;
        //We do a malloc inside the config struct of a float pointer to have all the times of our racer stored.
        config->times = (float*) malloc(sizeof(float) * numbgp);

        //Create malloc of the GP we will have
        GP * gp = malloc(sizeof(GP) * numbgp);
        //Check if error when creating malloc
        if(NULL==gp){
            //Notify if there has benn an error
            printf("An error occured during the processing of the GP File.\n\n");
            //Set error to 1
            *error=1;
        }
        else{
            //Do this loop as many times as categories we have
            for(i=0;i<numbgp;i++){
                //Position
                fgets(auxstring,25,gpfile);
                gp[i].position = atoi(auxstring);
                //NameGP
                fgets(gp[i].GpName,25,gpfile);
                gp[i].GpName[strlen(gp[i].GpName)-1]='\0';
                //Appropiate acceleration
                fgets(auxstring,25,gpfile);
                gp[i].appspeed = atoi(auxstring);
                //Appropiate acceleration
                fgets(auxstring,25,gpfile);
                gp[i].appacceleration = atoi(auxstring);
                //Appropiate consumption
                fgets(auxstring,25,gpfile);
                gp[i].appconsumption = atoi(auxstring);
                //Appropiate Reliability
                fgets(auxstring,25,gpfile);
                gp[i].appreliability = atoi(auxstring);
                //Base time
                fgets(auxstring,25,gpfile);
                gp[i].basetime = atof(auxstring);
                gp[i].basetime = gp[i].basetime * 60;
                //Pit Stop Time
                fgets(auxstring,25,gpfile);
                gp[i].pittime = atoi(auxstring);
                //Number pit stops
                fgets(auxstring,25,gpfile);
                gp[i].numpit = atoi(auxstring);

            }
            //We add them to the list sorted by their position
            for(i=0;i<numbgp;i++) {
                SORTEDLIST_sortedAdd(&gplist, gp[i]);
            }

        }
    }
    //We return the list
    return gplist;
}

//Function used to get a dynamic array with the racers information stored from the Racers binary file.
Racers* loadRacers(FILE* file,int* error){
    //We define variables we are going to use
    int numracers = 7;//As long as the file is not empty we will have 7 racers
    int i;


    //Create a malloc of Racers with the number of racers
    Racers* racers = (Racers*) malloc(sizeof(Racers)*numracers);
    //Check if any error
    if(NULL== racers){
        //Notify error
        printf("An error occured during the processing of the Racers File.\n\n");
        //Change error to 1
        *error = 1;
    }
    else{


        fseek(file, 0, SEEK_END); // goto end of file
        //Check if file is empty
        if (ftell(file) == 0){
            //Notify that the file is empty
            printf("\nRacers file is empty.\n");
            //Set error to 1
            *error=1;
        }
        else{
            //Go the the start of the file
            fseek(file, 0, SEEK_SET);
            //Scan the number of racers into the dynamic array
            for(i=0; i<numracers;i++){
                //Read the racers structure
                fread(&racers[i],sizeof(Racers),1,file);
            }
        }
    }
//Return racers dynamic array
return racers;
}

//Procedure that will load the information from the base binary file of the racers cars and will store directly on them.
void baseLoad(FILE* basefile, Racers* racers,int * error){

    //Define variables that are going to be used in the function
    int i;
    int basespeed,baseacc,baseconsu,baserelia;


    fseek(basefile, 0, SEEK_END); // Go to end of file
    //Check if file is empty
    if (ftell(basefile) == 0){
        //Notify that the file is empty
        printf("\nRacers file is empty.\n");
        //Set error to 1
        *error=1;
    }
    else {
        //Set at the start of the file
        fseek(basefile, 0, SEEK_SET);
        //Read for the four integers in the file
        fread(&basespeed, sizeof(int), 1, basefile);
        fread(&baseacc, sizeof(int), 1, basefile);
        fread(&baseconsu, sizeof(int), 1, basefile);
        fread(&baserelia, sizeof(int), 1, basefile);
        //For all 7 racers stored in the dynamic array we will add these stats to their base ones
        for(i=0;i<7;i++){
            //Add them into the four stats
            racers[i].speed += basespeed;
            racers[i].acceleration += baseacc;
            racers[i].consumption += baseconsu;
            racers[i].reliability += baserelia;
        }
    }
}

//Frees all dynamic memory used in the program
void freeMem(Category * category,Racers *racers,LeaderBoards *leaderBoards,SortedGp *gpscores,int numcategories){
    int i,k;

    //Free all dynamic structures used
    for(i=0;i<numcategories;i++){
        for(k=0;k<category[i].numparts;k++){
           free(category[i].part) ;
           category[i].part = NULL;
        }
    }

    //Free memory and set pointers to NULL
    free(category);
    category = NULL;

    free(racers);
    racers = NULL;

    free(leaderBoards);
    leaderBoards = NULL;

    free(gpscores);
    gpscores = NULL;

}