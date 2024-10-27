#include "projet.h"


int main() {
    char m = 178;
    char v = 255;
    int nbt = 0;
    int nbi = 0;
    int nbl = 0;
    int C11 = 0;
    int C12 = 0;
    int C21 = 6;
    int C22 = 6;
    int C31 = 0;
    int C32 = 6;
    int C41 = 6;
    int C42 = 0;
    int Ctresor=-1;
    int Calea=0;
    int Compteurtresor1=0;
    int Compteurtresor2=0;
    int Compteurtresor3=0;
    int Compteurtresor4=0;
    int nbrjoueur=0;


    int *compteurtresor1=&Compteurtresor1;
    int *compteurtresor2=&Compteurtresor2;
    int *compteurtresor3=&Compteurtresor3;
    int *compteurtresor4=&Compteurtresor4;
    int *calea=&Calea;
    int *ctresor=&Ctresor;
    int *Nbt = &nbt;
    int *Nbi = &nbi;
    int *Nbl = &nbl;
    int *c11 = &C11;
    int *c12 = &C12;
    int *c21 = &C21;
    int *c22 = &C22;
    int *c31 = &C31;
    int *c32 = &C32;
    int *c41 = &C41;
    int *c42 = &C42;
    TUILE ALEATOIRE;
    char tableaucarajoueur[NOMBRE_JOUEUR_MAX];
    char tableautresor[NOMBRE_CARTE_TRESOR];
    int tableaualea[NOMBRE_CARTE_REST];
    char tableaucartejoueur[NOMBRE_JOUEUR_MAX][12];
    srand(time(NULL));
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < NOMBRE_CARTE_TRESOR; i++) {
        tableautresor[i] = 'a' + i;
    }
    for (int i = NOMBRE_CARTE_TRESOR - 1; i > 0; i=i-1) {
        int j;
        int temp;
        j = rand() % (i + 1);
        temp = tableautresor[i];
        tableautresor[i] = tableautresor[j];
        tableautresor[j] = temp;
    }

    for (int i = 0; i < NOMBRE_CARTE_REST; i++) {
        tableaualea[i] = 0 + i;
    }
    for (int i = NOMBRE_CARTE_REST - 1; i > 0; i=i-1) {
        int j;
        int temp;
        j = rand() % (i + 1);
        temp = tableaualea[i];
        tableaualea[i] = tableaualea[j];
        tableaualea[j] = temp;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    TUILE plateau[COLONNES][COLONNES];
    TUILE T = {m, v, v, v, v};
    TUILE TGAUCHE = {v, m, v, v, v};
    TUILE TDROITE = {v, v, v, m, v};
    TUILE TBAS = {v, v, v, v, m};

    TUILE I = {v, m, v, m, v};
    TUILE ICOUCHE = {m, v, v, v, m};

    TUILE LDEPARTDROITE = {m, v, v, m, v};
    TUILE LDEPARTGAUCHE = {m, m, v, v, v};
    TUILE LDEPARTBASGAUCHE = {v, m, v, v, m};
    TUILE LDEPARTBASDROITE = {v, v, v, m, m};


    TUILE ALEATOIRE1=PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                    LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE PIECERestante=ALEATOIRE1;
    TUILE ALEATOIRE2 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE3 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE4 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE5 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE6 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE7 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE8 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE9 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                      LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE10 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE11 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE12 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE13 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE14 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE15 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE16 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE17 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE18 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE19 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE20 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE21 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE22 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE23 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE24 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE25 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE26 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE27 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE28 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE29 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE30 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE31 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE32 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE33 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    TUILE ALEATOIRE34 = PieceALEATOIRE(&nbt, &nbi, &nbl, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE,
                                       LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);



    plateau[*c11][*c12].mMmillieu=tableaucarajoueur[1];
    plateau[*c21][*c22].mMmillieu=tableaucarajoueur[2];
    plateau[*c31][*c32].mMmillieu=tableaucarajoueur[3];
    plateau[*c41][*c42].mMmillieu=tableaucarajoueur[4];

    plateau[0][0] = LDEPARTGAUCHE;
    plateau[0][1] = ALEATOIRE34;
    plateau[0][2] = T;
    plateau[0][2].mMmillieu=tableautresor[13];

    plateau[0][3] = ALEATOIRE2;
    plateau[0][4] = T;
    plateau[0][4].mMmillieu=tableautresor[14];

    plateau[0][5] = ALEATOIRE3;
    plateau[0][6] = LDEPARTDROITE;

    plateau[1][0] = ALEATOIRE4;
    plateau[1][1] = ALEATOIRE5;
    plateau[1][2] = ALEATOIRE6;
    plateau[1][3] = ALEATOIRE7;
    plateau[1][4] = ALEATOIRE8;
    plateau[1][5] = ALEATOIRE9;
    plateau[1][6] = ALEATOIRE10;

    plateau[2][0] = TGAUCHE;
    plateau[2][0].mMmillieu=tableautresor[15];

    plateau[2][1] = ALEATOIRE11;
    plateau[2][2] = TGAUCHE;
    plateau[2][2].mMmillieu=tableautresor[16];

    plateau[2][3] = ALEATOIRE12;
    plateau[2][4] = T;
    plateau[2][4].mMmillieu=tableautresor[17];

    plateau[2][5] = ALEATOIRE13;
    plateau[2][6] = TDROITE;
    plateau[2][6].mMmillieu= tableautresor[18];

    plateau[3][0] = ALEATOIRE14;
    plateau[3][1] = ALEATOIRE15;
    plateau[3][2] = ALEATOIRE16;
    //////////////////////////////////////////
    plateau[3][3] = ALEATOIRE17;
    plateau[3][4] = ALEATOIRE18;
    plateau[3][5] = ALEATOIRE19;
    plateau[3][6] = ALEATOIRE20;

    plateau[4][0] = TGAUCHE;
    plateau[4][0].mMmillieu=tableautresor[19];

    plateau[4][1] = ALEATOIRE21;
    plateau[4][2] = TBAS;
    plateau[4][2].mMmillieu=tableautresor[20];

    plateau[4][3] = ALEATOIRE22;
    plateau[4][4] = TDROITE;
    plateau[4][4].mMmillieu=tableautresor[21];

    plateau[4][5] = ALEATOIRE23;
    plateau[4][6] = TDROITE;
    plateau[4][6].mMmillieu=tableautresor[22];

    plateau[5][0] = ALEATOIRE24;
    plateau[5][1] = ALEATOIRE25;
    plateau[5][2] = ALEATOIRE26;
    plateau[5][3] = ALEATOIRE27;
    plateau[5][4] = ALEATOIRE28;
    plateau[5][5] = ALEATOIRE29;
    plateau[5][6] = ALEATOIRE30;

    plateau[6][0] = LDEPARTBASGAUCHE;
    plateau[6][1] = ALEATOIRE31;
    plateau[6][2] = TBAS;
    plateau[6][2].mMmillieu=tableautresor[23];

    plateau[6][3] = ALEATOIRE32;
    plateau[6][4] = TBAS;
    plateau[6][4].mMmillieu=tableautresor[24];

    plateau[6][5] = ALEATOIRE33;
    plateau[6][6] = LDEPARTBASDROITE;

///////////////////////////////////////////////////////////////////////////
    for(int p=0; p<NOMBRE_CARTE_TRESOR/2; p++){
        int x=alea7();
        int y= alea7();
        if (plateau[x][y].mMmillieu!=tableautresor[0] && plateau[x][y].mMmillieu!=tableautresor[1] && plateau[x][y].mMmillieu!=tableautresor[2] &&
            plateau[x][y].mMmillieu!=tableautresor[3] && plateau[x][y].mMmillieu!=tableautresor[4] && plateau[x][y].mMmillieu!=tableautresor[5] &&
            plateau[x][y].mMmillieu!=tableautresor[6] && plateau[x][y].mMmillieu!=tableautresor[7] && plateau[x][y].mMmillieu!=tableautresor[8] &&
            plateau[x][y].mMmillieu!=tableautresor[9] && plateau[x][y].mMmillieu!=tableautresor[10] && plateau[x][y].mMmillieu!=tableautresor[11] &&
            plateau[x][y].mMmillieu!=tableautresor[12] && plateau[x][y].mMmillieu!=tableautresor[13] && plateau[x][y].mMmillieu!=tableautresor[14] &&
            plateau[x][y].mMmillieu!=tableautresor[15] &&plateau[x][y].mMmillieu!=tableautresor[16] && plateau[x][y].mMmillieu!=tableautresor[17] &&
            plateau[x][y].mMmillieu!=tableautresor[18] && plateau[x][y].mMmillieu!=tableautresor[19] && plateau[x][y].mMmillieu!=tableautresor[20] &&
            plateau[x][y].mMmillieu!=tableautresor[21] && plateau[x][y].mMmillieu!=tableautresor[22] && plateau[x][y].mMmillieu!=tableautresor[23] &&
            plateau[x][y].mMmillieu!=tableautresor[24] /*&&plateau[x][y].mMmillieu!=tableaucarajoueur[1] && plateau[x][y].mMmillieu!=tableaucarajoueur[2] &&
        plateau[x][y].mMmillieu!=tableaucarajoueur[3] && plateau[x][y].mMmillieu!=tableaucarajoueur[4]*/) {
            if((x==1 && y ==1)||(x==1 && y==6)||(x==6 && y==1)||(x==6 && y==6)){
                p=p-1;
            }else{
                plateau[x][y].mMmillieu= tableautresor[p];
            }
        }else{
            p=p-1;
        }
    }

    PIECERestante= ALEATOIRE1;
    TUILE PIECERestante2;
    int arret=0;

    nbrjoueur=Affichermenu(tableaucarajoueur, &Ctresor, tableaucartejoueur, tableautresor);
    Afficherplateau(plateau,&C11, &C12, tableaucarajoueur, &C21, &C22, &C31, &C32, &C41, &C42, PIECERestante,tableautresor,&Ctresor);
    if(nbrjoueur==2) {
        do {
            printf("\nAu tour du joueur 1\n");
            PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22, &C31,
                                          &C32, &C41, &C42,
                                          T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                          LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                          &Ctresor);
            PIECERestante = PIECERestante2;
            Avancerjoueur1(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                           PIECERestante,
                           tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor1, nbrjoueur);

            if(*compteurtresor1 >= 12){
                arret=1;
            }

            if(arret==0) {
                printf("\nAu tour du joueur 2\n");
                PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22,
                                              &C31,
                                              &C32, &C41, &C42,
                                              T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                              LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                              &Ctresor);
                PIECERestante = PIECERestante2;
                Avancerjoueur2(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                               PIECERestante,
                               tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor2, nbrjoueur);
            }

            if (*compteurtresor2 >= 12){
                arret=1;
            }
        } while (arret==0);
    }else if(nbrjoueur==3){
        do {
            printf("\nAu tour du joueur 1\n");
            PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22, &C31,
                                          &C32, &C41, &C42,
                                          T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                          LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                          &Ctresor);
            PIECERestante = PIECERestante2;
            Avancerjoueur1(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                           PIECERestante,
                           tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor1, nbrjoueur);

            if(*compteurtresor1 >= 12){
                arret=1;
            }

            if(arret==0) {
                printf("\nAu tour du joueur 2\n");
                PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22,
                                              &C31,
                                              &C32, &C41, &C42,
                                              T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                              LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                              &Ctresor);
                PIECERestante = PIECERestante2;
                Avancerjoueur2(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                               PIECERestante,
                               tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor2, nbrjoueur);
            }

            if (*compteurtresor2 >= 12){
                arret=1;
            }

            if(arret==0) {
                printf("\nAu tour du joueur 3\n");
                PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22,
                                              &C31,
                                              &C32,
                                              &C41, &C42,
                                              T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                              LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                              &Ctresor);
                PIECERestante = PIECERestante2;

                Avancerjoueur3(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                               PIECERestante,
                               tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor3, nbrjoueur);
            }
            if (*compteurtresor3 >= 12){
                arret=1;
            }

        }while (arret==0);
    }else if(nbrjoueur==4){
        do {
            printf("\nAu tour du joueur 1\n");
            PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22, &C31,
                                          &C32, &C41, &C42,
                                          T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                          LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                          &Ctresor);
            PIECERestante = PIECERestante2;
            Avancerjoueur1(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                           PIECERestante,
                           tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor1, nbrjoueur);

            if(*compteurtresor1 >= 12){
                arret=1;
            }

            if(arret==0) {
                printf("\nAu tour du joueur 2\n");
                PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22,
                                              &C31,
                                              &C32, &C41, &C42,
                                              T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                              LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                              &Ctresor);
                PIECERestante = PIECERestante2;
                Avancerjoueur2(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                               PIECERestante,
                               tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor2, nbrjoueur);
            }

            if (*compteurtresor2 >= 12){
                arret=1;
            }

            if(arret==0) {
                printf("\nAu tour du joueur 3\n");
                PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22,
                                              &C31,
                                              &C32,
                                              &C41, &C42,
                                              T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                              LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                              &Ctresor);
                PIECERestante = PIECERestante2;

                Avancerjoueur3(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                               PIECERestante,
                               tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor3, nbrjoueur);
            }
            if (*compteurtresor3 >= 12){
                arret=1;
            }

            if(arret==0) {
                printf("\nAu tour du joueur 4\n");
                PIECERestante2 = InsererPiece(plateau, PIECERestante, &C11, &C12, tableaucarajoueur, &C21, &C22,
                                              &C31,
                                              &C32,
                                              &C41, &C42,
                                              T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE,
                                              LDEPARTBASGAUCHE, LDEPARTBASDROITE, tableautresor,
                                              &Ctresor);
                PIECERestante = PIECERestante2;

                Avancerjoueur4(plateau, tableaucarajoueur, &C11, &C12, &C21, &C22, &C31, &C32, &C41, &C42,
                               PIECERestante,
                               tableautresor, &Ctresor, tableaucartejoueur, &Compteurtresor4, nbrjoueur);
            }
            if (*compteurtresor4 >= 12){
                arret=1;
            }

        }while (arret==1);
    }
    printf("\nLe jeu est termine !");
    if(*compteurtresor1==NOMBRE_CARTE_TRESOR/ nbrjoueur) {
        printf("\nLe joueur 1 a gagne !\n BRAVO");
    } else if(*compteurtresor2==NOMBRE_CARTE_TRESOR/ nbrjoueur){
        printf("\nLe joueur 2 a gagne !\n BRAVO");
    }else if(*compteurtresor3==NOMBRE_CARTE_TRESOR/ nbrjoueur){
        printf("\nLe joueur 3 a gagne !\n BRAVO");
    }else {
        printf("\nLe joueur 4 a gagne !\n BRAVO");
    }
    scanf("%d", &arret);
}
