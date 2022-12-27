/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Stack ADT implemented using linked list
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */
#include "stackAsLinkedList.h"

/** stackPush()
 * @brief - puts an element onto the top of the stack
 * @param stack - a ptr to the stack structure
 * @param element - the character to push onto the stack
 * @pre   - stack before element added
 * @post  - stack one element taller
 */
void stackPush(StackAsLinkedList* stack, double element) {
    appendElementLinkedList(stack, element);
}