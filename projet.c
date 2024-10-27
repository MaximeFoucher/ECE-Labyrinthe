#include "projet.h"

void mur() {
    char m = 178;
    printf("%c%c%c", m, m, m);
}

int alea10() {
    int alea;
    alea = rand() % 9;
    return alea;
}

int alea7() {
    int alea;
    alea = rand() % 6;
    return alea;
}

void casevideafficher() {
    printf("%c%c%c%c%c%c%c%c%c%c", 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
}

int verifiertresor(char tableaucarte[NOMBRE_JOUEUR_MAX][12], TUILE plateau[COLONNES][COLONNES], int *c11, int *c12, int joueur){
    int m;
    if (plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][0] || plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][1] ||
        plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][2] || plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][3] ||
        plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][4] || plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][5] ||
        plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][6] || plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][7] ||
        plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][8] || plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][9] ||
        plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][10] || plateau[*c11][*c12].mMmillieu==tableaucarte[joueur-1][11]){
        m=1;
    }else{
        m=0;
    }
    return m;
}

int Menu() {
    int choixMenu;
    printf("\n/*/*/*/*/*/*/*/*/*/*/BIENVENU DANS LE LABYRINTHE/*/*/*/*/*/*/*/*/*/*/\n");
    printf("////MENU PRINCIPAL////\n1:Nouvelle partie\n2:Charger Partie\n3:Sauvegarde\n4:Regles du jeu\n5:Quitter\n");
    scanf("%d", &choixMenu);
    switch (choixMenu) {
        case 1:
            printf("NOUVELLE PARTIE\n");
            break;
        case 2:
            printf("CHARGER PARTIE\n");
            break;
        case 3:
            printf("SAUVEGARDER\n");
            break;
        case 4:
            printf("\ncliquez sur le lien suivant pour lire les regles :\nhttps://www.ravensburger.fr/spielanleitungen/ecm/Spielanleitungen/26743_Labyrinthe_00.pdf?ossl=pds_text_Spielanleitung\n");
            break;
    }
    printf("\n");
    return choixMenu;
}

int Affichermenu(char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12],
                 char tableautresor[NOMBRE_CARTE_TRESOR]) {
    int choix;
    int nbrjoueur=0;
    do {
        choix = Menu();
    } while (choix != 1 && choix != 5);
    if (choix == 1) {
        nbrjoueur=demanderJoueur();
        Joueur(nbrjoueur, tableaucarajoueur, ctresor, tableaucarte, tableautresor);
    } else if (choix == 5) {
        printf("FIN");
    }
    return nbrjoueur;
}

void Joueur(int nbJoueur, char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12],
            char tableautresor[NOMBRE_CARTE_TRESOR]) {
    int caracspe = 0;
    char v=255;
    printf("veuillez choisir un caractere special parmi ceux presentes:\n1.%c, 2.%c, 3.%c, 4.%c\n", 03, 04, 05, 06);

    if (nbJoueur == 2) {
        for (int i = 0; i < NOMBRE_CARTE_TRESOR / 2; i++) {
            tableaucarte[0][i] = tableautresor[i];
            tableaucarte[1][i] = tableautresor[i + 12];
            tableaucarajoueur[3]=v;
            tableaucarajoueur[4]=v;
        }
    } else if (nbJoueur == 3) {
        for (int i = 0; i < NOMBRE_CARTE_TRESOR / 3; i++) {
            tableaucarte[0][i] = tableautresor[i];
            tableaucarte[1][i] = tableautresor[i + 8];
            tableaucarte[2][i] = tableautresor[i + 16];
            tableaucarajoueur[4]=v;
        }
    } else {
        for (int i = 0; i < NOMBRE_CARTE_TRESOR / 4; i++) {
            tableaucarte[0][i] = tableautresor[i];
            tableaucarte[1][i] = tableautresor[i + 6];
            tableaucarte[2][i] = tableautresor[i + 12];
            tableaucarte[3][i] = tableautresor[i + 18];
        }
    }
    for (int i = 1; i <= nbJoueur; ++i) {
        printf("\n\nPour le %de joueur:\n", i);
        scanf("%d", &caracspe);
        while (caracspe < 1 || caracspe > 4) {
            printf("ERREUR dans l'ecriture ressayez:\n");
            scanf("%d", &caracspe);
        }
        if (caracspe == 1) {
            tableaucarajoueur[i] = 03;
        } else if (caracspe == 2) {
            tableaucarajoueur[i] = 04;
        } else if (caracspe == 3) {
            tableaucarajoueur[i] = 05;
        } else if (caracspe == 4) {
            tableaucarajoueur[i] = 06;
        }
        printf("\npour le %de joueur vous avez choisis : %c\nVos tresors sont:\n", i, tableaucarajoueur[i]);
        for (int u = 0; u < NOMBRE_CARTE_TRESOR / nbJoueur; u++) {
            printf("%c. ", tableaucarte[i - 1][u]);
        }
    }
    printf("\n\nQue la partie commence !\n");
}

TUILE
PieceALEATOIRE(int *Nbl, int *Nbi, int *Nbt, TUILE T, TUILE TGAUCHE, TUILE TDROITE, TUILE TBAS, TUILE I, TUILE ICOUCHE,
               TUILE LDEPARTDROITE, TUILE LDEPARTGAUCHE, TUILE LDEPARTBASGAUCHE, TUILE LDEPARTBASDROITE) {
    TUILE ALEATOIRE;
    int alea;
    do {
        alea = alea10();
        if (alea == 0 && *Nbt < 6) {
            ALEATOIRE = T;
            ++*Nbt;
        } else if (alea == 1 && *Nbt < 6) {
            ALEATOIRE = TGAUCHE;
            ++*Nbt;
        } else if (alea == 2 && *Nbt < 6) {
            ALEATOIRE = TDROITE;
            ++*Nbt;
        } else if (alea == 3 && *Nbt < 6) {
            ALEATOIRE = TBAS;
            ++*Nbt;
        } else if (alea == 4 && *Nbi < 12) {
            ALEATOIRE = I;
            ++*Nbi;
        } else if (alea == 5 && *Nbi < 12) {
            ALEATOIRE = ICOUCHE;
            ++*Nbi;
        } else if (alea == 6 && *Nbl < 16) {
            ALEATOIRE = LDEPARTDROITE;
            ++*Nbl;
        } else if (alea == 7 && *Nbl < 16) {
            ALEATOIRE = LDEPARTGAUCHE;
            ++*Nbl;
        } else if (alea == 8 && *Nbl < 16) {
            ALEATOIRE = LDEPARTBASDROITE;
            ++*Nbl;
        } else if (alea == 9 && *Nbl < 16) {
            ALEATOIRE = LDEPARTBASGAUCHE;
            ++*Nbl;
        } else {
            alea = 0;
        }
    } while (alea == 0);
    return ALEATOIRE;
}

