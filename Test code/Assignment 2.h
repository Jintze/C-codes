/*
 * This program reads text file into a linked list,
 * then based on some rule to make the change 
 * from English to Euroglish,
 * for example, from 'th' to z.
 */

/* 
 *  * Assignment #2
 * File:   Assignment 2.h
 * Author: Jinzhe
 * Created on October 17, 2018, 9:03 AM
 */

#ifndef ASSIGNMENT_2_H
#define ASSIGNMENT_2_H

#endif /* ASSIGNMENT_2_H */

/*
 * Read file and create linked list.
 */
node *createLink();

/*
 * Replace all “c” with “s” if followed the characters “e”, “I” 
 * or “y”; with “k” otherwise.
 */
void firstYear(node *head);

/*
 * Replace all instances of “ph” with the character “f”.
 */
void secondYear(node *head);

/*
 * Remove one “e” from the end of words, which end in e, and 
 * are more than three characters long.
 * 
 * Change all double letters to a single letter. 
 * Did not remove double spacing.
 * 
 * When a word ends in “ed”, remove “e”, change that to“d”.
 */
void thirdYear(node *head);

/*
 * Replace“th” with “z”.
 * Replace“w” with “v”.
 * Remove the “o” in “ou”.
 * Remove the “a” in “ea”.
 */
void forthYear(node *head);

/*
 * Build a linked list, set a pointer of *head, 
 * read file using createLink(), 
 * then go through every year to make the change from English to Euroglish.
 */
int main();

