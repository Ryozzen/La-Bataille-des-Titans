/*Déclaration des bibliotheques*/
#include "console.h"
#include "titans.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief creeJoueur permet de créer une structure Joueur en récupérant son nom, en initialisant ses coordonnées x et y aléatoirement
 * @return La structure Joueur créée
 */
struct Joueur creeJoueur() {
  srand(time(NULL));
  struct Joueur joueur;
  scanf(" %[^\n]s", joueur.nom);
  clrscr();
  joueur.x = rand() % 2;
  joueur.y = 0;

  return joueur;
}

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

  /* Deroulement de la partie */
  char fin = '\0', aide = '\0';
  fin = getch();
  aide = getch();
  int tour = 1;
  int scoreJ1 = 0, scoreJ2 = 0;
  
  while (fin != 'q') {
    
  if (aide == 'h') {
    instruction();
  }
    trajectoire(&J1,&J2,coorTete,scoreJ1, scoreJ2);   
  }
  /* Fin de la partie */

  resetcolors();
  resetterminal();
  return 0;
}