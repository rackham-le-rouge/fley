/**
 * @file        io.c
 * @rogram      Fley
 * @brief       I/O functions on files
 * @description In this file, there is all I/O fiunctions on files (loading pictures etc...)
 * @date        1/2014
 * @licence     Beerware (rev 42)
 * @author      Jerome GRARD
 */




#include "conf.h"



extern char g_cFile[30];

/** @brief Load from file the number of pictures to display and return it.
  * @param p_iLargeur : Max width of a picture
  * @param p_iHauteur : Max height of a picture
  */
int nombreDeFrames(int* p_iLargeur, int* p_iHauteur)
{
	FILE * l_fileFichier;

	int l_iFrames;
	int l_iLargeur;
	char l_cCaractereEnCours;

	l_iFrames = 0;
	l_iLargeur = 0;
	l_cCaractereEnCours = ' ';

 	l_fileFichier = fopen(g_cFile,"r");
	if (l_fileFichier!=NULL)
	{
	    do
	    {
		l_cCaractereEnCours = fgetc(l_fileFichier);

		/*  Tous les cas spéciaux */
		switch(l_cCaractereEnCours)
		{
			case '@':
				break;
			case '#':
				l_iFrames++;
				break;
			case '\n':
				(*p_iHauteur)++;
				if(l_iLargeur > *p_iLargeur) *p_iLargeur = l_iLargeur;
				l_iLargeur = 0;
				/* if(*p_iHauteur > DIMENTION_IMAGE_MAX_HAUTEUR) *p_iHauteur = DIMENTION_IMAGE_MAX_HAUTEUR; */
				if(*p_iLargeur > DIMENTION_IMAGE_MAX_LARGEUR) *p_iLargeur = DIMENTION_IMAGE_MAX_LARGEUR;
				break;
			default:
				l_iLargeur++;
				if(l_iLargeur > DIMENTION_IMAGE_MAX_LARGEUR) l_iLargeur = DIMENTION_IMAGE_MAX_LARGEUR;
		 }
	    }while(l_cCaractereEnCours != '@');

	    fclose (l_fileFichier);
	}
	else
		return -1;
	return l_iFrames;
}



/** @brief Load all pictures from the file
    @param p_cImage : Matrix with all pictures in it.
    @param p_iTempsDeChaqueImage : Matric used to return the displaying time of each picture stored in p_iImage
    */
void chargerImageDuFichier(char** p_cImage, int* p_iTempsDeChaqueImage)
{
	int l_iLargeur = 0;
	int l_iHauteur = 0;
	int l_iImageEnCours = 0;
	int l_iPositionDansBuffer=0;
	char l_cBufferDeNombre[15];
	char l_cCaractereEnCours = ' ';


	FILE * l_fileFichier;
 	l_fileFichier = fopen(g_cFile,"r");
	if (l_fileFichier!=NULL)
	{
	    do
	    {
		l_cCaractereEnCours = fgetc(l_fileFichier);

		/*  Tous les cas spéciaux */
		switch(l_cCaractereEnCours)
		{
			case '@':
				break;
			case '#':

				l_cCaractereEnCours = fgetc(l_fileFichier);
				l_iPositionDansBuffer = 0;

				while(l_cCaractereEnCours != '\n')
				{
					l_cBufferDeNombre[l_iPositionDansBuffer++] = l_cCaractereEnCours;
					l_cBufferDeNombre[l_iPositionDansBuffer] = '\0';

					l_cCaractereEnCours = fgetc(l_fileFichier);
				}
				l_iPositionDansBuffer = 0;
				p_iTempsDeChaqueImage[l_iImageEnCours++] = atoi(l_cBufferDeNombre);

			case '\n':
				l_iHauteur++;
				l_iLargeur = 0;
				break;
			default:
				/*  Dans les cas normaux */
				/* if(l_iHauteur < *p_iHauteur && l_iLargeur < *p_iLargeur) */
				p_cImage[l_iHauteur][l_iLargeur++] = l_cCaractereEnCours;
				break;
		 }
	    }while(l_cCaractereEnCours != '@');

	    fclose (l_fileFichier);
	}
}


/** @brief Function called if the user don't specify a file to load
    */
void askForTheFile(void)
{
	mvprintw(2, 0, "You need the specify a file in the command line");
	mvprintw(3, 0, "Add a second parameter to make this screen disapear.");

	mvprintw(5, 0, "How to create our own picture file :");
	mvprintw(6, 0, "------------------------------------");
	mvprintw(8, 0, "Begin each picture with #number  ; number is the date when the picture is displayed for the");
	mvprintw(9, 0, "first time. If some pictures have the same 'number' they are displayed one after one ; they");
	mvprintw(10, 0, "also need to be one after one in the file. For instance, if the first picture is #0 and the");
	mvprintw(11, 0, "second is #1, the third could not be #0 ; it must be #1 or superior. N.B: the first picture");
	mvprintw(12, 0, "must be #0.");

	mvprintw(14, 0, "The number is linked with the internal loop - counter. The loop counter is incremented after");
	mvprintw(15, 0, "the end of a sequence (display all pictures with the same 'number').");

	mvprintw(17, 0, "In the file, you must use predefined capital letters to create a colored point on the screen");
	mvprintw(18, 0, "like in the example file : picture.fley.");

	mvprintw(20, 0, "/!\\ All pictures need to have the same seize (the seize of the biggest picture in the file)");
	mvprintw(21, 0, "So, remember to leave some empty lines and some spaces at the end of all the lines. A space");
	mvprintw(22, 0, "equals to a black point.");

}
