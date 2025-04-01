#include "Joueur.h"																	// Inclusion Fichier En-t�te 'Joueur.h' //
#include "GL\glut.h"																// Inclusion Fichier En-t�te Bib. GLUT //



extern int PosC;																	// Coordonn�es du Joueur issues du Programme Principal //
extern int PosL;




void Joueur::DessinerJoueur()														// Fonction de Dessin Joueur //
{

	
		

		glPushMatrix();																// On Sauvegarde la Matrice active avant Translation //

		glTranslated(PosC+0.5, PosL+0.5, 0.0);										// Fonction GLUT de translation du Joueur //
		glColor3d(0.0, 0.0, 1.0);													// Couleur Bleue //
		glutSolidSphere(0.4, 12, 12);												// Dessin du Corps //
		glColor3d(0.0, 0.0, 0.0);													// Couleur Noire //
		glutSolidSphere(0.2, 12, 12);												// Dessin de la t�te //

		

		glPopMatrix();																// On Restaure la Matrice active apr�s translation //

		


	



}