/*******************************************************

		Configuration du programme
		Saisir les données ici et
		recompiler pour les appliquer

*******************************************************/


/**
 * @file        conf.h
 * @rogram      Fley
 * @brief       Configuration values
 * @description There is all configurables values of the program
 * @date        1/2014
 * @licence     Beerware (rev 42)
 * @author      Jerome GRARD
 */







/*   Avaiable colors 	*

        COLOR_BLACK   0
        COLOR_RED     1
        COLOR_GREEN   2
        COLOR_YELLOW  3
        COLOR_BLUE    4
        COLOR_MAGENTA 5
        COLOR_CYAN    6
        COLOR_WHITE   7
**			*/




#ifndef CONFIG_H
#define CONFIG_H


/* Some constants */
#define DIMENTION_IMAGE_MAX_HAUTEUR	50
#define DIMENTION_IMAGE_MAX_LARGEUR	80

#define	TIME_FOR_A_LOOP			300

/* Colors of lines (Bottom and Top) */
#define COLOR_LINE_BG_BOTTOM  	COLOR_RED
#define COLOR_LINE_BG_TOP 	COLOR_BLUE
#define COLOR_LINE_FG_BOTTOM	COLOR_BLACK
#define COLOR_LINE_FG_TOP	COLOR_BLACK


/* Colors of element in a single matrix */
#define COLOR_ELEMENT_FG	COLOR_BLACK
#define GRAPHIC_MODE		0		/* 1 background is colored 0 background id black and letter is colored */

typedef enum
{
	enumNoir = 	3,
	enumRouge =	4,
	enumVert =	5,
	enumJaune =	6,
	/* 7 is reserved don't use it ! */
	enumBleu = 	8,
	enumMagenta =	9,
	enumCyan =	10,
	enumBlanc =	11
}g_enumJeuxDeCouleursDispo;

#define	DEBUG_T1	{mvprintw(1, 1, "/%d/", 314);refresh();getch();}
#define	DEBUG_T2	{mvprintw(1, 1, "/%d/", 235);refresh();getch();}


#endif
