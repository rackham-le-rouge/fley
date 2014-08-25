/**
 * @file        drawing.c
 * @rogram      Fley
 * @brief       Drawing method of the program
 * @description In this file, there is all of the drawing methods of the program (using ncurses).
 * @date        1/2014
 * @licence     Beerware (rev 42)
 * @author      Jerome GRARD
 */




#include <ncurses.h>                    /* ncurses.h includes stdio.h */
#include <string.h>
#include "conf.h"
#include "drawing.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>




/** @brief Blues lines - Top and bottom of the screen */
void initBar()
{
        int row,col,i;                          /* to store the number of rows and */
        getmaxyx(stdscr,row,col);               /* get the number of rows and columns */
        start_color();                          /* start color mode */
        init_pair(1, COLOR_BLACK, COLOR_LINE_BG_BOTTOM);   /* référence des couleurs */
        attron(COLOR_PAIR(1));
        /* Bottom line */
        for(i = 0; i<col ; i++)
                mvprintw(row-1,i," ");
        /* Top line */
        attroff(COLOR_PAIR(1));
        init_pair(2, COLOR_BLACK, COLOR_LINE_BG_TOP);   /* référence des couleurs */
        attron(COLOR_PAIR(2));

        for(i = 0; i<col ; i++)
                mvprintw(0,i," ");

        attroff(COLOR_PAIR(2));
}







/** @brief Text of the top line
  * @param s : String at the top of the screen
  */

void topText(char* s)
{
        start_color();                          /* start color mode */
        attron(COLOR_PAIR(2));
        mvprintw(0,0,"%s", s);
        attroff(COLOR_PAIR(2));
}





/** @brief Disable the two lines */
void disableBar()
{
        start_color();                          /* start color mode */
        init_pair(1, COLOR_BLACK, COLOR_BLACK);   /* référence des couleurs */

        init_pair(2, COLOR_BLACK, COLOR_BLACK);   /* référence des couleurs */
}









/** @brief Text of the bottom line
  * @param s : String at the bottom of the screen */
void botText(char* s)
{
        int row,col;                            /* to store the number of rows and */
        getmaxyx(stdscr,row,col);               /* get the number of rows and columns */
        start_color();                          /* start color mode */
        attron(COLOR_PAIR(1));
        mvprintw(row-1,0,"%s", s);

        attroff(COLOR_PAIR(1));
	col++;
}




/** @brief Draw an element on the screen
  * @param x : x position of the character
  * @param y : y position of the character
  * @param c : character to draw
  * @param color : color code. Defined in conf.h
  */
int drawElement(int x, int y, char c, int color)
{
        int row,col;                            /* to store the number of rows and */
        getmaxyx(stdscr,row,col);               /* get the number of rows and columns */

	/* Graphical binding */
	if(x>col) return -1;
	if(y>row) return -1;

        start_color();                          /* start color mode */
        attron(COLOR_PAIR(color));

	/* Draw the element */
        mvprintw(y,x,"%c", c);

	attroff(COLOR_PAIR(color));
	return 0;
}


