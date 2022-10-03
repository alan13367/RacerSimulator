
// Define guard to prevent compilation problems if we add the module more
//  than once in the project.
#ifndef _SORTEDLIST_H_
#define _SORTEDLIST_H_

// Libraries
#include <stdlib.h>					// To use dynamic memory.

// Constants to manage the list's error codes.
#define LIST_NO_ERROR 0
#define LIST_ERROR_FULL 1			// Error, the list is full.
#define LIST_ERROR_EMPTY 2			// Error, the list is empty.
#define LIST_ERROR_MALLOC 3			// Error, a malloc failed.
#define LIST_ERROR_END 4			// Error, the POV is at the end.


//Element to be stored in the list
typedef struct{
    int position;
    char GpName[25];
    int appspeed;
    int appacceleration;
    int appconsumption;
    int appreliability;
    float basetime;
    int pittime;
    int numpit;
}GP;

typedef GP Element;

typedef struct _Node {
	GP element;
	struct _Node * next;
} Node;


typedef struct {
	int error;			// Error code to keep track of failing operations;
	Node * head;	 	// Head/First element or Phantom node;
	Node * previous; 	// Previous node before the point of view;
} SortedList;


// Procedures & Functions


SortedList SORTEDLIST_create ();

void 	SORTEDLIST_sortedAdd (SortedList * list, Element element);

void LINKEDLIST_add (SortedList * list, Element element);

void sortlist(SortedList * lits);

void 	SORTEDLIST_remove (SortedList * list);


GP SORTEDLIST_get (SortedList * list);


int 	SORTEDLIST_isEmpty (SortedList list);


void 	SORTEDLIST_goToHead (SortedList * list);


void 	SORTEDLIST_next (SortedList * list);


int 	SORTEDLIST_isAtEnd (SortedList list);


void 	SORTEDLIST_destroy (SortedList * list);


int		SORTEDLIST_getErrorCode (SortedList list);


void SORTEDLIST_nextGP(SortedList* list);

#endif

