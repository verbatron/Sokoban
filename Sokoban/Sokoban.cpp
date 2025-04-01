																	//        JEU SOKOBAN        //
																	//       En C++  Natif	     //
																	//      API Glut (OPENGL)    //
																	// Chargement sur 2 Niveaux  //
																	//      12 Fevrier 2019		 //


#include <stdlib.h>																	// Inclusion Bib. Standard Langage C //
#include <stdio.h>																	// Inclusion Bib. Standard E/S //
#include <Windows.h>																// Inclusion Bib. Windows //
#include <fstream>																	// Inclusion Pour les Fichiers externes (chargement Niveaux) //
#include <mmsystem.h>																// Pour Jouer les Sons avec PlaySound() //
#include "Joueur.h"																	// Fichier En-t�te 'Joueur.h' //
#include "Caisses.h"																// Fichier En-t�te 'Caisses.h' //
#include "GL/freeglut.h"
#include "GL/freeglut_ext.h"
#include "GL/freeglut_std.h"
#include "GL/glut.h"																// Inclusion Bib. GLUT //


using namespace std;																// Utilisation Espace de Noms Standard langage C //


int ValidCaisse1 = 0;	
int ValidCaisse2 = 0;
int ValidCaisse3 = 0;
int ValidCaisse4 = 0;																// Variables de Validation Caisses Pos�es dans Cases Victoire //
int ValidCaisse5 = 0;
int ValidCaisse6 = 0;
int ValidDeplac = 0;																// Pour arr�ter le d�placement Joueur � la fin du jeu (0->D�placement 1->Arr�t) //
int ValidVictoire = 0;																// Pour valider la Victoire du Niveau 1 en Appuyant sur 'F3' //
int ChoixNiveau = 1;																// Variable Choix du Niveau en Cours //
int VariableTexte;																	// Variable Choix Texte � Afficher //
int NbColonnes;																		// Variable Nombre Colonnes //
int NbLignes;																		// Variable Nombre Lignes //
int PosC;																			
int PosL;																			// Coordonn�es Joueur //
int ColCaisse1, LigCaisse1;
int ColCaisse2, LigCaisse2;
int ColCaisse3, LigCaisse3;
int ColCaisse4, LigCaisse4;															// Coordonn�es Caisses � Pousser //
int ColCaisse5, LigCaisse5;
int ColCaisse6, LigCaisse6;
int ColCaisseV1, LigCaisseV1;
int ColCaisseV2, LigCaisseV2;
int ColCaisseV3, LigCaisseV3;														// Coordonn�es Caisses Pos�es (Caisses Victoire) //
int ColCaisseV4, LigCaisseV4;
int ColCaisseV5, LigCaisseV5;
int ColCaisseV6, LigCaisseV6;
char **Matrice;																		// Tableau � 2 Dimensions de caract�res allou� dans le TAS par des Pointeurs //
void GestionNiveau();																// Fonction Gestion Chargement Niveau en Cours //
void SceneAff();																	// Fonction affichage Scene //
void SceneRedim(int x,int y);														// Fonction Redimensionnement Fen�tre //
void SceneClavierSpecial(int key, int x, int y);									// Fonction Gestion Clavier //
void OuvrirNiveau(char* nom_fichier);												// Fonction Ouverture Fichier Externe //
void DessinerScene();																// Fonction Dessin Scene //
void DessinerCaissesScene();														// Fonction Dessin Caisses //
void GestionGauche();																// Fonction Gestion D�placement Gauche //
void GestionDroite();																// Fonction Gestion D�placement Droite //
void GestionHaut();																	// Fonction Gestion D�placement Haut //
void GestionBas();																	// Fonction Gestion D�placement Bas //
void TestVictoire();																// Fonction Test Victoire //
void AffTexte();																	// Fonction Affichage Texte dans Fen�tre //
void LibererMemoire();																// Fonction pour lib�rer la m�moire (TAS) //
Joueur MonJoueur;																	// Objet Global Classe Joueur //
Caisses LaCaisse1;
Caisses LaCaisse2;
Caisses LaCaisse3;
Caisses LaCaisse4;									
Caisses LaCaisse5;
Caisses LaCaisse6;																	// Objets Globaux Classe Caisses //
Caisses LaCaisseV1;
Caisses LaCaisseV2;
Caisses LaCaisseV3;
Caisses LaCaisseV4;
Caisses LaCaisseV5;
Caisses LaCaisseV6;





