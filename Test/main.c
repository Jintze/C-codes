/* 
 * A rock, paper, scissors game, which has two players.
 * One of the two players is user, the other player is computer.
 * Computer will make its random choice.
 * The game have a total of 10 rounds.
 * Who wins more round is the winner.
 * 
 * File:   main.c
 * Author: Jinzhe
 * Created on October 1, 2018, 12:46 PM
 */
/*
* File: main.c
* Author: rosanna
*
* Created on October 11, 2018, 12:12 PM
*/
#include <stdio.h>
#include <stdlib.h>
//Make my node data type
typedef struct node{
 char data;
 struct node *next;
} node;
//Print a linked list
void printList(node *start){
 node *location = start;

 while(location != NULL){
 printf("%c", location->data);
 location = location->next;
 }//while
 printf("\n");
}
//Testing
int main() {
 node x; //static node (allocated pre-run time)
 x.data = 'C';
 x.next = NULL;
 printf("X data: %c next: %p\n", x.data, x.next);

 node *start = NULL; //dynamic node (allocated at run time)
 start = malloc(sizeof(node));
 start->data = 'A';
 start->next = &x; //Link the static dude into the list (at end)
 printf("Start data: %c next: %p\n", start->data, start->next);
 printf("X data: %c next: %p\n", start->next->data,
 start->next->next);

 printf("Testing printList\n");
 printList(start);

 return (EXIT_SUCCESS);
}