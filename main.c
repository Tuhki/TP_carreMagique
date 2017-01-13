#include <stdio.h>
#include <stdlib.h>

//Cr�ation des constantes d�finissant la taille du carr� magique
#define TAILLE 5
#define TAILLETAB 25

//Cr�ation du type point, poss�dant des coordonn�es du tableau
typedef struct{
    int x;
    int y;
}point;

//Initialisation des proc�dures et fonctions
void init(int tab2[TAILLE][TAILLE]);
int avancer(int tabMag[TAILLE][TAILLE]);
int corriger(int coordPosition);
void afficher(int tableau[TAILLE][TAILLE]);


int main()
//BUT : cr�er un carr� magique : tableau dont la somme des valeurs de chaque ligne, colonne et diagonale est la m�me
//ENTREE : tableau de dimension TAILLExTAILLE, nombres de 1 � TAILLETAB
//SORTIE : tableau contenant les nombres de 1 � TAILLETAB, une seule fois
{
    //Cr�ation du tableau du carr� magique
    int tabMagique[TAILLE][TAILLE];

    //Initialisation des valeurs du tableau � 0
    init(tabMagique);

    //Appel de la proc�dure attribuant les valeurs au tableau
    avancer(tabMagique);

    //Affichage du carr� magique
    afficher(tabMagique);

    //Tout s'est correctement pass�, on retourne 0
    return 0;
}


void init(int tab2[TAILLE][TAILLE])
//BUT : initialiser le tableau de valeurs
//ENTREE : tableau � deux dimensions
//SORTIE : tableau � deux dimensions aux valeurs initialis�es � 0
{
    //Variables de boucle
    int i=0;
    int j=0;

    //Boucle attribuant 0 � toutes les cases du tableau
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            tab2[i][j]=0;
        }
    }
}


int avancer(int tabMag[TAILLE][TAILLE])
//BUT : placer les nombres dans le tableau
//ENTREE : valeurs du tableau
//SORTIE : valeurs mises � jour
{
    //Variable de boucle
    int i=0;

    //Cr�ation de la variable qui se d�place dans le tableau pour placer les valeurs
    point position;

    //On place le premier chiffre au milieu nord du tableau
    position.x=(TAILLE/2)-1;
    position.y=TAILLE/2;

    //Boucle de remplissage du tableau
    for(i=1;i<TAILLETAB+1;i++){

        //La case du tableau prend la valeur de i
        tabMag[position.x][position.y]=i;

        //On se d�place sur la case suivante, au nord-est
        position.x=corriger(position.x-1);
        position.y=corriger(position.y+1);

        //Si la case contient d�j� un nombre, on va sur celle au nord-ouest
        if (tabMag[position.x][position.y]!=0){
            position.x=corriger(position.x-1);
            position.y=corriger(position.y-1);
            }
        }
    }


int corriger(int coordPosition)
//BUT : Faire en sorte que le placement des valeurs se fasse dans le tableau
//ENTREE : coordonn�es de la case sur laquelle on vient de se d�placer
//SORTIE : coordonn�es corrig�es pour rester dans le tableau/carr� magique
{
    switch (coordPosition){
        //Si la position est � -1, on va � la taille max du tableau
        case -1 :
            return TAILLE-1;
            break;

        //Si la position d�passe la taille max du tableau, on revient � 0
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
//BUT : Afficher le carr� magique avec toutes ses valeurs
//ENTREE : tableau de valeurs
//SORTIE : affichage du tableau sous forme de carr� magique
{
    //Variables d'incr�mentation de la boucle
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

