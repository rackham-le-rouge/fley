#ifndef MAIN_H
#define MAIN_H


/**
 * @file        main.h
 * @rogram      Fley
 * @brief       Main file - Start and stop functions
 * @description First and last functions executed by the program are here and the squeleton of the program too.
 * @date        1/2014
 * @licence     Beerware (rev 42)
 * @author      Jerome GRARD
 */



void killTheApp(void);
extern void initBar();
extern void topText(char*);
extern void botText(char*);
extern int drawElement(int, int, char, int);
extern void initColor();
extern void drawIntro(int, int);
extern void chargerImageDuFichier(int*, int*, char**, int*);
extern void boucleAffichageImage(int, int, char**, int*, int);
extern int nombreDeFrames(int*, int*);
extern void askForTheFile(char*);
extern void disableBar();

#endif
