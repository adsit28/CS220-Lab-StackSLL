/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Implementation of Linked List Library
 * Purpose: List ADT as linked list
 * entirely coded by chatgpt
 * ===========================================================
 */

// Use your solution from previous labs

#include <stdio.h>
#include <stdlib.h>
#include "listAsLinkedList.h"

// Create a new empty linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    return list;
}

// Delete the linked list and free all memory used
void deleteLinkedList(LinkedList* list) {
    if (list == NULL) return;
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Append a new element to the end of the linked list
void appendElementLinkedList(LinkedList* list, double element) {
    if (list == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->numberOfElements++;
}

// Get the size of the linked list
int lengthOfLinkedList(LinkedList* list) {
    if (list == NULL) return 0;
    return list->numberOfElements;
}

// Print the linked list to the console
void printLinkedList(LinkedList* list) {
    if (list == NULL) return;
    Node* current = list->head;
    while (current != NULL) {
        printf("%f -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Retrieve the element at a given position in the linked list
double getElementLinkedList(LinkedList* list, int position) {
    if (list == NULL || position < 0 || position >= list->numberOfElements) {
        return -1;  // Error, invalid position
    }

    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->data;
}

// Delete the element at a given position in the linked list
void deleteElementLinkedList(LinkedList* list, int position) {
    if (list == NULL || position < 0 || position >= list->numberOfElements) {
        return;  // Error, invalid position
    }

    Node* current = list->head;
    Node* previous = NULL;

    // If the element to delete is the head
    if (position == 0) {
        list->head = current->next;
        if (list->head == NULL) {
            list->tail = NULL;  // List became empty
        }
        free(current);
    } else {
        for (int i = 0; i < position; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if (current == list->tail) {
            list->tail = previous;  // Update tail if deleting last element
        }
        free(current);
    }

    list->numberOfElements--;
}

// Insert a new element at a given position in the linked list
void insertElementLinkedList(LinkedList* list, int position, double element) {
    if (list == NULL || position < 0 || position > list->numberOfElements) {
        return;  // Error, invalid position
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;

    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
        if (list->numberOfElements == 0) {
            list->tail = newNode;
        }
    } else {
        Node* current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == NULL) {
            list->tail = newNode;  // Update tail if inserted at the end
        }
    }

    list->numberOfElements++;
}

// Change the value of an element at a given position in the linked list
void changeElementLinkedList(LinkedList* list, int position, double newElement) {
    if (list == NULL || position < 0 || position >= list->numberOfElements) {
        return;  // Error, invalid position
    }

    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    current->data = newElement;
}

// Find the position of a given element in the linked list, if it exists
int findElementLinkedList(LinkedList* list, double element) {
    if (list == NULL) return -1;

    Node* current = list->head;
    int position = 0;

    while (current != NULL) {
        if (current->data == element) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;  // Element not found
}

// Perform an insertion sort on the linked list
void insertSortLinkedList(LinkedList* list) {
    if (list == NULL || list->head == NULL) return;

    Node* sorted = NULL;
    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    list->head = sorted;
    // Update the tail of the list
    Node* temp = list->head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    list->tail = temp;
}

// Perform a selection sort on the linked list
void selSortLinkedList(LinkedList* list) {
    if (list == NULL || list->head == NULL) return;

    Node* start = list->head;
    while (start != NULL) {
        Node* min = start; // Assume the current node is the smallest
        Node* current = start->next;

        while (current != NULL) {
            if (current->data < min->data) {
                min = current; // Found a new minimum
            }
            current = current->next; // Move to the next node
        }

        // Swap the data of start and min nodes if min is not start
        if (min != start) {
            double temp = start->data;
            start->data = min->data;
            min->data = temp;
        }

        start = start->next; // Move to the next node for the next iteration
    }
}
