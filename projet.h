#ifndef TP2EX_PROJET_H
#define TP2EX_PROJET_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLONNES 7
#define NOMBRE_CARTE_TRESOR 24
#define NOMBRE_CARTE_REST 7 //pour coordonnées
#define NOMBRE_JOUEUR_MAX 4


void mur();
void casevideafficher();
int alea10();
int alea7();
typedef struct {
    char mHmillieu, mMgauche, mMmillieu, mMdroite, mBmillieu;
} TUILE;

int verifiertresor(char tableaucarte[NOMBRE_JOUEUR_MAX][12], TUILE plateau[COLONNES][COLONNES], int *cX1, int *cX2, int joueur);


void Joueur(int nbJoueur, char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int* ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12], char tableautresor[NOMBRE_CARTE_TRESOR]);
int Affichermenu(char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int* ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12], char tableautresor[NOMBRE_CARTE_TRESOR]);

int demanderJoueur();
void AfficherPieceRest(TUILE PieceRESTANTE);

char Afficherplateau(TUILE plateau[COLONNES][COLONNES], int* c11, int* c12, char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int* c21, int* c22, int* c31, int* c32,
                     int* c41, int* c42, TUILE PieceRESTANTE, char tableautresor[NOMBRE_CARTE_TRESOR], int* ctresor);

TUILE PieceALEATOIRE(int *Nbl, int *Nbi, int *Nbt, TUILE T, TUILE TGAUCHE, TUILE TDROITE, TUILE TBAS, TUILE I, TUILE ICOUCHE, TUILE LDEPARTDROITE,
                     TUILE LDEPARTGAUCHE, TUILE LDEPARTBASGAUCHE, TUILE LDEPARTBASDROITE);

void Avancerjoueur1(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int* c11, int* c12, int *c21, int *c22, int *c31, int *c32,
                    int *c41, int *c42, TUILE PieceRESTANTE, char tableautresor[NOMBRE_CARTE_TRESOR], int* ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12],
                    int *compteurtresor1, int nbrjoueur);

void Avancerjoueur2(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int* c11, int* c12, int *c21, int *c22, int *c31, int *c32,
                    int *c41, int *c42, TUILE PieceRESTANTE, char tableautresor[NOMBRE_CARTE_TRESOR], int* ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12],
                    int *compteurtresor2, int nbrjoueur);

void Avancerjoueur3(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int* c11, int* c12, int *c21, int *c22, int *c31, int *c32,
                    int *c41, int *c42, TUILE PieceRESTANTE, char tableautresor[NOMBRE_CARTE_TRESOR], int* ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12],
                    int *compteurtresor3, int nbrjoueur);

void Avancerjoueur4(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int* c11, int* c12, int *c21, int *c22, int *c31, int *c32,
                    int *c41, int *c42, TUILE PieceRESTANTE, char tableautresor[NOMBRE_CARTE_TRESOR], int* ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12],
                    int *compteurtresor4, int nbrjoueur);

int Menu();

TUILE Orientationtuile(TUILE PieceRESTANTE, TUILE T, TUILE TGAUCHE, TUILE TDROITE, TUILE TBAS, TUILE I, TUILE ICOUCHE,
                       TUILE LDEPARTDROITE, TUILE LDEPARTGAUCHE, TUILE LDEPARTBASGAUCHE, TUILE LDEPARTBASDROITE);
TUILE InsererPiece(TUILE plateau[COLONNES][COLONNES], TUILE PieceRESTANTE, int* c11, int* c12, char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *c21, int* c22,
                   int *c31, int* c32, int *c41, int* c42, TUILE T, TUILE TGAUCHE, TUILE TDROITE, TUILE TBAS, TUILE I, TUILE ICOUCHE,
                   TUILE LDEPARTDROITE, TUILE LDEPARTGAUCHE, TUILE LDEPARTBASGAUCHE, TUILE LDEPARTBASDROITE, char tableautresor[NOMBRE_CARTE_TRESOR], int*ctresor);

#endif //TP2EX_PROJET_H