/** @brief Initialisation of the colors */
void initColor()
{
	start_color();

#ifdef GRAPHIC_MODE
        init_pair(enumNoir, COLOR_BLACK, COLOR_BLACK);
        init_pair(enumRouge, COLOR_BLACK, COLOR_RED);
        init_pair(enumVert, COLOR_BLACK, COLOR_GREEN);
        init_pair(enumJaune, COLOR_BLACK, COLOR_YELLOW);
        init_pair(enumBleu, COLOR_BLACK, COLOR_BLUE);
        init_pair(enumMagenta, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(enumCyan, COLOR_BLACK, COLOR_CYAN);
        init_pair(enumBlanc, COLOR_BLACK, COLOR_WHITE);
#else
        init_pair(enumNoir, COLOR_BLACK, COLOR_BLACK);
        init_pair(enumRouge, COLOR_RED, COLOR_BLACK);
        init_pair(enumVert, COLOR_GREEN, COLOR_BLACK);
        init_pair(enumJaune, COLOR_YELLOW, COLOR_BLACK);
        init_pair(enumBleu, COLOR_BLUE, COLOR_BLACK);
        init_pair(enumMagenta, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(enumCyan, COLOR_CYAN, COLOR_BLACK);
        init_pair(enumBlanc, COLOR_WHITE, COLOR_BLACK);
#endif
}



/** @brief Draw the intro panel
  * @param row : Number of rows in the screen
  * @param col : Number of columns in the screen
  */
void drawIntro(int row, int col)
{
        start_color();                          /* start color mode */
        init_pair(7, COLOR_YELLOW, COLOR_BLACK);   /* référence des couleurs */
        attron(COLOR_PAIR(7));

	row = (row - 30)/2;

	drawCenter("F.L.E.Y", col, row++);row++;

	drawCenter("+-----------------+", col, row++);
	drawCenter("| F.ley           |", col, row++);
	drawCenter("| L.oad           |", col, row++);
	drawCenter("| E.verything for |", col, row++);
	drawCenter("| Y.ou            |", col, row++);
	drawCenter("+-----------------+", col, row++);row+=2;
	drawCenter("It's also the name of my stupid cat...", col, row++);row+=2;


	drawCenter("                 ______                 ", col, row++);
	drawCenter("                /     /\\                ", col, row++);
	drawCenter("               /     /##\\               ", col, row++);
	drawCenter("              /     /####\\              ", col, row++);
	drawCenter("             /     /######\\             ", col, row++);
	drawCenter("            /     /########\\            ", col, row++);
	drawCenter("           /     /##########\\           ", col, row++);
	drawCenter("          /     /#####/\\#####\\          ", col, row++);
	drawCenter("         /     /#####/++\\#####\\         ", col, row++);
	drawCenter("        /     /#####/++++\\#####\\        ", col, row++);
	drawCenter("       /     /#####/\\+++++\\#####\\       ", col, row++);
	drawCenter("      /     /#####/  \\+++++\\#####\\      ", col, row++);
	drawCenter("     /     /#####/    \\+++++\\#####\\     ", col, row++);
	drawCenter("    /     /#####/      \\+++++\\#####\\    ", col, row++);
	drawCenter("   /     /#####/        \\+++++\\#####\\   ", col, row++);
	drawCenter("  /     /#####/__________\\+++++\\#####\\  ", col, row++);
	drawCenter(" /                        \\+++++\\#####\\ ", col, row++);
	drawCenter("/__________________________\\+++++\\####/ ", col, row++);
	drawCenter("\\+++++++++++++++++++++++++++++++++\\##/  ", col, row++);
	drawCenter(" \\+++++++++++++++++++++++++++++++++\\/   ", col, row++);
	drawCenter("  ``````````````````````````````````    ", col, row++);

        attroff(COLOR_PAIR(7));

	topText("Free, simple, open-source and hightly configurable drawing program for linux shell - Beerware licence");

	refresh();getch();
        init_pair(7, COLOR_BLACK, COLOR_BLACK);   /* référence des couleurs */


	usleep(10000);
}




/** @brief Draw str to the center of the screen
  * @param str : String to write in the center of the screen
  * @param col : Column in the screen (the width)
  * @param row : The line to write */
int drawCenter(char* str, int col, int row)
{
	/* si on met -1 en col ou en row, il prendra comme valeur la première valeur non nulle qui
	 lui a été donnée. */
	static int backupCol = 0;
	static int backupRow = 0;

	if(col == -1) col=backupCol;
	if(row == -1) row=backupRow;

        mvprintw(row, (col - strlen(str))/2, "%s", str);
	return row;
}



/** @brief this is actually the main function of this program. This function display pictures in the right order at the
           right moment
    @param p_iLargeur : Width of the screen
    @param p_iHauteur : Height of the screen
    @param p_cImage : Pictures matrix, loaded bu io.c. There is all pictures to display
    @param p_iTempsDesImages : In this matrix there is the displaying time of each pictures
    @param p_iNombretotalImage : How many images to draw
    */
void boucleAffichageImage(int p_iLargeur, int p_iHauteur, char** p_cImage, int* p_iTempsDesImages, int p_iNombreTotalImage)
{
	/* Dans cette boucle les images vont défiler les unes a la suite des autres de sorte
	   a donner une impression de mouvement */

	int l_iLargeur, l_iHauteur;
	int l_iImageEnCours = 0;
	int l_iPositionY = 1;
	int l_iPremiereImage = 0;
	int l_iNumeroDeTour = 0;
	char l_cCaractere = '\0';
	char l_bResterDansLaBoucle = 1;
	char l_bAfficherDate = 1;

        int row,col;                            /* to store the number of rows and */
        getmaxyx(stdscr,row,col);               /* get the number of rows and columns */

	g_enumJeuxDeCouleursDispo l_enumCouleurDeLaMatrice;

	topText("Free, simple, open-source and hightly configurable drawing program for linux shell");
	botText("Q, q or ESC to quit - D or d to disable these information bars");


	while(l_bResterDansLaBoucle)
	{
		l_iPositionY = (row - p_iHauteur)/2;

		for(l_iHauteur = l_iImageEnCours*p_iHauteur; l_iHauteur < (l_iImageEnCours + 1)*p_iHauteur ; l_iHauteur++)
		{
			for(l_iLargeur = 0; l_iLargeur < p_iLargeur ; l_iLargeur++)
			{
				switch(p_cImage[l_iHauteur][l_iLargeur])
				{
					case 'D':	l_enumCouleurDeLaMatrice =	enumNoir; break;
					case 'R':	l_enumCouleurDeLaMatrice =	enumRouge; break;
					case 'G':	l_enumCouleurDeLaMatrice =	enumVert; break;
					case 'Y':	l_enumCouleurDeLaMatrice =	enumJaune; break;
					case 'B':	l_enumCouleurDeLaMatrice =	enumBleu; break;
					case 'M':	l_enumCouleurDeLaMatrice =	enumMagenta; break;
					case 'C':	l_enumCouleurDeLaMatrice =	enumCyan; break;
					case 'W':	l_enumCouleurDeLaMatrice =	enumBlanc; break;
					case ' ':	l_enumCouleurDeLaMatrice =	enumNoir; break;
					default:	l_enumCouleurDeLaMatrice =	enumNoir; break;
				}
				/*if(l_iLargeur<col && l_iHauteur<row) */
				drawElement(l_iLargeur + (col - p_iLargeur)/2 , l_iPositionY, ' ', l_enumCouleurDeLaMatrice);
			}
			l_iPositionY++;
		}

		if(l_iImageEnCours + 1 >= p_iNombreTotalImage)
		{
			l_iImageEnCours = l_iPremiereImage;
		}
		else
		{
			if(p_iTempsDesImages[l_iImageEnCours + 1] == p_iTempsDesImages[l_iImageEnCours])
			{
				l_iImageEnCours++;
			}
			else
			{
				if(p_iTempsDesImages[l_iImageEnCours + 1] < l_iNumeroDeTour)
				{
					l_iImageEnCours++;
					l_iPremiereImage = l_iImageEnCours;
				}
				else
				{
					l_iImageEnCours = l_iPremiereImage;
				}
			}
		}

		l_cCaractere = getch();

		switch(l_cCaractere)
		{
			case 27:
			case 'q':
			case 'Q':
				l_bResterDansLaBoucle = 0;
				break;
			case 'T':
			case 't':
				l_bAfficherDate = (l_bAfficherDate == 0) ? 1 : 0;
				break;
			case 'D':
			case 'd':
				disableBar();
				break;
		}

		if(l_bAfficherDate)
			printDate(1);
		else
			printDate(0);

		/* Debug */
		/*mvprintw(1,1,"%d",l_iImageEnCours); */

		refresh();
		usleep(1000*TIME_FOR_A_LOOP);
		l_iNumeroDeTour++;
	}
}


/** @brief Print date at the bottom of the screen
    @param p_bAfficher : used like a boolean value to control whether we have or not to display the time
  */
void printDate(char p_bAfficher)
{
	/* Afficher la date en bas */
	time_t l_timeTimer;
	struct tm y2k;
	static double l_iSecondsDebut = 0;
	double l_iSecondsEnCours;
	int l_iIterateur;
	char l_cChaine[20];
        int row,col;                            /* to store the number of rows and */

        getmaxyx(stdscr,row,col);               /* get the number of rows and columns */

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&l_timeTimer);
	l_iSecondsEnCours = difftime(l_timeTimer,mktime(&y2k));

	if(l_iSecondsDebut == 0) l_iSecondsDebut = l_iSecondsEnCours;

	sprintf(l_cChaine, "%.f", l_iSecondsEnCours - l_iSecondsDebut);

	/* Nettoyer avant chaque écriture
	for(l_iIterateur = 0; l_iIterateur < strlen(l_cChaine) + 2 ; l_iIterateur++)
		mvprintw(row-5, (int)(col/2) - strlen(l_cChaine)/2 - 3 + l_iIterateur  , "    ");

	/* Afficher ou nettoyer l'écran
	if(p_bAfficher) mvprintw(row - 5,(int)(col/2) - strlen(l_cChaine)/2,"%.f",l_iSecondsEnCours - l_iSecondsDebut);
}



