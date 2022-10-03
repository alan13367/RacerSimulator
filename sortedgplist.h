//
// Created by Alan on 7/1/2020.
//

#ifndef P2FINAL_SORTEDGPLIST_H
#define P2FINAL_SORTEDGPLIST_H

#include <stdlib.h>
// Constants to manage the list's error codes.
#define LIST_NO_ERROR 0
#define LIST_ERROR_FULL 1			// Error, the list is full.
#define LIST_ERROR_EMPTY 2			// Error, the list is empty.
#define LIST_ERROR_MALLOC 3			// Error, a malloc failed.
#define LIST_ERROR_END 4			// Error, the POV is at the end.


// Element the list will contain
typedef struct{
    char name[25];
    int drivernumb;
    float time;
    int points;
}ScoreRacers;



typedef ScoreRacers Scores;

typedef struct _Node1 {
    Scores element;
    struct _Node1 * next;
} Node1;


typedef struct {
    int error;			// Error code to keep track of failing operations;
    Node1 * head;	 	// Head/First element or Phantom node;
    Node1 * previous; 	// Previous node before the point of view;
} SortedGp;


// Procedures & Functions


SortedGp SORTEDGP_create ();

void 	SORTEDGP_sortedAdd (SortedGp * list, Scores element);

void SORTEDGP_sortedAddPoints (SortedGp * list, Scores element);

void sortGPlist(SortedGp * lits);

void 	SORTEDGP_remove (SortedGp * list);


Scores SORTEDGP_get (SortedGp * list);


int 	SORTEDGP_isEmpty (SortedGp list);


void 	SORTEDGP_goToHead (SortedGp * list);


void 	SORTEDGP_next (SortedGp * list);


int 	SORTEDGP_isAtEnd (SortedGp list);


void 	SORTEDGP_destroy (SortedGp * list);


int		SORTEDGP_getErrorCode (SortedGp list);

void SORTEDGP_nextGP(SortedGp* list);

#endif //P2FINAL_SORTEDGPLIST_H