void main(int argc, char *argv[])													// Fonction Principale du Programme //
{

	FreeConsole();																	// On Masque la Console //

	NbColonnes = 0;																	// On R�initialise le Nombre Colonnes & Lignes //
	NbLignes = 0;
	Matrice = NULL;																	// On R�initialise le Tableau � 2 Dimensions //

	glutInit(&argc, argv);															// Fonction Initialisation GLUT //
	glutInitWindowPosition(645,285);												// Fonction GLUT Position Fen�tre � L'Ecran //
	glutInitWindowSize(630, 630);													// Fonction GLUT Taille Fen�tre Jeu //
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);									// Affichage Mode 3 Couleurs Analogique & Double Tampon Affichage //
	glutCreateWindow("Sokoban");													// Fonction GLUT Cr�ation Fen�tre Jeu avec son Titre // 
	glutDisplayFunc(SceneAff);														// Fonction GLUT Affichage //
	glutReshapeFunc(SceneRedim);													// Fonction GLUT Redimensionnement Fen�tre //
	glutSpecialFunc(SceneClavierSpecial);											// Fonction GLUT Gestion Clavier //


	
	GestionNiveau();																// Fonction Gestion Niveau //


	glutMainLoop();																	// Fonction GLUT Boucle Principale dans la Fonction main() //

}



void GestionNiveau()
{

	switch (ChoixNiveau)															// On Commute sur le Choix du Niveau en Cours //
	{
	case 1:																			// Cas Niveau 1 //
	{
		OuvrirNiveau("Datas\\niveau1.txt");											// On Charge le Niveau 1 //
		VariableTexte = 1;															// Pour Pouvoir Afficher le Texte du Niveau 1 //
		break;
	}

	case 2:																			// Cas Niveau 2 //
	{
		OuvrirNiveau("Datas\\niveau2.txt");											// On Charge le Niveau 2 //
		VariableTexte = 2;															// Pour Pouvoir Afficher le Texte du Niveau 2 //
		break;
	}

	}

}



void OuvrirNiveau(char* nom_fichier)
{

	ifstream fichier;																// On lance la Gestion Fichier //
	fichier.open(nom_fichier);														// On ouvre le Fichier //

	fichier >> NbColonnes;															// On r�cup�re le Nombre de Colonnes et de Lignes //
	fichier >> NbLignes;

	Matrice = new char*[NbColonnes];
	for (int i = 0; i < NbColonnes; i++)
																					// Allocation en Espace M�moire adressable (TAS) de la Matrice avec des Pointeurs //
		Matrice[i] = new char[NbLignes];

	for (int i = 0; i < NbColonnes; i++)
		for (int j = 0; j < NbLignes; j++)
		{
			Matrice[i][j] = '0';													// On initialise le Contenu � 0 //
		}

	for (int j = 0; j < NbLignes; j++)
		for (int i = 0; i < NbColonnes; i++)

		{
			fichier >> Matrice[i][j];												// On r�cup�re le Contenu de chaque Colonne et Lignes � partir du Fichier pour la Matrice //
		}

	for (int i = 0; i < NbColonnes; i++)
		for (int j = 0; j < NbLignes; j++)
		{
			switch (Matrice[i][j])													// On Commute sur le Tableau //
			{
			case '7':																// Si C'est le Joueur //
			{
				PosC = i;															// On Affecte ses Coordonn�es //
				PosL = j;
				break;
			}
			case '1':																// Si C'est la Caisse 1 //
			{
				ColCaisse1 = i;														// On affecte ses Coordonn�es //
				LigCaisse1 = j;
				break;
			}
			case '2':																// Ainsi de Suite //
			{
				ColCaisse2 = i;
				LigCaisse2 = j;
				break;
			}
			case '3':
			{
				ColCaisse3 = i;
				LigCaisse3 = j;
				break;
			}
			case '4':
			{
				ColCaisse4 = i;
				LigCaisse4 = j;
				break;
			}
			case '5':
			{
				ColCaisse5 = i;
				LigCaisse5 = j;
				break;
			}
			case '6':
			{
				ColCaisse6 = i;
				LigCaisse6 = j;
				break;
			}

			}

		}
		
	fichier.close();																// Fermeture Fichier //

}





void LibererMemoire()
{

	for (int i = 0; i < NbColonnes; i++)											// On supprimme la Matrice allou�e //
	
		delete[] Matrice[i];
			delete[] Matrice;														// De Mani�re Manuelle avec Instruction delete //

}



void SceneAff()
{

	glClearColor(1.0, 1.0, 1.0, 1.0);												// On Efface L'Ecran avec la Couleur Blanche //
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);														// Matrice Active -> Vue de Mod�les //


	DessinerScene();																// On execute la Fonction Dessin Scene // 

	DessinerCaissesScene();															// Fonction Dessin Caisses //

	MonJoueur.DessinerJoueur();														// On Dessine le Joueur //

	AffTexte();																		// On Affiche le Texte dans la Fen�tre //

	TestVictoire();																	// On Teste la Victoire //

	glutSwapBuffers();																// Inversion Tampons Affichage //


}



