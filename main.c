#include <stdio.h>
#include <stdlib.h>

//Création des constantes définissant la taille du carré magique
#define TAILLE 5
#define TAILLETAB 25

//Création du type point, possédant des coordonnées du tableau
typedef struct{
    int x;
    int y;
}point;

//Initialisation des procédures et fonctions
void init(int tab2[TAILLE][TAILLE]);
int avancer(int tabMag[TAILLE][TAILLE]);
int corriger(int coordPosition);
void afficher(int tableau[TAILLE][TAILLE]);


int main()
//BUT : créer un carré magique : tableau dont la somme des valeurs de chaque ligne, colonne et diagonale est la même
//ENTREE : tableau de dimension TAILLExTAILLE, nombres de 1 à TAILLETAB
//SORTIE : tableau contenant les nombres de 1 à TAILLETAB, une seule fois
{
    //Création du tableau du carré magique
    int tabMagique[TAILLE][TAILLE];

    //Initialisation des valeurs du tableau à 0
    init(tabMagique);

    //Appel de la procédure attribuant les valeurs au tableau
    avancer(tabMagique);

    //Affichage du carré magique
    afficher(tabMagique);

    //Tout s'est correctement passé, on retourne 0
    return 0;
}


void init(int tab2[TAILLE][TAILLE])
//BUT : initialiser le tableau de valeurs
//ENTREE : tableau à deux dimensions
//SORTIE : tableau à deux dimensions aux valeurs initialisées à 0
{
    //Variables de boucle
    int i=0;
    int j=0;

    //Boucle attribuant 0 à toutes les cases du tableau
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            tab2[i][j]=0;
        }
    }
}


int avancer(int tabMag[TAILLE][TAILLE])
//BUT : placer les nombres dans le tableau
//ENTREE : valeurs du tableau
//SORTIE : valeurs mises à jour
{
    //Variable de boucle
    int i=0;

    //Création de la variable qui se déplace dans le tableau pour placer les valeurs
    point position;

    //On place le premier chiffre au milieu nord du tableau
    position.x=(TAILLE/2)-1;
    position.y=TAILLE/2;

    //Boucle de remplissage du tableau
    for(i=1;i<TAILLETAB+1;i++){

        //La case du tableau prend la valeur de i
        tabMag[position.x][position.y]=i;

        //On se déplace sur la case suivante, au nord-est
        position.x=corriger(position.x-1);
        position.y=corriger(position.y+1);

        //Si la case contient déjà un nombre, on va sur celle au nord-ouest
        if (tabMag[position.x][position.y]!=0){
            position.x=corriger(position.x-1);
            position.y=corriger(position.y-1);
            }
        }
    }


int corriger(int coordPosition)
//BUT : Faire en sorte que le placement des valeurs se fasse dans le tableau
//ENTREE : coordonnées de la case sur laquelle on vient de se déplacer
//SORTIE : coordonnées corrigées pour rester dans le tableau/carré magique
{
    switch (coordPosition){
        //Si la position est à -1, on va à la taille max du tableau
        case -1 :
            return TAILLE-1;
            break;

        //Si la position dépasse la taille max du tableau, on revient à 0
        case TAILLE :
            return 0;
            break;

        //Si la position est bien dans le tableau, on ne la change pas
        default :
            return coordPosition;
            break;
    }
}


void afficher(int tableau[TAILLE][TAILLE])
//BUT : Afficher le carré magique avec toutes ses valeurs
//ENTREE : tableau de valeurs
//SORTIE : affichage du tableau sous forme de carré magique
{
    //Variables d'incrémentation de la boucle
    int i=0;
    int j=0;

    //Boucle d'affichage du tableau
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            printf(" %d ",tableau[i][j]);
        }
        printf("\n");
    }
}

