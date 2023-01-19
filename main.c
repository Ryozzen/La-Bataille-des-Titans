/*Déclaration des bibliotheques*/
#include "console.h"
#include "titans.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Joueur {
  int x;
  int y;
  char nom[10];
};

struct Joueur creeJoueur() {
  srand(time(NULL));
  struct Joueur joueur;
  scanf(" %[^\n]s", joueur.nom);
  clrscr();
  joueur.x = rand() % 2;
  joueur.y = 0;

  return joueur;
}

struct Build {
  int height;
  int width;
};

struct Build BuildList[10];


/*Programme Principale*/

int main() {

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
  int NBRBuild = 10;
  int i;
  for (i = 0; i < NBRBuild; i++) {
    BuildList[i].height = 0;
    BuildList[i].width = 0;
  }
  char ville[45][80];
  creeVille(ville,BuildList);
  /* Fin de la creation de la Ville */

  /* Affichage */
  AffichageBat(J1.x, J2.x, ville,BuildList);
  int coorTete[8];
  AffichagePersos(BuildList, coorTete);
  /* Fin de l'affichage */
  
  char fin = '\0';
  while (fin != 'q') {
    fin = getch();
    trajectoire(&J1,&J2,coorTete);
  }

  resetcolors();
  resetterminal();
  return 0;
}