void DessinerScene()
{

	for (int i = 0; i < NbColonnes; i++)
		for (int j = 0; j < NbLignes; j++)
		{
			if (Matrice[i][j] == 's')												// Si C'est le Sol Ext�rieur //
			{
				glColor3d(0.0, 1.0, 0.0);											// Couleur Verte //
				glBegin(GL_QUADS);													// D�but Dessin Carr� //
				glVertex2d(i, j);
				glVertex2d(i, j + 1.0);
				glVertex2d(i + 1.0, j + 1.0);										// On Dessine un Carr� Vert //
				glVertex2d(i + 1.0, j);
				glEnd();															// Fin Dessin //

				glPushMatrix();														// On sauvegarde la Matrice active avant translation //
				glTranslated(i + 0.5, j + 0.5, 0.0);								// On se remet au centre //
				glColor3d(0.0, 0.0, 0.0);											// Couleur Noire //
				glutWireCube(0.1);													// On Dessine un petit Cube pour chaque Carr� Vert //
				glPopMatrix();														// On Restaure la Matrice active apr�s translation //


			}

		}

	for (int i = 0; i < NbColonnes; i++)
		for (int j = 0; j < NbLignes; j++)
		{
			if (Matrice[i][j] == '9')												// Si C'est le Mur de la Scene de Jeu //
			{
				glColor3d(0.5, 0.5, 0.5);											// Couleur Grise // 
				glBegin(GL_QUADS);													// D�but Dessin Carr� //
				glVertex2d(i, j);
				glVertex2d(i, j + 1.0);
				glVertex2d(i + 1.0, j + 1.0);										// On Dessine le Carr� Gris //
				glVertex2d(i + 1.0, j);
				glEnd();															// Fin Dessin //

				glFlush();															// On Ach�ve toute Commandes // 
			}

		}

	for (int i = 0; i < NbColonnes; i++)
		for (int j = 0; j < NbLignes; j++)
		{

			if ((Matrice[i][j] == '0') || (Matrice[i][j] == '7') || (Matrice[i][j] == '1') || (Matrice[i][j] == '2') || (Matrice[i][j] == '3') || (Matrice[i][j] == '4') || (Matrice[i][j] == '5') || (Matrice[i][j] == '6'))
			{																		// Si C'est le Sol de la Scene Int�rieure //
				glPushMatrix();														// On Dessine un Cube Blanc avec un Contour Noir //
				glColor3d(0.0, 0.0, 0.0);
				glTranslated(i + 0.5, j + 0.5, 0.0);
				glutWireCube(1.0);
				glPopMatrix();
			}
		}


	switch (ChoixNiveau)															// On Commute sur le Niveau en Cours //
	{

	case 1:																			// Cas Niveau 1 //
	{
		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(17.5, 11.5, 0.0);												// On Affiche les cases Victoire au Bon endroit //
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();

		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(18.5, 11.5, 0.0);												// Ainsi de Suite //
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();


		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(17.5, 12.5, 0.0);
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();

		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(18.5, 12.5, 0.0);
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();

		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(17.5, 13.5, 0.0);
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();

		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(18.5, 13.5, 0.0);
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();

		break;
	}

	case 2:																			// De m�me pour Niveau 2 //
	{
		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(13.5, 10.5, 0.0);
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();

		glPushMatrix();
		glColor3d(0.0, 0.0, 0.0);
		glTranslated(13.5, 12.5, 0.0);
		glutWireCube(1.0);
		glColor3d(0.0, 0.0, 1.0);
		glutWireCube(0.3);

		glPopMatrix();

		break;

	}

	}


}



void DessinerCaissesScene()
{

	switch (ChoixNiveau)															// On Commute sur le Niveau en Cours //
	{

	case 1:																			// Cas Niveau 1 //
	{


		LaCaisse1.DessinerCaisse1();
		LaCaisse2.DessinerCaisse2();
		LaCaisse3.DessinerCaisse3();
		LaCaisse4.DessinerCaisse4();												// Dessin des 6 Caisses //
		LaCaisse5.DessinerCaisse5();
		LaCaisse6.DessinerCaisse6();
		break;

	}

	case 2:																			// Cas Niveau 2 //
	{
		LaCaisse1.DessinerCaisse1();
		LaCaisse2.DessinerCaisse2();												// Dessin des 2 Caisses //
		break;
	}

	}


}