int demanderJoueur() {
    int nbJoueur;
    do {
        printf("Vous pouvez jouer de 2 a 4 joueurs.\n");
        printf("Combien de joueur?\n");
        scanf("%d", &nbJoueur);
    } while (nbJoueur < 2 || nbJoueur > 4);
    return nbJoueur;
}

/////////////////////////////////////////////////////////////////////////////DEPLACEMENT

void Avancerjoueur1(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *c11, int *c12,
                    int *c21, int *c22, int *c31, int *c32, int *c41, int *c42, TUILE PieceRESTANTE,char tableautresor[NOMBRE_CARTE_TRESOR],
                    int *ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12], int* compteurtresor1, int nbrjoueur) {
    int mvt;
    char m = 178;
    char v=255;
    int i=-1;
    int arret=0;
    do {
        printf("Au tour du joueur 1: %c\n", tableaucarajoueur[1]);
        Afficherplateau(plateau, c11, c12, tableaucarajoueur, c21, c22, c31, c32, c41, c42, PieceRESTANTE, tableautresor, ctresor);
        printf("\nVos tresors sont:\n");
        for (int i = 0; i < NOMBRE_CARTE_TRESOR/nbrjoueur; i++) {
            printf("%c. ", tableaucarte[0][i]);
        }
        printf("\nvous avez receuillit %d tresor(s)\n", *compteurtresor1);
        printf("\nPour finir votre tour appuyez sur 0.\n");
        scanf("%d", &mvt);
        if (mvt == 8) {
            if (plateau[*c11 - 1][*c12].mBmillieu == m || plateau[*c11][*c12].mHmillieu == m) {
                printf("il y a une mur en haut c'est impossible.\n");
            } else {if ('a'<=plateau[*c11][*c12].mMmillieu && plateau[*c11][*c12].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c11][*c12].mMmillieu==tableaucarte[0][i]){
                            ++*compteurtresor1;
                            arret=1;
                            plateau[*c11][*c12].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }

                *c11 = *c11 - 1;
            }
        } else if (mvt == 5) {
            if (plateau[*c11 + 1][*c12].mHmillieu == m || plateau[*c11][*c12].mBmillieu == m) {
                printf("il y a une mur en bas c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c11][*c12].mMmillieu && plateau[*c11][*c12].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c11][*c12].mMmillieu==tableaucarte[0][i]){
                            ++*compteurtresor1;
                            arret=1;
                            plateau[*c11][*c12].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c11;
            }
        } else if (mvt == 4) {
            if (plateau[*c11][*c12 - 1].mMdroite == m || plateau[*c11][*c12].mMgauche == m) {
                printf("il y a une mur a gauche c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c11][*c12].mMmillieu && plateau[*c11][*c12].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c11][*c12].mMmillieu==tableaucarte[0][i]){
                            ++*compteurtresor1;
                            arret=1;
                            plateau[*c11][*c12].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }

                *c12 = *c12 - 1;
            }
        } else if (mvt == 6) {
            if (plateau[*c11][*c12 + 1].mMgauche == m || plateau[*c11][*c12].mMdroite == m) {
                printf("il y a une mur a droite c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c11][*c12].mMmillieu && plateau[*c11][*c12].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c11][*c12].mMmillieu==tableaucarte[0][i]){
                            ++*compteurtresor1;
                            arret=1;
                            plateau[*c11][*c12].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c12;
            }

        }
        else if (mvt==1){
            ++*compteurtresor1;
            plateau[*c11][*c12].mMmillieu=255;
        }
    } while (mvt != 0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Avancerjoueur2(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *c11, int *c12,
                    int *c21, int *c22, int *c31, int *c32, int *c41, int *c42, TUILE PieceRESTANTE,char tableautresor[NOMBRE_CARTE_TRESOR],
                    int *ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12], int* compteurtresor2, int nbrjoueur) {
    int mvt;
    char m = 178;
    char v=255;
    int i=-1;
    int arret=0;
    do {
        printf("Au tour du joueur 2: %c\n", tableaucarajoueur[2]);
        Afficherplateau(plateau, c11, c12, tableaucarajoueur, c21, c22, c31, c32, c41, c42, PieceRESTANTE, tableautresor, ctresor);
        printf("\nVos tresors sont:\n");
        for (int i = 0; i < NOMBRE_CARTE_TRESOR/nbrjoueur; i++) {
            printf("%c. ", tableaucarte[1][i]);
        }
        printf("\nvous avez receuillit %d tresor(s)\n", *compteurtresor2);
        printf("\nPour finir votre tour appuyez sur 0.\n");
        scanf("%d", &mvt);
        if (mvt == 8) {
            if (plateau[*c21 - 1][*c22].mBmillieu == m || plateau[*c21][*c22].mHmillieu == m) {
                printf("il y a une mur en haut c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c21][*c22].mMmillieu && plateau[*c21][*c22].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c21][*c22].mMmillieu==tableaucarte[1][i]){
                            ++*compteurtresor2;
                            arret=1;
                            plateau[*c21][*c22].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                *c21 = *c21 - 1;
            }
        } else if (mvt == 5) {
            if (plateau[*c21 + 1][*c22].mHmillieu == m || plateau[*c21][*c22].mBmillieu == m) {
                printf("il y a une mur en bas c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c21][*c22].mMmillieu && plateau[*c21][*c22].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c21][*c22].mMmillieu==tableaucarte[1][i]){
                            ++*compteurtresor2;
                            arret=1;
                            plateau[*c21][*c22].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c21;
            }
        } else if (mvt == 4) {
            if (plateau[*c21][*c22 - 1].mMdroite == m || plateau[*c21][*c22].mMgauche == m) {
                printf("il y a une mur a gauche c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c21][*c22].mMmillieu && plateau[*c21][*c22].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c21][*c22].mMmillieu==tableaucarte[1][i]){
                            ++*compteurtresor2;
                            arret=1;
                            plateau[*c21][*c22].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                *c22 = *c22 - 1;
            }
        } else if (mvt == 6) {
            if (plateau[*c21][*c22 + 1].mMgauche == m || plateau[*c21][*c22].mMdroite == m) {
                printf("il y a une mur a droite c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c21][*c22].mMmillieu && plateau[*c21][*c22].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c21][*c22].mMmillieu==tableaucarte[1][i]){
                            ++*compteurtresor2;
                            arret=1;
                            plateau[*c21][*c22].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c22;
            }
        }
        else if (mvt==1){
            ++*compteurtresor2;
            plateau[*c21][*c22].mMmillieu=255;
        }
    } while (mvt != 0);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Avancerjoueur3(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *c11, int *c12,
                    int *c21, int *c22, int *c31, int *c32, int *c41, int *c42, TUILE PieceRESTANTE,char tableautresor[NOMBRE_CARTE_TRESOR],
                    int *ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12], int* compteurtresor3, int nbrjoueur) {
    int mvt;
    char m = 178;
    char v=255;
    int i=-1;
    int arret=0;
    do {
        printf("Au tour du joueur 3: %c\n", tableaucarajoueur[3]);
        Afficherplateau(plateau, c11, c12, tableaucarajoueur, c21, c22, c31, c32, c41, c42, PieceRESTANTE, tableautresor, ctresor);
        printf("\nVos tresors sont:\n");
        for (int i = 0; i < NOMBRE_CARTE_TRESOR/nbrjoueur; i++) {
            printf("%c. ", tableaucarte[2][i]);
        }
        printf("\nvous avez receuillit %d tresor(s)\n", *compteurtresor3);
        printf("\nPour finir votre tour appuyez sur 0.\n");
        scanf("%d", &mvt);
        if (mvt == 8) {
            if (plateau[*c31 - 1][*c32].mBmillieu == m || plateau[*c31][*c32].mHmillieu == m) {
                printf("il y a une mur en haut c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c31][*c32].mMmillieu && plateau[*c31][*c32].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c31][*c32].mMmillieu==tableaucarte[2][i]){
                            ++*compteurtresor3;
                            arret=1;
                            plateau[*c31][*c32].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                *c31 = *c31 - 1;
            }
        } else if (mvt == 5) {
            if (plateau[*c31 + 1][*c32].mHmillieu == m || plateau[*c31][*c32].mBmillieu == m) {
                printf("il y a une mur en bas c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c31][*c32].mMmillieu && plateau[*c31][*c32].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c31][*c32].mMmillieu==tableaucarte[2][i]){
                            ++*compteurtresor3;
                            arret=1;
                            plateau[*c31][*c32].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c31;
            }
        } else if (mvt == 4) {
            if (plateau[*c31][*c32 - 1].mMdroite == m || plateau[*c31][*c32].mMgauche == m) {
                printf("il y a une mur a gauche c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c31][*c32].mMmillieu && plateau[*c31][*c32].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c31][*c32].mMmillieu==tableaucarte[2][i]){
                            ++*compteurtresor3;
                            arret=1;
                            plateau[*c31][*c32].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                *c32 = *c32 - 1;
            }
        } else if (mvt == 6) {
            if (plateau[*c31][*c32 + 1].mMgauche == m || plateau[*c31][*c32].mMdroite == m) {
                printf("il y a une mur a droite c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c31][*c32].mMmillieu && plateau[*c31][*c32].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c31][*c32].mMmillieu==tableaucarte[2][i]){
                            ++*compteurtresor3;
                            arret=1;
                            plateau[*c31][*c32].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c32;
            }
        }else if (mvt==1){
            ++*compteurtresor3;
            plateau[*c31][*c32].mMmillieu=255;
        }
    } while (mvt != 0);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Avancerjoueur4(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *c11, int *c12,
                    int *c21, int *c22, int *c31, int *c32, int *c41, int *c42, TUILE PieceRESTANTE,char tableautresor[NOMBRE_CARTE_TRESOR],
                    int *ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12], int* compteurtresor4, int nbrjoueur) {
    int mvt;
    char m = 178;
    char v=255;
    int i=-1;
    int arret=0;
    do {
        printf("Au tour du joueur 4: %c\n", tableaucarajoueur[4]);
        Afficherplateau(plateau, c11, c12, tableaucarajoueur, c21, c22, c31, c32, c41, c42, PieceRESTANTE, tableautresor, ctresor);
        printf("\nVos tresors sont:\n");
        for (int i = 0; i < NOMBRE_CARTE_TRESOR/nbrjoueur; i++) {
            printf("%c. ", tableaucarte[3][i]);
        }
        printf("\nvous avez receuillit %d tresor(s)\n", *compteurtresor4);
        printf("\nPour finir votre tour appuyez sur 0.\n");
        scanf("%d", &mvt);
        if (mvt == 8) {
            if (plateau[*c41 - 1][*c42].mBmillieu == m || plateau[*c41][*c42].mHmillieu == m) {
                printf("il y a une mur en haut c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c41][*c42].mMmillieu && plateau[*c41][*c42].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c41][*c42].mMmillieu==tableaucarte[3][i]){
                            ++*compteurtresor4;
                            arret=1;
                            plateau[*c41][*c42].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                *c41 = *c41 - 1;
            }
        } else if (mvt == 5) {
            if (plateau[*c41 + 1][*c42].mHmillieu == m || plateau[*c41][*c42].mBmillieu == m) {
                printf("il y a une mur en bas c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c41][*c42].mMmillieu && plateau[*c41][*c42].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c41][*c42].mMmillieu==tableaucarte[3][i]){
                            ++*compteurtresor4;
                            arret=1;
                            plateau[*c41][*c42].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c41;
            }
        } else if (mvt == 4) {
            if (plateau[*c41][*c42 - 1].mMdroite == m || plateau[*c41][*c42].mMgauche == m) {
                printf("il y a une mur a gauche c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c41][*c42].mMmillieu && plateau[*c41][*c42].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c41][*c42].mMmillieu==tableaucarte[3][i]){
                            ++*compteurtresor4;
                            arret=1;
                            plateau[*c41][*c42].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                *c42 = *c42 - 1;
            }
        } else if (mvt == 6) {
            if (plateau[*c41][*c42 + 1].mMgauche == m || plateau[*c41][*c42].mMdroite == m) {
                printf("il y a une mur a droite c'est impossible.\n");
            } else {
                if ('a'<=plateau[*c41][*c42].mMmillieu && plateau[*c41][*c42].mMmillieu>'y'){
                    do{
                        i++;
                        if(plateau[*c41][*c42].mMmillieu==tableaucarte[3][i]){
                            ++*compteurtresor4;
                            arret=1;
                            plateau[*c41][*c42].mMmillieu=v;
                        }
                    } while (i<=12 || arret==1);
                }
                ++*c42;
            }
        }else if (mvt==1){
            ++*compteurtresor4;
            plateau[*c41][*c42].mMmillieu=255;
        }
    } while (mvt != 0);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void Avancerjoueur1(TUILE plateau[COLONNES][COLONNES], char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *c11, int *c12,
                    int *c21, int *c22, int *c31, int *c32, int *c41, int *c42, TUILE PieceRESTANTE,char tableautresor[NOMBRE_CARTE_TRESOR],
                    int *ctresor, char tableaucarte[NOMBRE_JOUEUR_MAX][12], int* compteurtresor1) {
    int mvt;
    char m = 178;
    char verif;
    char v=255;
    int i=-1;
    int arret=0;
    do {
        printf("Au tour du joueur 1: %c\n", tableaucarajoueur[1]);
        Afficherplateau(plateau, c11, c12, tableaucarajoueur, c21, c22, c31, c32, c41, c42, PieceRESTANTE, tableautresor, ctresor);
        printf("\nVos tresors sont:\n");
        for (int i = 0; i < 12; i++) {
            printf("%c. ", tableaucarte[0][i]);
        }
        printf("\nvous avez receuillit %d tresor(s)\n", *compteurtresor1);
        printf("\nPour haut utilisez 8, pour bas 5, pour droite 6, pour gauche 4 et 0 pour finir votre tour.\n");
        scanf("%d", &mvt);
        if (mvt == 8) {
                /*if (plateau[*c11-1][*c12].mMmillieu!=v && plateau[*c11-1][*c12].mMmillieu!=m){
                    do{
                        i++;
                        verif=tableaucarte[0][i];
                        if(plateau[*c11][*c12].mMmillieu==verif){
                            arret=1;
                            ++*compteurtresor1;
                            plateau[*c11-1][*c12].mMmillieu=v;
                        }
                    } while (i<12 || arret==1);
                }*/
/*i=-1;
if (plateau[*c11-1][*c12].mMmillieu!=v && plateau[*c11-1][*c12].mMmillieu!=m){
do{
    i++;
    verif=tableaucarte[0][i];
    if(plateau[*c11-1][*c12].mMmillieu==verif){
        ++*compteurtresor1;
        plateau[*c11-1][*c12].mMmillieu=v;
        arret=1;
    }
    if(i==12){
        arret=1;
    }
} while (arret==1);
}*/
/*                *c11 = *c11 - 1;

        } else if (mvt == 5) {
            /*i=-1;
            if (plateau[*c11+1][*c12].mMmillieu!=v && plateau[*c11+1][*c12].mMmillieu!=m){
                do{
                    i++;
                    verif=tableaucarte[0][i];
                    if(plateau[*c11+1][*c12].mMmillieu==verif){
                        ++*compteurtresor1;
                        plateau[*c11+1][*c12].mMmillieu=v;
                        arret=1;
                    }
                    if(i==12){
                        arret=1;
                    }
                } while (arret==1);
            }*/
/*           ++*c11;
           *compteurtresor1=*compteurtresor1+verifiertresor(tableaucarte, plateau, *c11, *c12, 1);
       } else if (mvt == 4) {
           /*i=-1;
           if (plateau[*c11][*c12-1].mMmillieu!=v && plateau[*c11][*c12-1].mMmillieu!=m){
               do{
                   i++;
                   verif=tableaucarte[0][i];
                   if(plateau[*c11][*c12-1].mMmillieu==verif){
                       ++*compteurtresor1;
                       plateau[*c11][*c12-1].mMmillieu=v;
                       arret=1;
                   }
                   if(i==12){
                       arret=1;
                   }
               } while (arret==1);
           }*/
/*            *c12 = *c12 - 1;
            *compteurtresor1=*compteurtresor1+verifiertresor(tableaucarte, plateau, *c11, *c12, 1);
        } else if (mvt == 6) {
            /*i=-1;
            if (plateau[*c11][*c12+1].mMmillieu!=v && plateau[*c11][*c12+1].mMmillieu!=m){
                do{
                    i++;
                    verif=tableaucarte[0][i];
                    if(plateau[*c11][*c12+1].mMmillieu==verif){
                        ++*compteurtresor1;
                        plateau[*c11][*c12+1].mMmillieu=v;
                        arret=1;
                    }
                    if(i==12){
                        arret=1;
                    }
                } while (arret==1);
            }*/
/*            ++*c12;
            *compteurtresor1=*compteurtresor1+verifiertresor(tableaucarte, plateau, *c11, *c12, 1);
        }
    } while (mvt != 0);
}*/



char Afficherplateau(TUILE plateau[COLONNES][COLONNES], int *c11, int *c12, char tableaucarajoueur[NOMBRE_JOUEUR_MAX],
                     int *c21, int *c22, int *c31, int *c32, int *c41, int *c42, TUILE PieceRESTANTE,
                     char tableautresor[NOMBRE_CARTE_TRESOR], int *ctresor) {
    ////////////////////////////////////////////////////////////////////////////////////////
    casevideafficher();
    casevideafficher();
    printf("%c%c%c1%c%c%c%c", 255, 255, 255, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c2%c%c%c%c", 255, 255, 255, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c3%c%c%c%c\n", 255, 255, 255, 255, 255, 255, 255);
    //
    casevideafficher();
    casevideafficher();
    printf("%c%c%c%c%c%c%c%c", 255, 255, 255, 25, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c%c%c%c%c%c", 255, 255, 255, 25, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c%c%c%c%c%c\n", 255, 255, 255, 25, 255, 255, 255, 255);
    ////////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < COLONNES; i++) {
        casevideafficher();
        for (int j = 0; j < COLONNES; j++) {
            mur();
            printf("%c%c%c", plateau[i][j].mHmillieu, plateau[i][j].mHmillieu, plateau[i][j].mHmillieu);
            mur();
        }
        if (i==0){
            printf("            ");
        }else if(i==1){
            printf("         .-/|          Les regles sont:          \\ /   Voici la piece dans votre main   |\\-.");
        }else if (i==6){
            printf("         ||/=====================================\\|/=====================================\\||");
        }else if (i==2){
            printf("         ||||                                     |                                     ||||");
        }else if (i==3){
            printf("         ||||                                     |              %c%c%c%c%c%c%c%c%c              ||||", 178, 178, 178, PieceRESTANTE.mHmillieu, PieceRESTANTE.mHmillieu, PieceRESTANTE.mHmillieu, 178, 178, 178);
        }else if (i==4){
            printf("         ||||Pour gerer l'orientation de la tuile:|                                     ||||");
        }else if (i==5){
            printf("         ||||Appuyez sur 1 pour capturer le tresor| APPUYER SUR 0 CONFIRME TOUTE ACTION ||||");
        }
        printf("\n");
        for (int j = 0; j < COLONNES; j++) {
            /////////////////////////////////////////// affichage côtés
            if (j == 0) {
                if ((i + 1) % 2 == 0) {
                    if (i == 1) {
                        printf("12%c%c%c%c%c%c%c%c", 255, 26, 255, 255, 255, 255, 255, 255);
                    } else if (i == 3) {
                        printf("11%c%c%c%c%c%c%c%c", 255, 26, 255, 255, 255, 255, 255, 255);
                    } else if (i == 5) {
                        printf("10%c%c%c%c%c%c%c%c", 255, 26, 255, 255, 255, 255, 255, 255);
                    }
                } else {
                    casevideafficher();
                }
            }
            ////////////////////////////////////////// affichage MILIEU
            printf("%c%c%c", plateau[i][j].mMgauche, plateau[i][j].mMgauche, plateau[i][j].mMgauche);

            if (i == *c11 && j == *c12) {
                printf("%c%c%c", 255, tableaucarajoueur[1], 255);
            } else if (i == *c21 && j == *c22) {
                printf("%c%c%c", 255, tableaucarajoueur[2], 255);
            } else if (i == *c31 && j == *c32) {
                printf("%c%c%c", 255, tableaucarajoueur[3], 255);
            } else if (i == *c41 && j == *c42) {
                printf("%c%c%c", 255, tableaucarajoueur[4], 255);
            } else {
                printf("%c%c%c", 255, plateau[i][j].mMmillieu, 255);
            }

            printf("%c%c%c", plateau[i][j].mMdroite, plateau[i][j].mMdroite, plateau[i][j].mMdroite);
            ////////////////////////////////////////////////////////////////////////////////////////////////////// affichage côtés
            if (j == 6) {
                if ((i + 1) % 2 == 0) {
                    if (i == 1) {
                        printf("%c%c%c%c4    ||||                                     |                                     ||||", 255, 255, 27, 255);
                    } else if (i == 3) {
                        printf("%c%c%c%c5    ||||Pour attraper un tresor appuyez sur 1|              %c%c%c%c%c%c%c%c%c              ||||", 255, 255, 27, 255, PieceRESTANTE.mMgauche, PieceRESTANTE.mMgauche, PieceRESTANTE.mMgauche, 255, PieceRESTANTE.mMmillieu, 255, PieceRESTANTE.mMdroite, PieceRESTANTE.mMdroite, PieceRESTANTE.mMdroite);
                    } else if (i == 5) {
                        printf("%c%c%c%c6    ||||   Sur votre case quand vous jouez   |                                     ||||", 255, 255, 27, 255);
                    }
                } else {
                    if (i == 2) {
                        printf("         ||||  Deplacez vous : Haut : 8, Bas : 5, |                                     ||||");
                    } else if (i == 4) {
                        printf("         |||| pour touner a droite: 6 et gauche:4 |                                     ||||");
                    }else if(i==6){
                        printf("         -----------------------------------------------------------------------------------");
                    }
                }
            }
            ///////////////////////////////////////////////////////////////////////////////////////////////////// affichage fin case
        }
        printf("\n");
        casevideafficher();
        for (int j = 0; j < COLONNES; j++) {
            mur();
            printf("%c%c%c", plateau[i][j].mBmillieu, plateau[i][j].mBmillieu, plateau[i][j].mBmillieu);
            mur();
        }
        if (i==0){
            printf("             ____________________________________   ____________________________________");
        }else if (i==6){
            printf("     ");
        }else if (i==1){
            printf("         ||||   Attrapez  vos tresors  respectifs |                                     ||||");
        }else if (i==2){
            printf("         ||||      Droite : 6, Gauche : 4.        |                                     ||||");
        }else if (i==3){
            printf("         ||||                                     |              %c%c%c%c%c%c%c%c%c              ||||", 178, 178, 178, PieceRESTANTE.mBmillieu, PieceRESTANTE.mBmillieu, PieceRESTANTE.mBmillieu, 178, 178, 178);
        }else if (i==4){
            printf("         ||||                                     |                                     ||||");
        }else if (i==5){
            printf("         ||||                                     |                                     ||||");
        }
        printf("\n");
    }
    //////////////////////////////////////////////////////////////////////////////////////// affichage dessous
    casevideafficher();
    casevideafficher();
    printf("%c%c%c%c%c%c%c%c", 255, 255, 255, 24, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c%c%c%c%c%c", 255, 255, 255, 24, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c%c%c%c%c%c\n", 255, 255, 255, 24, 255, 255, 255, 255);
    //
    casevideafficher();
    casevideafficher();
    printf("%c%c%c9%c%c%c%c", 255, 255, 255, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c8%c%c%c%c", 255, 255, 255, 255, 255, 255, 255);
    casevideafficher();
    printf("%c%c%c7%c%c%c%c\n", 255, 255, 255, 255, 255, 255, 255);
    //////////////////////////////////////////////////////////////////////////////////////// affichage dessous
}

void AfficherPieceRest(TUILE PieceRESTANTE) {
    printf("\n Voici votre main avec la piece restante\n");
    mur();
    printf("%c%c%c", PieceRESTANTE.mHmillieu, PieceRESTANTE.mHmillieu, PieceRESTANTE.mHmillieu);
    mur();
    printf("\n");
    printf("%c%c%c", PieceRESTANTE.mMgauche, PieceRESTANTE.mMgauche, PieceRESTANTE.mMgauche);
    printf("%c%c%c", 255, PieceRESTANTE.mMmillieu, 255);
    printf("%c%c%c", PieceRESTANTE.mMdroite, PieceRESTANTE.mMdroite, PieceRESTANTE.mMdroite);
    printf("\n");
    mur();
    printf("%c%c%c", PieceRESTANTE.mBmillieu, PieceRESTANTE.mBmillieu, PieceRESTANTE.mBmillieu);
    mur();
    printf("\n");
}


TUILE Orientationtuile(TUILE PieceRESTANTE, TUILE T, TUILE TGAUCHE, TUILE TDROITE, TUILE TBAS, TUILE I, TUILE ICOUCHE,
                       TUILE LDEPARTDROITE, TUILE LDEPARTGAUCHE, TUILE LDEPARTBASGAUCHE, TUILE LDEPARTBASDROITE) {
    int choix;
    TUILE MilieuTuile;
    MilieuTuile.mMmillieu=PieceRESTANTE.mMmillieu;
    printf("\nAvant de choisir ou mettre la piece choisissez l'orientation de la piece\n");
    do {
        printf("Appuyez sur 0 pour confirmer\n");
        scanf("%d", &choix);
        if (PieceRESTANTE.mMgauche == T.mMgauche && PieceRESTANTE.mMdroite==T.mMdroite && PieceRESTANTE.mHmillieu==T.mHmillieu &&
            PieceRESTANTE.mBmillieu==T.mBmillieu) {
            if (choix == 6) {
                PieceRESTANTE = TDROITE;
            } else if (choix == 4) {
                PieceRESTANTE = TGAUCHE;
            }
            //
        } else if (PieceRESTANTE.mMgauche == TGAUCHE.mMgauche && PieceRESTANTE.mMdroite==TGAUCHE.mMdroite && PieceRESTANTE.mHmillieu==TGAUCHE.mHmillieu &&
                   PieceRESTANTE.mBmillieu==TGAUCHE.mBmillieu) {
            if (choix == 6) {
                PieceRESTANTE = T;
            } else if (choix == 4) {
                PieceRESTANTE = TBAS;
            }
            //
        } else if (PieceRESTANTE.mMgauche == TBAS.mMgauche && PieceRESTANTE.mMdroite==TBAS.mMdroite && PieceRESTANTE.mHmillieu==TBAS.mHmillieu &&
                   PieceRESTANTE.mBmillieu==TBAS.mBmillieu) {
            if (choix == 6) {
                PieceRESTANTE = TGAUCHE;
            } else if (choix == 4) {
                PieceRESTANTE = TDROITE;
            }
            //
        } else if (PieceRESTANTE.mMgauche == TDROITE.mMgauche && PieceRESTANTE.mMdroite==TDROITE.mMdroite && PieceRESTANTE.mHmillieu==TDROITE.mHmillieu &&
                   PieceRESTANTE.mBmillieu==TDROITE.mBmillieu) {
            if (choix == 6) {
                PieceRESTANTE = TBAS;
            } else if (choix == 4) {
                PieceRESTANTE = T;
            }
            //
        } else if (PieceRESTANTE.mMgauche == I.mMgauche && PieceRESTANTE.mMdroite==I.mMdroite && PieceRESTANTE.mHmillieu==I.mHmillieu &&
                   PieceRESTANTE.mBmillieu==I.mBmillieu) {
            if (choix == 6) {
                PieceRESTANTE = ICOUCHE;
            } else if (choix == 4) {
                PieceRESTANTE = ICOUCHE;
            }
            //
        } else if (PieceRESTANTE.mMgauche == ICOUCHE.mMgauche && PieceRESTANTE.mMdroite==ICOUCHE.mMdroite && PieceRESTANTE.mHmillieu==ICOUCHE.mHmillieu &&
                   PieceRESTANTE.mBmillieu==ICOUCHE.mBmillieu) {
            if (choix == 6) {
                PieceRESTANTE = I;
            } else if (choix == 4) {
                PieceRESTANTE = I;
            }
            //
        }else if(PieceRESTANTE.mMgauche == LDEPARTBASDROITE.mMgauche && PieceRESTANTE.mMdroite==LDEPARTBASDROITE.mMdroite && PieceRESTANTE.mHmillieu==LDEPARTBASDROITE.mHmillieu &&
                 PieceRESTANTE.mBmillieu==LDEPARTBASDROITE.mBmillieu){
            if (choix == 6) {
                PieceRESTANTE = LDEPARTBASGAUCHE;
            } else if (choix == 4) {
                PieceRESTANTE = LDEPARTGAUCHE;
            }
            //
        }else if(PieceRESTANTE.mMgauche == LDEPARTBASGAUCHE.mMgauche && PieceRESTANTE.mMdroite==LDEPARTBASGAUCHE.mMdroite && PieceRESTANTE.mHmillieu==LDEPARTBASGAUCHE.mHmillieu &&
                 PieceRESTANTE.mBmillieu==LDEPARTBASGAUCHE.mBmillieu){
            if (choix == 6) {
                PieceRESTANTE = LDEPARTDROITE;
            } else if (choix == 4) {
                PieceRESTANTE = LDEPARTBASDROITE;
            }
            //
        }else if(PieceRESTANTE.mMgauche == LDEPARTDROITE.mMgauche && PieceRESTANTE.mMdroite==LDEPARTDROITE.mMdroite && PieceRESTANTE.mHmillieu==LDEPARTDROITE.mHmillieu &&
                 PieceRESTANTE.mBmillieu==LDEPARTDROITE.mBmillieu){
            if (choix == 6) {
                PieceRESTANTE = LDEPARTBASDROITE;
            } else if (choix == 4) {
                PieceRESTANTE = LDEPARTGAUCHE;
            }
        }else if(PieceRESTANTE.mMgauche == LDEPARTGAUCHE.mMgauche && PieceRESTANTE.mMdroite==LDEPARTGAUCHE.mMdroite && PieceRESTANTE.mHmillieu==LDEPARTGAUCHE.mHmillieu &&
                 PieceRESTANTE.mBmillieu==LDEPARTGAUCHE.mBmillieu){
            if (choix == 6) {
                PieceRESTANTE = LDEPARTDROITE;
            } else if (choix == 4) {
                PieceRESTANTE = LDEPARTBASGAUCHE;
            }
        }
        PieceRESTANTE.mMmillieu=MilieuTuile.mMmillieu;
        AfficherPieceRest(PieceRESTANTE);
    } while (choix!=0);
    return PieceRESTANTE;
}

TUILE InsererPiece(TUILE plateau[COLONNES][COLONNES], TUILE PieceRESTANTE, int *c11, int *c12,
                   char tableaucarajoueur[NOMBRE_JOUEUR_MAX], int *c21, int *c22, int *c31, int *c32, int *c41,
                   int *c42, TUILE T, TUILE TGAUCHE, TUILE TDROITE, TUILE TBAS, TUILE I, TUILE ICOUCHE,
                   TUILE LDEPARTDROITE, TUILE LDEPARTGAUCHE, TUILE LDEPARTBASGAUCHE, TUILE LDEPARTBASDROITE, char tableautresor[NOMBRE_CARTE_TRESOR], int*ctresor) {
    int choix;
    TUILE PieceRest;
    TUILE PieceRESTANTE2 = Orientationtuile(PieceRESTANTE, T, TGAUCHE, TDROITE, TBAS, I, ICOUCHE, LDEPARTDROITE, LDEPARTGAUCHE, LDEPARTBASGAUCHE, LDEPARTBASDROITE);
    PieceRESTANTE=PieceRESTANTE2;
    Afficherplateau(plateau, c11, c12, tableaucarajoueur, c21, c22, c31, c32, c41, c42, PieceRESTANTE,
                    tableautresor, ctresor);
    //////////////////////////////////////////////////////////////////////////////////////////   inserer orientation piece
    do {
        printf("Ou voulez vous mettre la piece ? Cliquez sur le numero entre 1 et 12.\n");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 12);
    if (choix == 12) {///////////////////////////////////////////////////////
        PieceRest = plateau[1][6];
        for (int i = 6; i > 0; i = i - 1) {
            plateau[1][i] = plateau[1][i - 1];
            plateau[1][i].mMmillieu = plateau[1][i - 1].mMmillieu;
        }
        if (*c11 == 1) {
            if(*c12 == 6) {
                *c12 = 0;
            }else{
                ++*c12;
            }
        } else if (*c21 == 1 ) {
            if(*c22 == 6) {
                *c22 = 0;
            }else{
                ++*c22;
            }
        } else if (*c31 == 1) {
            if(*c32 == 6) {
                *c32 = 0;
            }else{
                ++*c32;
            }
        } else if (*c41 == 1) {
            if(*c42 == 6) {
                *c42 = 0;
            }else{
                ++*c42;
            }
        }
        plateau[1][0] = PieceRESTANTE;///////////////////////////////////////
    } else if (choix == 11) {
        PieceRest = plateau[3][6];
        for (int i = 6; i > 0; i = i - 1) {
            plateau[3][i] = plateau[3][i - 1];
        }
        if (*c11 == 3 ) {
            if(*c12 == 6) {
                *c12 = 0;
            }else{
                ++*c12;
            }
        } else if (*c21 == 3) {
            if(*c22 == 6) {
                *c22 = 0;
            }else{
                ++*c22;
            }
        } else if (*c31 == 3) {
            if(*c32 == 6) {
                *c32 = 0;
            }else{
                ++*c32;
            }
        } else if (*c41 == 3) {
            if(*c42 == 6) {
                *c42 = 0;
            }else{
                ++*c42;
            }
        }
        plateau[3][0] = PieceRESTANTE;///////////////////////////////
    } else if (choix == 10) {
        PieceRest = plateau[5][6];
        for (int i = 6; i > 0; i = i - 1) {
            plateau[5][i] = plateau[3][i - 1];
        }
        if (*c11 ==5 ) {
            if(*c12 == 6) {
                *c12 = 0;
            }else{
                ++*c12;
            }
        } else if (*c21 == 5) {
            if(*c22 == 6) {
                *c22 = 0;
            }else{
                ++*c22;
            }
        } else if (*c31 == 5) {
            if(*c32 == 6) {
                *c32 = 0;
            }else{
                ++*c32;
            }
        } else if (*c41 == 5) {
            if(*c42 == 6) {
                *c42 = 0;
            }else{
                ++*c42;
            }
        }
        plateau[5][0] = PieceRESTANTE;//////////////////////////////
    } else if (choix == 4) {
        PieceRest = plateau[1][0];
        for (int i = 0; i < COLONNES; ++i) {
            plateau[1][i] = plateau[1][i + 1];
        }
        if (*c11 == 1 ) {
            if(*c12 == 0) {
                *c12 = 6;
            }else{
                --*c12;
            }
        } else if (*c21 == 1) {
            if(*c22 == 0) {
                *c22 = 6;
            }else{
                --*c22;
            }
        } else if (*c31 == 1) {
            if(*c32 == 0) {
                *c32 = 6;
            }else{
                --*c32;
            }
        } else if (*c41 == 1) {
            if(*c42 == 0) {
                *c42 = 6;
            }else{
                --*c42;
            }
        }
        plateau[1][6] = PieceRESTANTE;////////////////////////////////
    } else if (choix == 5) {
        PieceRest = plateau[3][0];
        for (int i = 0; i < COLONNES; ++i) {
            plateau[3][i] = plateau[3][i + 1];
        }
        if (*c11 == 3) {
            if(*c12 == 0) {
                *c12 = 6;
            }else{
                --*c12;
            }
        } else if (*c21 == 3) {
            if(*c22 == 0) {
                *c22 = 6;
            }else{
                --*c22;
            }
        } else if (*c31 == 3) {
            if(*c32 == 0) {
                *c32 = 6;
            }else{
                --*c32;
            }
        } else if (*c41 == 3) {
            if(*c42 == 0) {
                *c42 = 6;
            }else{
                --*c42;
            }
        }
        plateau[3][6] = PieceRESTANTE;///////////////////////
    } else if (choix == 6) {
        PieceRest = plateau[5][0];
        for (int i = 0; i < COLONNES; ++i) {
            plateau[5][i] = plateau[5][i + 1];
        }
        if (*c11 == 5 ) {
            if(*c12 == 0) {
                *c12 = 6;
            }else{
                --*c12;
            }
        } else if (*c21 == 5) {
            if(*c22 == 0) {
                *c22 = 6;
            }else{
                --*c22;
            }
        } else if (*c31 == 5) {
            if(*c32 == 0) {
                *c32 = 6;
            }else{
                --*c32;
            }
        } else if (*c41 == 5) {
            if(*c42 == 0) {
                *c42 = 6;
            }else{
                --*c42;
            }
        }
        plateau[5][6] = PieceRESTANTE;///////////////////////////////
    } else if (choix == 1) {
        PieceRest = plateau[6][1];
        for (int i = 6; i > 0; i = i - 1) {
            plateau[i][1] = plateau[i - 1][1];
        }
        if ( *c12 == 1) {
            if(*c11 == 6) {
                *c11 = 0;
            }else{
                ++*c11;
            }
        } else if (*c22 == 1) {
            if(*c21 ==6) {
                *c21 = 0;
            }else{
                ++*c21;
            }
        } else if (*c32 == 1) {
            if(*c31 == 6) {
                *c31 = 0;
            }else{
                ++*c31;
            }
        } else if (*c42 == 1) {
            if(*c41 == 6) {
                *c41 = 0;
            }else{
                ++*c41;
            }
        }
        plateau[0][1] = PieceRESTANTE;//////////////////////////////
    } else if (choix == 2) {
        PieceRest = plateau[6][3];
        for (int i = 6; i > 0; i = i - 1) {
            plateau[i][3] = plateau[i - 1][3];
        }
        if ( *c12 == 3) {
            if(*c11 == 6) {
                *c11 = 0;
            }else{
                ++*c11;
            }
        } else if (*c22 == 3) {
            if(*c21 ==6) {
                *c21 = 0;
            }else{
                ++*c21;
            }
        } else if (*c32 == 3) {
            if(*c31 == 6) {
                *c31 = 0;
            }else{
                ++*c31;
            }
        } else if (*c42 == 3) {
            if(*c41 == 6) {
                *c41 = 0;
            }else{
                ++*c41;
            }
        }
        plateau[0][3] = PieceRESTANTE;///////////////////////
    } else if (choix == 3) {
        PieceRest = plateau[6][5];
        for (int i = 6; i > 0; i = i - 1) {
            plateau[i][5] = plateau[i - 1][5];
        }
        if ( *c12 == 5) {
            if(*c11 == 6) {
                *c11 = 0;
            }else{
                ++*c11;
            }
        } else if (*c22 == 5) {
            if(*c21 ==6) {
                *c21 = 0;
            }else{
                ++*c21;
            }
        } else if (*c32 == 5) {
            if(*c31 == 6) {
                *c31 = 0;
            }else{
                ++*c31;
            }
        } else if (*c42 == 5) {
            if(*c41 == 6) {
                *c41 = 0;
            }else{
                ++*c41;
            }
        }
        plateau[0][5] = PieceRESTANTE;///////////////////////////////
    } else if (choix == 7) {
        PieceRest = plateau[0][5];
        for (int i = 0; i < COLONNES; ++i) {
            plateau[i][5] = plateau[i + 1][5];
        }
        if ( *c12 ==5) {
            if(*c11 == 0) {
                *c11 = 0;
            }else{
                --*c11;
            }
        } else if (*c22 == 5) {
            if(*c21 ==0) {
                *c21 = 0;
            }else{
                --*c21;
            }
        } else if (*c32 == 5) {
            if(*c31 == 0) {
                *c31 = 0;
            }else{
                --*c31;
            }
        } else if (*c42 == 5) {
            if(*c41 == 0) {
                *c41 = 0;
            }else{
                --*c41;
            }
        }
        plateau[6][5] = PieceRESTANTE;////////////////////////////
    } else if (choix == 8) {
        PieceRest = plateau[0][3];
        for (int i = 0; i < COLONNES; ++i) {
            plateau[i][3] = plateau[i + 1][3];
        }
        if ( *c12 ==3) {
            if(*c11 == 0) {
                *c11 = 0;
            }else{
                --*c11;
            }
        } else if (*c22 == 3) {
            if(*c21 ==0) {
                *c21 = 0;
            }else{
                --*c21;
            }
        } else if (*c32 == 3) {
            if(*c31 == 0) {
                *c31 = 0;
            }else{
                --*c31;
            }
        } else if (*c42 == 3) {
            if(*c41 == 0) {
                *c41 = 0;
            }else{
                --*c41;
            }
        }
        plateau[6][3] = PieceRESTANTE;///////////////////////////
    } else if (choix == 9) {
        PieceRest = plateau[0][1];
        for (int i = 0; i < COLONNES; ++i) {
            plateau[i][1] = plateau[i + 1][1];
        }
        if ( *c12 ==1) {
            if(*c11 == 0) {
                *c11 = 0;
            }else{
                --*c11;
            }
        } else if (*c22 == 1) {
            if(*c21 ==0) {
                *c21 = 0;
            }else{
                --*c21;
            }
        } else if (*c32 == 1) {
            if(*c31 == 0) {
                *c31 = 0;
            }else{
                --*c31;
            }
        } else if (*c42 == 1) {
            if(*c41 == 0) {
                *c41 = 0;
            }else{
                --*c41;
            }
        }
        plateau[6][1] = PieceRESTANTE;
    }
    return PieceRest;
}
 