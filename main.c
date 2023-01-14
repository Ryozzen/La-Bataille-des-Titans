/*Déclaration des bibliotheques*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "console.h"
#include <time.h>
#include "titans.h"

struct Joueur{
    int x;
    int y;
    char nom[10];
};

struct Joueur creeJoueur()//n'importe ou on s'en fout
{
    srand(time(NULL));
    struct Joueur joueur;
    scanf(" %[^\n]s", joueur.nom);
    clrscr();
    joueur.x = rand()%2;
    joueur.y = 0;

    return joueur;
}

/*Programme Principale*/

int main()
{

    /* Creation des joueurs */
    settitle("--==== Bataille des Titans ====--");
    struct termsize taille;
    resetterminal();

    printf("Donnez le nom du premier joueur : ");
    struct Joueur J1 = creeJoueur();

    printf("Donnez le nom du deuxieme joueur : ");
    struct Joueur J2 = creeJoueur();
    /* Fin de la creation des joueurs */



    /* Creation de la Ville */
    char ville[45][80];
    creeVille(ville);
    /* Fin de la creation de la Ville */



    /* Affichage */
    Affichage(J1.x, J2.x, ville);
    /* Fin de l'affichage */
    

    while (getch() != 'q')
    {
        gotoxy(1,1);
        refresh();
        printf("\nAppuyez sur q pour quitter\n");
    }

    resetcolors();
    resetterminal();
    return 0;
}