void SceneRedim(int x, int y)
{

	glViewport(0, 0, x, y);															// Fonction ViewPort (perspective)
	glMatrixMode(GL_PROJECTION);													// Matrice de Projection
	glLoadIdentity();																// On charge Identit� Matrice //
	gluOrtho2D(0.0,(double)NbColonnes,(double)NbLignes,0.0);						// Fonction de redimensionnement GLUT //



}



void SceneClavierSpecial(int key, int x, int y)
{

	switch (key)																	// On Commute sur la Touche Appuy�e //
	{

	case GLUT_KEY_F10:																// Appui sur 'F10' //	
	{
		LibererMemoire();															// On Lib�re la M�moire et On Quitte le Jeu en renvoyant la valeur 0 a Windows //
		exit(0);
		break;
	}

	case GLUT_KEY_F1:																// Appui sur 'F1' //
	{
		PlaySound(TEXT("Datas\\FondSonore.wav"),NULL, SND_LOOP | SND_ASYNC);		// On Joue le Fond Sonore en Boucle //
		break;
	}

	case GLUT_KEY_F2:																// Appui sur 'F2' //
	{		
		PlaySound(NULL, NULL, NULL);												// On arr�te le Son //
		break;
	}

	case GLUT_KEY_LEFT:																// Appui Touche Gauche //
	{
		if (ValidDeplac == 0)														// Si le D�placement Joueur est Autoris� (Cours de Jeu) //
		{
			GestionGauche();														// On Execute la Fonction D�placement Gauche //
		}
		glutPostRedisplay();														// On rafraichit Affichage //
		break;
	}

	case GLUT_KEY_RIGHT:															// Appui Touche Droite (M�me Principe) //
	{
		if (ValidDeplac == 0)
		{
			GestionDroite();
		}
		glutPostRedisplay();
		break;
	}

	case GLUT_KEY_UP:																// M�me Principe //
	{
		if (ValidDeplac == 0)
		{
			GestionHaut();
		}
		glutPostRedisplay();
		break;
	}

	case GLUT_KEY_DOWN:																// M�me Principe //
	{
		if (ValidDeplac == 0)
		{
			GestionBas();
		}
		glutPostRedisplay();
		break;
	}

	case GLUT_KEY_F3:																// Si On Appuie sur 'F3' � la Fin du Niveau 1 //
	{
		ValidVictoire = 1;															// On Valide la Victoire du Niveau 1 //
		break;
	}

	}



}


void GestionGauche()
{
	if (ChoixNiveau == 1)															// Cas Niveau 1 //
	{
		switch (Matrice[PosC - 1][PosL])											// On Commute sur la Position dans la Scene de la Colonne � Gauche de la Position du Joueur //
		{
		case '0':																	// Si C'est le Sol Int�rieur Scene ou Case D�part Joueur ou Cases Victoire //
		case '7':
		case '8':
		{
			PosC--;																	// On D�place le Joueur d'une Colonne vers la Gauche //
			break;
		}

		case '1':																	// Si la Colonne a Gauche du Joueur est la Caisse1 //
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{																		// Si la Colonne a Gauche de la Caisse1 est Vide //
				Matrice[PosC - 1][PosL] = '0';										// On Affecte les Nouvelles Entr�es dans Tableau //
				Matrice[ColCaisse1-1][LigCaisse1] = '1';
				ColCaisse1--;
				PosC--;																// On D�place la Caisse1 et le Joueur d'une Position � Gauche //
				break;
			}
		}

		case '2':																	// M�me Code (ainsi de suite)
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{
				Matrice[PosC - 1][PosL] = '0';
				Matrice[ColCaisse2 - 1][LigCaisse2] = '2';
				ColCaisse2--;
				PosC--;
				break;
			}
		}

		case '3':
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{
				Matrice[PosC - 1][PosL] = '0';
				Matrice[ColCaisse3 - 1][LigCaisse3] = '3';
				ColCaisse3--;
				PosC--;
				break;
			}
		}

		case '4':
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{
				Matrice[PosC - 1][PosL] = '0';
				Matrice[ColCaisse4 - 1][LigCaisse4] = '4';
				ColCaisse4--;
				PosC--;
				break;
			}
		}

		case '5':
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{
				Matrice[PosC - 1][PosL] = '0';
				Matrice[ColCaisse5 - 1][LigCaisse5] = '5';
				ColCaisse5--;
				PosC--;
				break;
			}
		}

		case '6':
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{
				Matrice[PosC - 1][PosL] = '0';
				Matrice[ColCaisse6 - 1][LigCaisse6] = '6';
				ColCaisse6--;
				PosC--;
				break;
			}
		}
		}
	}

	if (ChoixNiveau == 2)															// M�me principe de Code pour le Niveau 2 // 
	{
		switch (Matrice[PosC - 1][PosL])
		{
		case '0':
		case '7':
		case '8':
		{
			PosC--;
			break;
		}

		case '1':
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{
				Matrice[PosC - 1][PosL] = '0';
				Matrice[ColCaisse1 - 1][LigCaisse1] = '1';
				ColCaisse1--;
				PosC--;
				break;
			}
		}

		case '2':
		{
			if ((Matrice[PosC - 2][PosL] == '0') || (Matrice[PosC - 2][PosL] == '7') || (Matrice[PosC - 2][PosL] == '8'))
			{
				Matrice[PosC - 1][PosL] = '0';
				Matrice[ColCaisse2 - 1][LigCaisse2] = '2';
				ColCaisse2--;
				PosC--;
				break;
			}
		}


		}

	}

}



