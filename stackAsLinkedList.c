/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Stack ADT implemented using linked list
 * Purpose: Stack ADT library - LIFO
 * Coded entirely by chatgpt
 * ===========================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackAsLinkedList.h"
#include "listAsLinkedList.h"  // Include the LinkedList implementation

// Push an element onto the stack
void stackPush(StackAsLinkedList* stack, double element) {
    if (!stack) return;
    appendElementLinkedList(stack, element);  // Use the append function of the LinkedList
}

// Pop an element off the stack
double stackPop(StackAsLinkedList* stack) {
    if (!stack || stackIsEmpty(stack)) {
        return -1;  // Return -1 if the stack is empty or invalid
    }

    // Retrieve and remove the top element of the stack
    double topElement = getElementLinkedList(stack, stackSize(stack) - 1);
    deleteElementLinkedList(stack, stackSize(stack) - 1);  // Remove the last element (top of stack)
    return topElement;
}

// Check if the stack is empty
bool stackIsEmpty(StackAsLinkedList* stack) {
    if (!stack) return true;
    return lengthOfLinkedList(stack) == 0;
}

// Check if the stack is full
bool stackIsFull(StackAsLinkedList* stack) {
    // Since we're using a linked list, it's theoretically never full
    return false;
}

// Initialize the stack (create an empty stack)
StackAsLinkedList* stackInit() {
    return createLinkedList();  // Create and return an empty linked list (stack)
}

// Delete the stack, freeing all memory used
void deleteStack(StackAsLinkedList* stack) {
    deleteLinkedList(stack);  // Free memory used by the stack (linked list)
}

// Peek at the top element of the stack without removing it
double stackPeek(StackAsLinkedList* stack) {
    if (!stack || stackIsEmpty(stack)) {
        return -1;  // Return -1 if the stack is empty
    }

    return getElementLinkedList(stack, stackSize(stack) - 1);  // Return the top element of the stack
}

// Get the size of the stack
int stackSize(StackAsLinkedList* stack) {
    if (!stack) return 0;
    return lengthOfLinkedList(stack);  // The size of the stack is just the size of the linked list
}

// Print the elements in the stack
void stackPrint(StackAsLinkedList* stack) {
    if (!stack) return;
    printLinkedList(stack);  // Print the linked list (stack)
}


