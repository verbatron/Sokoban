#include "Caisses.h"																// Inclusion Fichier En-tête 'Caisses.h' //
#include "GL\glut.h"																// Inclusion Fichier En-tête Bib. GLUT //


extern int ColCaisse1, LigCaisse1;
extern int ColCaisse2, LigCaisse2;
extern int ColCaisse3, LigCaisse3;
extern int ColCaisse4, LigCaisse4;
extern int ColCaisse5, LigCaisse5;													// Coordonnées des Caisses (Tableau et Victoire) issues du Programme Principal //
extern int ColCaisse6, LigCaisse6;
extern int ColCaisseV1, LigCaisseV1;
extern int ColCaisseV2, LigCaisseV2;
extern int ColCaisseV3, LigCaisseV3;
extern int ColCaisseV4, LigCaisseV4;
extern int ColCaisseV5, LigCaisseV5;
extern int ColCaisseV6, LigCaisseV6;




void Caisses::DessinerCaisse1()														// Fonction de Dessin de la Caisse 1 //
{
	glPushMatrix();																	// On Sauvegarde la Matrice active avant Translation //

	glColor3d(1.0, 0.0, 0.0);														// Couleur Rouge //
	glBegin(GL_QUADS);																// Debut Dessin Carré //
	glVertex2d(ColCaisse1, LigCaisse1);
	glVertex2d(ColCaisse1, LigCaisse1 + 1);											// Les Coordonnées //
	glVertex2d(ColCaisse1 + 1, LigCaisse1 + 1);
	glVertex2d(ColCaisse1 + 1, LigCaisse1);
	glEnd();																		// Fin Dessin //

	glTranslated(ColCaisse1 + 0.5, LigCaisse1 + 0.5, 0.0);							// Fonction GLUT translation du Carré //
	glColor3d(0.0, 0.0, 0.0);														// Couleur Noire //
	glutWireCube(0.7);																// On Dessine un Cube à L'intérieur //

	glPopMatrix();																	// On restaure la Matrice active après Translation //
}


void Caisses::DessinerCaisse2()														// Même Code //
{
	glPushMatrix();

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisse2, LigCaisse2);
	glVertex2d(ColCaisse2, LigCaisse2 + 1);
	glVertex2d(ColCaisse2 + 1, LigCaisse2 + 1);
	glVertex2d(ColCaisse2 + 1, LigCaisse2);
	glEnd();

	glTranslated(ColCaisse2 + 0.5, LigCaisse2 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisse3()														// Même Code //
{
	glPushMatrix();

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisse3, LigCaisse3);
	glVertex2d(ColCaisse3, LigCaisse3 + 1);
	glVertex2d(ColCaisse3 + 1, LigCaisse3 + 1);
	glVertex2d(ColCaisse3 + 1, LigCaisse3);
	glEnd();

	glTranslated(ColCaisse3 + 0.5, LigCaisse3 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisse4()														// Même Code //
{
	glPushMatrix();

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisse4, LigCaisse4);
	glVertex2d(ColCaisse4, LigCaisse4 + 1);
	glVertex2d(ColCaisse4 + 1, LigCaisse4 + 1);
	glVertex2d(ColCaisse4 + 1, LigCaisse4);
	glEnd();

	glTranslated(ColCaisse4 + 0.5, LigCaisse4 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisse5()														// Même Code //
{
	glPushMatrix();

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisse5, LigCaisse5);
	glVertex2d(ColCaisse5, LigCaisse5 + 1);
	glVertex2d(ColCaisse5 + 1, LigCaisse5 + 1);
	glVertex2d(ColCaisse5 + 1, LigCaisse5);
	glEnd();

	glTranslated(ColCaisse5 + 0.5, LigCaisse5 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisse6()														// Même Code //
{
	glPushMatrix();

	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisse6, LigCaisse6);
	glVertex2d(ColCaisse6, LigCaisse6 + 1);
	glVertex2d(ColCaisse6 + 1, LigCaisse6 + 1);
	glVertex2d(ColCaisse6 + 1, LigCaisse6);
	glEnd();

	glTranslated(ColCaisse6 + 0.5, LigCaisse6 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}




void Caisses::DessinerCaisseV1()													// Même Code mais pour les Caisses Victoire en Vert //
{
	glPushMatrix();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisseV1, LigCaisseV1);
	glVertex2d(ColCaisseV1, LigCaisseV1 + 1);
	glVertex2d(ColCaisseV1 + 1, LigCaisseV1 + 1);
	glVertex2d(ColCaisseV1 + 1, LigCaisseV1);
	glEnd();

	glTranslated(ColCaisseV1 + 0.5, LigCaisseV1 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisseV2()													// Même Code //
{
	glPushMatrix();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisseV2, LigCaisseV2);
	glVertex2d(ColCaisseV2, LigCaisseV2 + 1);
	glVertex2d(ColCaisseV2 + 1, LigCaisseV2 + 1);
	glVertex2d(ColCaisseV2 + 1, LigCaisseV2);
	glEnd();

	glTranslated(ColCaisseV2 + 0.5, LigCaisseV2 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisseV3()													// Même Code //
{
	glPushMatrix();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisseV3, LigCaisseV3);
	glVertex2d(ColCaisseV3, LigCaisseV3 + 1);
	glVertex2d(ColCaisseV3 + 1, LigCaisseV3 + 1);
	glVertex2d(ColCaisseV3 + 1, LigCaisseV3);
	glEnd();

	glTranslated(ColCaisseV3 + 0.5, LigCaisseV3 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisseV4()													// Même Code //
{
	glPushMatrix();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisseV4, LigCaisseV4);
	glVertex2d(ColCaisseV4, LigCaisseV4 + 1);
	glVertex2d(ColCaisseV4 + 1, LigCaisseV4 + 1);
	glVertex2d(ColCaisseV4 + 1, LigCaisseV4);
	glEnd();

	glTranslated(ColCaisseV4 + 0.5, LigCaisseV4 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisseV5()													// Même Code //
{
	glPushMatrix();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisseV5, LigCaisseV5);
	glVertex2d(ColCaisseV5, LigCaisseV5 + 1);
	glVertex2d(ColCaisseV5 + 1, LigCaisseV5 + 1);
	glVertex2d(ColCaisseV5 + 1, LigCaisseV5);
	glEnd();

	glTranslated(ColCaisseV5 + 0.5, LigCaisseV5 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}


void Caisses::DessinerCaisseV6()													// Même Code //
{
	glPushMatrix();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(ColCaisseV6, LigCaisseV6);
	glVertex2d(ColCaisseV6, LigCaisseV6 + 1);
	glVertex2d(ColCaisseV6 + 1, LigCaisseV6 + 1);
	glVertex2d(ColCaisseV6 + 1, LigCaisseV6);
	glEnd();

	glTranslated(ColCaisseV6 + 0.5, LigCaisseV6 + 0.5, 0.0);
	glColor3d(0.0, 0.0, 0.0);
	glutWireCube(0.7);

	glPopMatrix();
}