void GestionDroite()																// M�me Principe de Code que la Gestion D�placement Gauche mais c'est pour la Droite //
{
	if (ChoixNiveau == 1)
	{
		switch (Matrice[PosC + 1][PosL])
		{
		case '0':
		case '7':
		case '8':
		{
			PosC++;
			break;
		}

		case '1':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse1 + 1][LigCaisse1] = '1';
				ColCaisse1++;
				PosC++;
				break;
			}
		}

		case '2':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse2 + 1][LigCaisse2] = '2';
				ColCaisse2++;
				PosC++;
				break;
			}
		}

		case '3':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse3 + 1][LigCaisse3] = '3';
				ColCaisse3++;
				PosC++;
				break;
			}
		}

		case '4':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse4 + 1][LigCaisse4] = '4';
				ColCaisse4++;
				PosC++;
				break;
			}
		}

		case '5':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse5 + 1][LigCaisse5] = '5';
				ColCaisse5++;
				PosC++;
				break;
			}
		}

		case '6':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse6 + 1][LigCaisse6] = '6';
				ColCaisse6++;
				PosC++;
				break;
			}
		}
		}
	}

	if (ChoixNiveau == 2)
	{
		switch (Matrice[PosC + 1][PosL])
		{
		case '0':
		case '7':
		case '8':
		{
			PosC++;
			break;
		}

		case '1':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse1 + 1][LigCaisse1] = '1';
				ColCaisse1++;
				PosC++;
				break;
			}
		}

		case '2':
		{
			if ((Matrice[PosC + 2][PosL] == '0') || (Matrice[PosC + 2][PosL] == '7') || (Matrice[PosC + 2][PosL] == '8'))
			{
				Matrice[PosC + 1][PosL] = '0';
				Matrice[ColCaisse2 + 1][LigCaisse2] = '2';
				ColCaisse2++;
				PosC++;
				break;
			}
		}

		}

	}
}



void GestionHaut()																	// M�me Principe de Code que la Gestion D�placement Gauche mais c'est pour le Haut //
{
	if (ChoixNiveau == 1)
	{
		switch (Matrice[PosC][PosL-1])
		{
		case '0':
		case '7':
		case '8':
		{
			PosL--;
			break;
		}

		case '1':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL-1] = '0';
				Matrice[ColCaisse1][LigCaisse1-1] = '1';
				LigCaisse1--;
				PosL--;
				break;
			}
		}

		case '2':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL - 1] = '0';
				Matrice[ColCaisse2][LigCaisse2 - 1] = '2';
				LigCaisse2--;
				PosL--;
				break;
			}
		}

		case '3':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL - 1] = '0';
				Matrice[ColCaisse3][LigCaisse3 - 1] = '3';
				LigCaisse3--;
				PosL--;
				break;
			}
		}

		case '4':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL - 1] = '0';
				Matrice[ColCaisse4][LigCaisse4 - 1] = '4';
				LigCaisse4--;
				PosL--;
				break;
			}
		}

		case '5':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL - 1] = '0';
				Matrice[ColCaisse5][LigCaisse5 - 1] = '5';
				LigCaisse5--;
				PosL--;
				break;
			}
		}

		case '6':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL - 1] = '0';
				Matrice[ColCaisse6][LigCaisse6 - 1] = '6';
				LigCaisse6--;
				PosL--;
				break;
			}
		}
		}
	}


	if (ChoixNiveau == 2)
	{
		switch (Matrice[PosC][PosL - 1])
		{
		case '0':
		case '7':
		case '8':
		{
			PosL--;
			break;
		}

		case '1':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL - 1] = '0';
				Matrice[ColCaisse1][LigCaisse1 - 1] = '1';
				LigCaisse1--;
				PosL--;
				break;
			}
		}

		case '2':
		{
			if ((Matrice[PosC][PosL - 2] == '0') || (Matrice[PosC][PosL - 2] == '7') || (Matrice[PosC][PosL - 2] == '8'))
			{
				Matrice[PosC][PosL - 1] = '0';
				Matrice[ColCaisse2][LigCaisse2 - 1] = '2';
				LigCaisse2--;
				PosL--;
				break;
			}
		}


		}

	}

}



