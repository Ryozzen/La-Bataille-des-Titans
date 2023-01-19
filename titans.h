#ifndef __TITANS_H
#define __TITANS_h

/**
 * @struct Joueur
 * @brief Structure représentant un joueur dans un jeu
 * 
 * @var Joueur::x
 * Coordonnée en x du joueur
 * @var Joueur::y
 * Coordonnée en y du joueur
 * @var Joueur::nom
 * Nom du joueur
 */
struct Joueur {
  int x;
  int y;
  char nom[10];
};

/**
 * @struct Build
 * @brief Structure représentant une construction
 * 
 * @var Build::height
 * Hauteur de la construction
 * @var Build::width
 * Largeur de la construction
 */
struct Build {
  int height;
  int width;
};

void NomJoueurs();
void creeVille(char ville[45][80],struct Build Buildlist[10]);
void AffichageBat(int J1, int J2, char ville[45][80],struct Build BuildList[10]);
void AffichagePersos(struct Build BuildList[10],int coorTete[]);
void instruction ();
void trajectoire(struct Joueur *J1, struct Joueur *J2, int coorTete[],int scoreJ1,int scoreJ2) ;
void delai(float a);

#endif
