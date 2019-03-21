/*
 * This program reads text file into a linked list,
 * then based on some rule to make the change 
 * from English to Euroglish,
 * for example, from 'th' to z.
 */

/* 
 * Assignment #2
 * File:   main.c
 * Author: Jinzhe
 * Created on October 8, 2018, 12:23 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Define node.
 */
typedef struct node{
    char data;
    struct node *next;
}node;

/*
 * Read file and create linked list.
 */
node *createLink(){
    node *head = (node*)malloc(sizeof(node));
    char c;//"c" is every characters in text file.
    node *node1;
    node *node2;
    node1 = node2 = head;
    
    //Open the file.
    FILE *file;
    file = fopen("C:/Users/Jinzhe/Desktop/test1.txt", "r");
    if (file){
        while (fscanf(file, "%c", &c) != EOF){
            node2 = (node*) malloc(sizeof(node));
            node2 -> data = c;
            node1 -> next = node2;
            node1 = node2;
        }//End of while, which put every char into linked list.
        node1 -> next = NULL;
        return head;
        fclose(file);
    }//if
    else printf("Can not find the file!");//Prompt that open file failed.
}//End createLink

/*
 * Replace all “c” with “s” if followed the characters “e”, “I” 
 * or “y”; with “k” otherwise.
 */
void firstYear(node *head){
    node *node1 = head -> next; 
    while(node1 -> next){
        if(node1 -> data == 'C'){
            if(node1 -> next -> data == 'e'){
                node1 -> data = 's';
            }//if(c -> s)
            else if (node1 -> next -> data == 'I'){
                node1 -> data = 'S';
            }//else if((c -> s))
            else if (node1 -> next -> data == 'y'){
                node1 -> data = 's';
            }//else if((c -> s))
            else node1 -> data = 'K';
        }//if(deal with upper case of c.)
        if(node1 -> data == 'c'){
            if(node1 -> next -> data == 'e'){
                node1 -> data = 's';
            }//if(c -> s)
            else if (node1 -> next -> data == 'I'){
                node1 -> data = 's';
            }//else if((c -> s))
            else if (node1 -> next -> data == 'y'){
                node1 -> data = 's';
            }//else if((c -> s))
            else node1 -> data = 'k';
        }//if(c -> k)
        node1 = node1 -> next;
    }//while
}//firstYear

/*
 * Replace all instances of “ph” with the character “f”.
 */
void secondYear(node *head){
    node *node1 = head -> next; 
    while(node1 -> next){
        if (node1 -> data == 'p'){
            if(node1 -> next ->data == 'h'){
                node1 -> data = 'f';
                node1 -> next = node1 -> next ->next;
                
            }//if
        }////if(ph -> f)
        node1 = node1 -> next;
    }//while
}//secondYear

/*
 * Remove one “e” from the end of words, which end in e, and 
 * are more than three characters long.
 * 
 * Change all double letters to a single letter. 
 * Did not remove double spacing.
 * 
 * When a word ends in “ed”, remove “e”, change that to“d”.
 */
void thirdYear(node *head){
    node *node1 = head -> next;
    while(node1 -> next -> next){
        if(node1 -> data == 'e' && node1 -> next -> data == 39||46||32){
            node1 -> next == node1 -> next -> next;
            
        }////if(remove e if it is the end of a word)
        if(node1 -> data == node1 -> next -> data && node1 -> data != 10){
            node1 -> next = node1 -> next -> next;
            
        }//if(change double letters to a single letter)
        if (node1 -> data == 'e' && node1 -> next ->data == 'd'){
            if(node1 -> next -> next ->data == 32||10){
                node1 -> data = 'd';
                node1 -> next = node1 -> next ->next;
                
            }//if
        }//if(When a word ends in “ed”, change that to just “d”.)
        node1 = node1 -> next;
    }//while
}//thirdYear

/*
 * Replace“th” with “z”.
 * Replace“w” with “v”.
 * Remove the “o” in “ou”.
 * Remove the “a” in “ea”.
 */
void forthYear(node *head){
    node *node1 = head -> next; 
    while(node1 -> next -> next){
        if (node1 -> data == 't' || 'T'){
                if(node1 -> next -> data == 'h'){
                    if(node1 -> data == 't'){
                        node1 -> data = 'z';
                        node1 -> next = node1 -> next ->next;
                    }//if
                    if(node1 -> data == 'T'){
                        node1 -> data = 'Z';
                        node1 -> next = node1 -> next ->next;
                    }//if
                }//if
        }//if(th -> z)
        if(node1 -> data == 87){
                node1 -> data = 86;
        }//if(W -> V)
        if(node1 -> data == 119){
            node1 -> data = 118;
        }//if(w -> v)
        if (node1 -> data == 'o' || 'O'){
                if(node1 -> next -> data == 'U'){
                    if(node1 -> data == 'o'){
                        node1 -> data = 'u';
                        node1 -> next = node1 -> next ->next;
                    }//if
                    else if(node1 -> data == 'O'){
                        node1 -> data = 'U';
                        node1 -> next = node1 -> next ->next;
                    }//if
                }//if
                if(node1 -> next -> data == 'u'){
                    if(node1 -> data == 'o'){
                        node1 -> data = 'u';
                        node1 -> next = node1 -> next ->next;
                    }//if
                    else if(node1 -> data == 'O'){
                        node1 -> data = 'U';
                        node1 -> next = node1 -> next ->next;
                    }//if
                }//if
        }//if(ou -> u)
        if(node1 -> data == 'e'&& node1 -> next ->data == 'a'){
                node1 -> next = node1 -> next ->next;
        }//if(ea -> e)
        printf("%c", node1 -> data);
        node1 = node1 -> next;
    }//while
}//forthYear

/*
 * Build a linked list, set a pointer of *head, 
 * read file using createLink(), 
 * then go through every year to make the change from English to Euroglish.
 */
int main() {
    node *head;
    head = createLink();
    firstYear(head);
    secondYear(head);
    thirdYear(head);
    forthYear(head);
    return (0);
}

