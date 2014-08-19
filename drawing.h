#ifndef DRAWING_H
#define DRAWING_H


/*

        Header of the graphical part of the program

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

