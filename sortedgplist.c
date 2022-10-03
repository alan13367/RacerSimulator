//
// Created by Alan on 7/1/2020.
//

#include "sortedgplist.h"

SortedGp SORTEDGP_create () {
    SortedGp list;

    // Request a Node. This node will be the auxiliary "Phantom" node.
    // The list's head now is the phantom node.
    list.head = (Node1*) malloc(sizeof(Node1));
    if (NULL != list.head) {
        // There is noone after the phantom node, so next is NULL.
        list.head->next = NULL;
        // We set the previous pointer to the phantom node. Now the point
        //  of view is after the last valid element in the list (there are
        //  no valid elements as the list is empty).
        list.previous = list.head;

        // Everything was fine, so we set the error code to NO_ERROR
        list.error = LIST_NO_ERROR;
    }
    else {
        // Could not get dynamic memory for the phantom node, so we set the
        //  error to malloc error code.
        list.error = LIST_ERROR_MALLOC;
    }

    return list;
}



// Auxiliary function from the LinkedList implementetion that will help us
//  implement the sortedAdd function.
// This function is not described in the .H file, so "no-one knows it exists".
void LINKEDLIST_add (SortedGp * list, Scores element) {
    // 1- Create a new node.
    Node1 * new_node = (Node1*) malloc(sizeof(Node1));
    if (new_node != NULL) {
        // 2- Set the element field in the new node.
        new_node->element = element;
        // 3- Set the next field in the new node.
        new_node->next = list->previous->next;
        // 4- Link the new node to the list.
        list->previous->next = new_node;
        // 5- Move the previous pointer.
        list->previous = new_node;
    }
}

void SORTEDGP_sortedAdd (SortedGp * list, Scores element) {
    int found = 0;
    Scores e;

    // We need to know where to place the new element before we can add it
    //  to the list. So the first step would be to go to the first element
    //  and to check all the elements in the list until we find the right
    //  position to place the new element.
    SORTEDGP_goToHead(list);
    // We will stop the loop when we get to the end of the list (we checked
    //  all the elements and we didn't find any place where to set the new
    //  element), or after we found the place where to set the given element.
    while (!SORTEDGP_isAtEnd(*list) && !found) {
        e = SORTEDGP_get(list);
        if (element.time > e.time) {
            SORTEDGP_next(list);
        }
        else {
            found = 1;
        }
    }
    // After finding where to place to new element, we reuse the method
    //  defined in the LinkedList to add the new node with the new
    //  element at the designated position.
    LINKEDLIST_add(list, element);
}
void SORTEDGP_sortedAddPoints (SortedGp * list, Scores element) {
    int found = 0;
    Scores e;

    // We need to know where to place the new element before we can add it
    //  to the list. So the first step would be to go to the first element
    //  and to check all the elements in the list until we find the right
    //  position to place the new element.
    SORTEDGP_goToHead(list);
    // We will stop the loop when we get to the end of the list (we checked
    //  all the elements and we didn't find any place where to set the new
    //  element), or after we found the place where to set the given element.
    while (!SORTEDGP_isAtEnd(*list) && !found) {
        e = SORTEDGP_get(list);
        if (element.points < e.points) {
            SORTEDGP_next(list);
        }
        else {
            found = 1;
        }
    }
    // After finding where to place to new element, we reuse the method
    //  defined in the LinkedList to add the new node with the new
    //  element at the designated position.
    LINKEDLIST_add(list, element);
}

void 	SORTEDGP_remove (SortedGp * list)  {
    Node1 * aux = NULL;
    // We cannot remove an element if the POV is not valid.
    // The POV will not be valid when the previous pointer points to the last
    //  node in the list (there is noone after PREVIOUS).
    if (SORTEDGP_isAtEnd(*list)) {
        list->error = LIST_ERROR_END;
    }
    else {
        // We need to set an auxiliary pointer to point the element we want
        //  to remove (the POV).
        aux = list->previous->next;

        // "Remove" the POV. The element after the PREVIOUS node will be the
        //  element after the POV.
        list->previous->next = list->previous->next->next;

        // Free the POV. Remove the element.
        free(aux);

        // If there are no errors, set error code to NO_ERROR.
        list->error = LIST_NO_ERROR;
    }
}


Scores SORTEDGP_get (SortedGp * list) {
    Scores element;

    // We cannot return an element if the POV is not valid.
    // The POV will not be valid when the previous pointer points to the last
    //  node in the list (there is noone after PREVIOUS).
    if (SORTEDGP_isAtEnd(*list)) {
        list->error = LIST_ERROR_END;
    }
    else {
        // The element to return is the element stored in the POV.
        element = list->previous->next->element;

        // If there are no errors, set error code to NO_ERROR.
        list->error = LIST_NO_ERROR;
    }

    return element;
}



int 	SORTEDGP_isEmpty (SortedGp list)  {
    // The list will be empty if there are no nodes after the phantom node.
    return NULL == list.head->next;
}


void 	SORTEDGP_goToHead (SortedGp * list) {
    // To move the POV to the first element in the list, we need to point
    //  whoever is before the first element. That is the phantom node.
    list->previous = list->head;
}



void 	SORTEDGP_next (SortedGp * list) {
    // We cannot move to the next element if the POV is not valid.
    // The POV will not be valid when the previous pointer points to the last
    //  node in the list (there is noone after PREVIOUS).
    if (SORTEDGP_isAtEnd(*list)) {
        list->error = LIST_ERROR_END;
    }
    else {
        // Move the POV to the next element.
        list->previous = list->previous->next;

        // If there are no errors, set error code to NO_ERROR.
        list->error = LIST_NO_ERROR;
    }
}
//Changes the head for the next element from the head
void SORTEDGP_nextGP(SortedGp * list){
    //Make the previous the head
    list->previous = list->head;
    //Make the next as the head
    list->head = list->head->next;
}

int 	SORTEDGP_isAtEnd (SortedGp list) {
    // To check if the list is at the end (POV after the last element) we
    //  need to check if there is any Node after the previous pointer.
    return NULL == list.previous->next;
}

void 	SORTEDGP_destroy (SortedGp * list) {
    Node1 * aux;
    // While there are still NODEs in the list.
    while (NULL != list->head) {
        // Take the first node.
        aux = list->head;
        // Now the first node is the next node.
        list->head = list->head->next;
        // Free who was the first node;
        free(aux);
    }
    // Set the pointers to NULL (best practice).
    list->head = NULL;
    list->previous = NULL;
}


int		SORTEDGP_getErrorCode (SortedGp list) {
    return list.error;
}

void sortGPlist(SortedGp * list){
    while(!SORTEDGP_isAtEnd(*list)){
        if(list->previous->element.time > list->head->element.time){
            list->head = list->previous;
            list->previous = list->head;
        }
        SORTEDGP_next(list);
    }

}