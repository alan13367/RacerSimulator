//
// Created by Alan on 7/4/2020.
//

#include "Option4.h"

//Procedure that will generate a log of the standings throught the competition
void generateLog(LeaderBoards* leaderboards,int numgp){
    //Create a file
    FILE* log;

    //Create indexes
    int i,k;

    //Create file and open file
    log = fopen("log_season.txt","w");

    //Check if there was a problem creating file
    if(NULL == log){
        //Notify the user
        printf("\nThere was a problem creating the log file.\n");
    }
    else{
        //Loop through the GPs
        for(i=0;i<numgp;i++){
            //Write in the file the name
            fprintf(log,"%s Ranking\n",leaderboards[i].gpname);
            //Loop through drivers
            for(k=0;k<8;k++){
                //Write each driver stats in that gp
                fprintf(log,"%d. %s with %.f seconds. Points: %d \n",k+1,leaderboards[i].racerspos[k].name,leaderboards[i].racerspos[k].time,leaderboards[i].racerspos[k].points);

            }
        }
        //Write the end of season ranking
        fprintf(log,"End of Season Ranking\n");
        //Loop through the drivers
        for(k=0;k<8;k++){
            //Write their final scores of the competition
            fprintf(log,"%d. %s  #%d with Points: %d \n",k+1,leaderboards[numgp].racerspos[k].name,leaderboards[numgp].racerspos[k].drivernumb,leaderboards[numgp].racerspos[k].points);
        }
    }
    //Notify to the user the log has been created succesfully
    printf("\nLog succesfully created.\n");

    //Close the file
    fclose(log);
}