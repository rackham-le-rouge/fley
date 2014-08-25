#ifndef DRAWING_H
#define DRAWING_H



/**
 * @file        drawing.h
 * @rogram      Fley
 * @brief       Drawing method of the program
 * @description In this file, there is all of the drawing methods of the program (using ncurses).
 * @date        1/2014
 * @licence     Beerware (rev 42)
 * @author      Jerome GRARD
 */



void initBar();
void disableBar();
void enableBar();
void topText(char*);
void botText(char*);
int drawElement(int, int, char, int);
void initColor();
void drawIntro(int, int);
int drawCenter(char*, int, int);
void boucleAffichageImage(int, int, char**, int*, int);
void printDate(char p_bAfficher);

#endif

