#ifndef MAIN_H
#define MAIN_H


/*

	Header of the main program

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
