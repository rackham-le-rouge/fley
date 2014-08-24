#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "conf.h"
#include "main.h"

char rev[] = "0.0";
char ver[] = "1.0";


int g_iLigne	=		0;
int g_iColonne =		0;
char g_cFile[30] =		"picture.fley";

// Main
int main(int argc, char** argv)
{
	int l_iTmp=0;
	int l_iHauteur = 0;
	int l_iLargeur = 0;
	char** l_cImage;
	int* l_iTempsDeChaqueImage;
	int l_iNombreDeFrames = 0;
	int l_iLargeurEnCoursDeTraitement = 0;
	int l_iHauteurEnCoursDeTraitement = 0;

	// Start the graphic mode
	initscr();

	// Hide the cursor
	curs_set(0);

	char l_cBuffer[250];
	char l_cBuffer2[250];
	noecho();
	cbreak();
	sprintf(l_cBuffer, "Fley - Ver %s - Rev %s - Dev by Geo", ver, rev);

	// Initialisation of some graphical elements
	initColor();
        getmaxyx(stdscr,g_iLigne,g_iColonne);
	initBar();

	// Intro drawing
	if(argc < 3)
	{
		drawIntro(g_iLigne, g_iColonne);
		initBar();
	}

	// If there is no file, print a message and quit
	if(argc > 1) strcpy(g_cFile, argv[1]);
	if(argc == 1)
	{
		askForTheFile(argv[1]);
		getch();
		endwin();
		exit(EXIT_FAILURE);
	}

	// Don't ask Enter key in order to complete a getch()
	nodelay(stdscr, 1);


	// Right message on the bottom bar
	for(l_iTmp=0; l_iTmp < g_iColonne - strlen(l_cBuffer) ; l_iTmp++)
	{
		l_cBuffer2[l_iTmp] = ' ';
		l_cBuffer2[l_iTmp+1] = '\0';
	}
	strcat(l_cBuffer2, l_cBuffer);
	botText(l_cBuffer2);

	// Initialisation of memory
	l_iNombreDeFrames = nombreDeFrames(&l_iLargeur, &l_iHauteur);
	if(l_iNombreDeFrames == -1)
	{
		// Something wrong with the file
		endwin();
		exit(EXIT_FAILURE);
	}

	l_iTempsDeChaqueImage = (int*)malloc(l_iNombreDeFrames*sizeof(int));
	l_cImage = (char**)malloc(l_iHauteur*l_iNombreDeFrames*sizeof(char*));
	for(l_iHauteurEnCoursDeTraitement = 0; l_iHauteurEnCoursDeTraitement<l_iHauteur; l_iHauteurEnCoursDeTraitement++)
	{
		l_cImage[l_iHauteurEnCoursDeTraitement] = (char*)malloc(l_iLargeur*sizeof(char));
		for(l_iLargeurEnCoursDeTraitement = 0; l_iLargeurEnCoursDeTraitement<l_iLargeur; l_iLargeurEnCoursDeTraitement++)
			l_cImage[l_iHauteurEnCoursDeTraitement][l_iLargeurEnCoursDeTraitement] = ' ';
	}


	// Load pictures from file
	chargerImageDuFichier(&l_iLargeur, &l_iHauteur, l_cImage, l_iTempsDeChaqueImage);


	if(argc > 2) disableBar();

	// Animate the picture
	boucleAffichageImage(l_iLargeur, l_iHauteur/l_iNombreDeFrames, l_cImage, l_iTempsDeChaqueImage, l_iNombreDeFrames);

	// Stop the program and leave the graphic mode ! Very important !
	endwin();

	exit(EXIT_SUCCESS);
	return 0;
}
