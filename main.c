/*Déclaration des bibliotheques*/
#include "console.h"
#include "titans.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief creeJoueur permet de créer une structure Joueur en récupérant son nom,
 * en initialisant sa coordonnée x aléatoirement
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

  hidecursor();
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
  creeVille(ville, BuildList);
  /* Fin de la creation de la Ville */

  /* Affichage */
  AffichageBat(J1.x, J2.x, ville, BuildList);
  int coorTete[8];
  AffichagePersos(BuildList, coorTete);
  /* Fin de l'affichage */

  /* Deroulement de la partie */
  int tour = 1;
  int scoreJ1 = 0, scoreJ2 = 0;
  char action = '\0';

  gotoxy(1, 1);
  printf("h pour afficher les commandes");

  do {
	action = getch();
	if (action == 'h') {
  	gotoxy(1, 1);
  	clrline();
  	instruction();
	} else if (action == 't') {
  	if (tour % 2 == 1) { // J1
    	if (trajectoire(coorTete, tour, ville) != 2)
      	scoreJ1++;
    	else
      	break;
  	} else { // J2
    	if (trajectoire(coorTete, tour, ville) != 2)
      	scoreJ2++;
    	else
      	break;
  	}
  	tour++;
  	AfficheScore(&J1, &J2, scoreJ1, scoreJ2);
	}
  } while (action != 'q');
  /* Fin de la partie */

  resetcolors();
  resetterminal();
  gotoxy(1, 1);

  if (action == 'q') {
   	 
    	printf("La partie a ete abandonné\n");
    	return 0;

	}

  if (tour % 2 == 1) { 
    printf("%s a gagné avec un score de %d !", J1.nom, scoreJ1); 
    for (i=0; i< 20; i++) { 
      animationJ1(); 
      } 
    } else { 
    printf("%s a gagné avec un score de %d !", J2.nom, scoreJ2); 
    for (i=0; i< 20; i++) { 
      animationJ2(); 
      } 
    }

	printf("\n");
 
  return 0;
}