void GestionBas()																	// M�me Principe de Code que la Gestion D�placement Gauche mais c'est pour le Bas //
{
	if (ChoixNiveau == 1)
	{
		switch (Matrice[PosC][PosL + 1])
		{
		case '0':
		case '7':
		case '8':
		{
			PosL++;
			break;
		}

		case '1':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse1][LigCaisse1 + 1] = '1';
				LigCaisse1++;
				PosL++;
				break;
			}
		}

		case '2':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse2][LigCaisse2 + 1] = '2';
				LigCaisse2++;
				PosL++;
				break;
			}
		}

		case '3':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse3][LigCaisse3 + 1] = '3';
				LigCaisse3++;
				PosL++;
				break;
			}
		}

		case '4':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse4][LigCaisse4 + 1] = '4';
				LigCaisse4++;
				PosL++;
				break;
			}
		}

		case '5':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse5][LigCaisse5 + 1] = '5';
				LigCaisse5++;
				PosL++;
				break;
			}
		}

		case '6':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse6][LigCaisse6 + 1] = '6';
				LigCaisse6++;
				PosL++;
				break;
			}
		}
		}
	}

	if (ChoixNiveau == 2)
	{
		switch (Matrice[PosC][PosL + 1])
		{
		case '0':
		case '7':
		case '8':
		{
			PosL++;
			break;
		}

		case '1':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse1][LigCaisse1 + 1] = '1';
				LigCaisse1++;
				PosL++;
				break;
			}
		}

		case '2':
		{
			if ((Matrice[PosC][PosL + 2] == '0') || (Matrice[PosC][PosL + 2] == '7') || (Matrice[PosC][PosL + 2] == '8'))
			{
				Matrice[PosC][PosL + 1] = '0';
				Matrice[ColCaisse2][LigCaisse2 + 1] = '2';
				LigCaisse2++;
				PosL++;
				break;
			}
		}

		}

	}

}



void AffTexte()
{
	switch (VariableTexte)
	{

	case 1:
	{
		glMatrixMode(GL_PROJECTION);												// Matrice de Projection //
		glPushMatrix();																// On Sauvegarde la Matrice//
		glLoadIdentity();															// On charge la Matrice � son Identit� //
		gluOrtho2D(0.0, 630, 630, 0.0);												// On d�finit le Minimum / Maximum de la Fenetre //

		glMatrixMode(GL_MODELVIEW);													// Matrice de Vue de Mod�le //
		glPushMatrix();																// On Sauvegarde la Matrice //
		glLoadIdentity();															// On charge la Matrice � son Identit� //

		glColor3d(0.0, 0.0, 0.0);													// Texte en Noir //

		glRasterPos2i(250,68);														// A la Position Horizontale : 180 et Verticale : 60 //


		string s = "NIVEAU 1";														// Texte � afficher //

		void * font = GLUT_BITMAP_TIMES_ROMAN_24;									// On d�finit le Type de Police et sa Taille //

		for (string::iterator i = s.begin(); i != s.end(); ++i)
		{
			char c = *i;															// Fonction GLUT affichage Texte //
			glutBitmapCharacter(font, c);
		}

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();																// On restaure la Matrice de Vue de Mod�le // 

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();																// On restaure la Matrice de Projection //	

		break;
	}

	case 2:
	{
		glMatrixMode(GL_PROJECTION);												// Matrice de Projection //
		glPushMatrix();																// On Sauvegarde la Matrice//
		glLoadIdentity();															// On charge la Matrice � son Identit� //
		gluOrtho2D(0.0, 630, 630, 0.0);												// On d�finit le Minimum / Maximum de la Fenetre //

		glMatrixMode(GL_MODELVIEW);													// Matrice de Vue de Mod�le //
		glPushMatrix();																// On Sauvegarde la Matrice //
		glLoadIdentity();															// On charge la Matrice � son Identit� //

		glColor3d(0.0, 0.0, 0.0);													// Texte en Noir //

		glRasterPos2i(250, 68);														// A la Position Horizontale : 180 et Verticale : 60 //


		string s = "NIVEAU 2";														// Texte � afficher //

		void * font = GLUT_BITMAP_TIMES_ROMAN_24;									// On d�finit le Type de Police et sa Taille //

		for (string::iterator i = s.begin(); i != s.end(); ++i)
		{
			char c = *i;															// Fonction GLUT affichage Texte //
			glutBitmapCharacter(font, c);
		}

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();																// On restaure la Matrice de Vue de Mod�le // 

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();																// On restaure la Matrice de Projection //	

		break;
	}

	case 3:
	{
		glMatrixMode(GL_PROJECTION);												// Matrice de Projection //
		glPushMatrix();																// On Sauvegarde la Matrice//
		glLoadIdentity();															// On charge la Matrice � son Identit� //
		gluOrtho2D(0.0, 630, 630, 0.0);												// On d�finit le Minimum / Maximum de la Fenetre //

		glMatrixMode(GL_MODELVIEW);													// Matrice de Vue de Mod�le //
		glPushMatrix();																// On Sauvegarde la Matrice //
		glLoadIdentity();															// On charge la Matrice � son Identit� //

		glColor3d(0.0, 0.0, 0.0);													// Texte en Noir //

		glRasterPos2i(250, 580);														// A la Position Horizontale : 180 et Verticale : 60 //


		string s = "VICTOIRE !";														// Texte � afficher //

		void * font = GLUT_BITMAP_TIMES_ROMAN_24;									// On d�finit le Type de Police et sa Taille //

		for (string::iterator i = s.begin(); i != s.end(); ++i)
		{
			char c = *i;															// Fonction GLUT affichage Texte //
			glutBitmapCharacter(font, c);
		}

		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();																// On restaure la Matrice de Vue de Mod�le // 

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();																// On restaure la Matrice de Projection //	

		break;
	}




	}

}








void TestVictoire()
{

	switch (ChoixNiveau)															// On Commute sur le Niveau en Cours // 
	{

	case 1:																			// Cas Niveau 1 //
	{



		if (((ColCaisse1 == 17) && (LigCaisse1 == 11)) ||
			((ColCaisse1 == 18) && (LigCaisse1 == 11)) ||
			((ColCaisse1 == 17) && (LigCaisse1 == 12)) ||							// Si la Caisse1 est sur une des Cases Victoire //
			((ColCaisse1 == 18) && (LigCaisse1 == 12)) ||
			((ColCaisse1 == 17) && (LigCaisse1 == 13)) ||
			((ColCaisse1 == 18) && (LigCaisse1 == 13)))
		{
			ValidCaisse1 = 1;														// Validation Caisse1 //
			ColCaisseV1 = ColCaisse1;												// On Affecte les Coordonn�es de la Caisse1 a la CaisseVictoire1 //
			LigCaisseV1 = LigCaisse1;
			LaCaisseV1.DessinerCaisseV1();											// On Dessine la Caisse Victoire1 //
		}
		else
		{
			ValidCaisse1 = 0;														// Sinon On ne Valide pas la Caisse1 //
		}

		if (((ColCaisse2 == 17) && (LigCaisse2 == 11)) ||
			((ColCaisse2 == 18) && (LigCaisse2 == 11)) ||
			((ColCaisse2 == 17) && (LigCaisse2 == 12)) ||							// M�me Principe de Code mais pour la Caisse2 (ainsi de suite) //
			((ColCaisse2 == 18) && (LigCaisse2 == 12)) ||
			((ColCaisse2 == 17) && (LigCaisse2 == 13)) ||
			((ColCaisse2 == 18) && (LigCaisse2 == 13)))
		{
			ValidCaisse2 = 1;
			ColCaisseV2 = ColCaisse2;
			LigCaisseV2 = LigCaisse2;
			LaCaisseV2.DessinerCaisseV2();
		}
		else
		{
			ValidCaisse2 = 0;
		}

		if (((ColCaisse3 == 17) && (LigCaisse3 == 11)) ||
			((ColCaisse3 == 18) && (LigCaisse3 == 11)) ||
			((ColCaisse3 == 17) && (LigCaisse3 == 12)) ||
			((ColCaisse3 == 18) && (LigCaisse3 == 12)) ||
			((ColCaisse3 == 17) && (LigCaisse3 == 13)) ||
			((ColCaisse3 == 18) && (LigCaisse3 == 13)))
		{
			ValidCaisse3 = 1;
			ColCaisseV3 = ColCaisse3;
			LigCaisseV3 = LigCaisse3;
			LaCaisseV3.DessinerCaisseV3();
		}
		else
		{
			ValidCaisse3 = 0;
		}

		if (((ColCaisse4 == 17) && (LigCaisse4 == 11)) ||
			((ColCaisse4 == 18) && (LigCaisse4 == 11)) ||
			((ColCaisse4 == 17) && (LigCaisse4 == 12)) ||
			((ColCaisse4 == 18) && (LigCaisse4 == 12)) ||
			((ColCaisse4 == 17) && (LigCaisse4 == 13)) ||
			((ColCaisse4 == 18) && (LigCaisse4 == 13)))
		{
			ValidCaisse4 = 1;
			ColCaisseV4 = ColCaisse4;
			LigCaisseV4 = LigCaisse4;
			LaCaisseV4.DessinerCaisseV4();
		}
		else
		{
			ValidCaisse4 = 0;
		}

		if (((ColCaisse5 == 17) && (LigCaisse5 == 11)) ||
			((ColCaisse5 == 18) && (LigCaisse5 == 11)) ||
			((ColCaisse5 == 17) && (LigCaisse5 == 12)) ||
			((ColCaisse5 == 18) && (LigCaisse5 == 12)) ||
			((ColCaisse5 == 17) && (LigCaisse5 == 13)) ||
			((ColCaisse5 == 18) && (LigCaisse5 == 13)))
		{
			
			ColCaisseV5 = ColCaisse5;
			LigCaisseV5 = LigCaisse5;
			LaCaisseV5.DessinerCaisseV5();
			ValidCaisse5 = 1;
		}
		else
		{
			ValidCaisse5 = 0;
		}

		if (((ColCaisse6 == 17) && (LigCaisse6 == 11)) ||
			((ColCaisse6 == 18) && (LigCaisse6 == 11)) ||
			((ColCaisse6 == 17) && (LigCaisse6 == 12)) ||
			((ColCaisse6 == 18) && (LigCaisse6 == 12)) ||
			((ColCaisse6 == 17) && (LigCaisse6 == 13)) ||
			((ColCaisse6 == 18) && (LigCaisse6 == 13)))
		{
			ValidCaisse6 = 1;
			ColCaisseV6 = ColCaisse6;
			LigCaisseV6 = LigCaisse6;
			LaCaisseV6.DessinerCaisseV6();
		}
		else
		{
			ValidCaisse6 = 0;
		}



		if ((ValidVictoire == 1) && (ValidCaisse1 == 1) && (ValidCaisse2 == 1) && (ValidCaisse3 == 1) && (ValidCaisse4 == 1) && (ValidCaisse5 == 1) && (ValidCaisse6 == 1))
		{																			// Si Toutes les Caisses � Pousser sont sur les Cases Victoire //
			ValidVictoire = 0;														// On r�initialise la Variable Validation Victoire //
			PlaySound(NULL, NULL, NULL);											// On Arr�te le Son (Fond Sonore si il est en Cours de Lecture)
			ChoixNiveau = 2;														// On Passe au Niveau 2 //
			GestionNiveau();														// On Ouvre le Niveau 2 //
			DessinerScene();														// On Red�ssine Scene & Caisses //
			DessinerCaissesScene();
			glutPostRedisplay();													// On Rafraichit Affichage //
			PlaySound(TEXT("Datas\\FondSonore.wav"), NULL, SND_LOOP | SND_ASYNC);	// On Relance le Fond Sonore //
		}

		break;

	}


	case 2:																			// Cas Niveau 2 (M�me Principe de Code mais avec 2 Caisses Seulement // 
	{



		if (((ColCaisse1 == 13) && (LigCaisse1 == 10)) ||
			((ColCaisse1 == 13) && (LigCaisse1 == 12)))
		{
			ValidCaisse1 = 1;
			ColCaisseV1 = ColCaisse1;
			LigCaisseV1 = LigCaisse1;
			LaCaisseV1.DessinerCaisseV1();
		}
		else
		{
			ValidCaisse1 = 0;
		}

		if (((ColCaisse2 == 13) && (LigCaisse2 == 10)) ||
			((ColCaisse2 == 13) && (LigCaisse2 == 12)))
		{
			ValidCaisse2 = 1;
			ColCaisseV2 = ColCaisse2;
			LigCaisseV2 = LigCaisse2;
			LaCaisseV2.DessinerCaisseV2();
		}
		else
		{
			ValidCaisse2 = 0;
		}

		if ((ValidCaisse1 == 1) && (ValidCaisse2 == 1))
		{
			PlaySound(NULL, NULL, NULL);											// On Arr�te le Fond Sonore //
			ValidDeplac = 1;														// On Emp�che le Joueur de Bouger //
			glutPostRedisplay();													// On Rafraichit Affichage //
			VariableTexte = 3;														// Variable Texte a Afficher sur 3 (Texte Victoire du Jeu) //
			AffTexte();																// On AFfiche ce Texte //

		}

		break;
	}

	}



}

																					// FIN //