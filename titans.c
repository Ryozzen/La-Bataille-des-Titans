/*Déclaration des bibliotheques*/

#include "titans.h"
#include "console.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Structure*/

struct Build {
  int height;
  int width;
};

struct Joueur {
  int x;
  int y;
  char nom[];
};

/*Variable Globale*/

/*Fonction secondaires*/

int GetColor(struct Build *BuildList, int a) {
  int somme = 0, cpt = 0;
  int cpt2;
  for (cpt2 = 0; cpt2 < 10; cpt2++) {
    somme += BuildList[cpt2].width;
    if (a <= somme) {
      return cpt;
    } else {
      cpt++;
      somme++;
    }
  }
}

void delai(float nbsecondes) {
  float pause = nbsecondes * (float)(CLOCKS_PER_SEC);
  clock_t start_time = clock();
  while (clock() < start_time + pause);
}

/*Fonctions Principales*/

void creeVille(char ville[45][80],struct Build BuildList[10]) {
  int i, j, k;
  const int NBRBuild = 10, L = 80, H = 45;

  srand(time(NULL));

  // Initialisation
  for (i = 0; i < H; i++) {
    for (j = 0; j < L; j++) {
      ville[i][j] = ' ';
    }
  }

  int valeur[] = {5, 5, 7, 7, 7, 7, 7, 7, 9, 9};
  int nbValeur = NBRBuild;
  int randIndex;

  // generation
  for (i = 0; i < NBRBuild; i++) {

    // générer ses coo
    // générer sa hauteur
    BuildList[i].height = 5 + rand() % 16;
    randIndex = rand() % nbValeur;
    BuildList[i].width = valeur[randIndex];

    // retire la valeur que l'on vient de prendre
    for (j = randIndex; j < nbValeur - 1; j++) {
      *(valeur + j) = *(valeur + j + 1);
    }
    nbValeur--;
  }

  // remplir la ville avec les buildings
  // On passe en revue les buildings

  int Xoffset = 0;
  for (i = 0; i < NBRBuild; i++) {
    for (j = 0; j < BuildList[i].height; j++) {
      for (k = 0; k < BuildList[i].width; k++) {
        if (Xoffset + k < L) {
          ville[j][Xoffset + k] = '=';
        }
      }
    }
    Xoffset += BuildList[i].width + 1;
  }
}

void AffichageBat(int J1, int J2, char ville[45][80],struct Build BuildList[10]) {
  int i, j, k;
  const int NBRBuild = 10, L = 80, H = 45;

  srand(time(NULL));
  
  // initialisation de la buildList
  for (i = 0; i < NBRBuild; i++) {
    BuildList[i].height = 0;
    BuildList[i].width = 0;
  }

  int cpt = 0;

  for (j = 0; j < 80; j++) {
    if (ville[0][j] != ' ') {
      BuildList[cpt].width++;
    } else {
      k = 0;
      while (ville[k][j - 1] != ' ') {
        k++;
        BuildList[cpt].height++;
      }
      cpt++;
    }
  }

  // Affichage des batiments
  int color[NBRBuild];

  for (i = 0; i < NBRBuild; i++) {
    color[i] = (rand() % 5) + 30;
  }

  for (i = H - 1; i >= 0; i--) {
    for (j = 0; j < L; j++) {
      setfontcolor(color[GetColor(BuildList, j)]);
      printf("%c", ville[i][j]);
    }
    if (i != 0) {
      printf("\n");
    }
  }
  setfontcolor(37);
}

void AffichagePersos(struct Build BuildList[10],int coorTete[]) {
  int i;
  const int NBRBuild = 10, L = 80, H = 45;

  srand(time(NULL));

  int RandPos = 1 + rand() % 2; // aléatoire entre 1 et 2
  int PosX = 0;
  for (i = 0; i < RandPos; i++) {
    PosX += BuildList[i].width + 1;
  }
  gotoxy(PosX + ((BuildList[RandPos].width - 1) / 2) - 1,
         H - 4 - BuildList[RandPos].height); // H - 4 pour la taille du personnage
  printf("/\\-/\\");
  gotoxy(PosX + ((BuildList[RandPos].width - 1) / 2) - 1,
         H - 3 - BuildList[RandPos].height);
  printf("\\* */");
  gotoxy(PosX + ((BuildList[RandPos].width - 1) / 2) - 1,
         H - 2 - BuildList[RandPos].height);
  printf(" \\-/");
  gotoxy(PosX + ((BuildList[RandPos].width - 1) / 2) - 1,
         H - 1 - BuildList[RandPos].height);
  printf("//_\\\\");
  gotoxy(PosX + ((BuildList[RandPos].width - 1) / 2) - 1,
         H - 0 - BuildList[RandPos].height);
  printf(" | | ");

  int RandPos2 = 7 + rand() % 2; // aléatoire entre 7 et 8
  int PosX2 = 0;
  for (i = 0; i < RandPos2; i++) {
    PosX2 += BuildList[i].width + 1;
  }

  gotoxy(PosX2 + ((BuildList[RandPos2].width - 1) / 2) - 1,
         H - 4 - BuildList[RandPos2].height);  // H - 4 pour la taille du personnage
  printf("/\\-/\\");
  gotoxy(PosX2 + ((BuildList[RandPos2].width - 1) / 2) - 1,
         H - 3 - BuildList[RandPos2].height);
  printf("\\o.o/");
  gotoxy(PosX2 + ((BuildList[RandPos2].width - 1) / 2) - 1,
         H - 2 - BuildList[RandPos2].height);
  printf(" \\-/");
  gotoxy(PosX2 + ((BuildList[RandPos2].width - 1) / 2) - 1,
         H - 1 - BuildList[RandPos2].height);
  printf("//_\\\\");
  gotoxy(PosX2 + ((BuildList[RandPos2].width - 1) / 2) - 1,
         H - 0 - BuildList[RandPos2].height);
  printf(" | | ");

  coorTete[0] = (PosX + ((BuildList[RandPos].width - 1) / 2) - 1) + 5;
  coorTete[1] = BuildList[RandPos].height + 4;
  coorTete[2] = PosX2 + ((BuildList[RandPos2].width - 1) / 2) - 2;
  coorTete[3] = BuildList[RandPos2].height + 4;
  coorTete[4] = PosX + ((BuildList[RandPos].width - 1) / 2) - 1;
  coorTete[5] =  H - 1 - BuildList[RandPos].height;
  coorTete[6] = PosX2 + ((BuildList[RandPos2].width - 1) / 2) - 1;
  coorTete[7] = H - 1 - BuildList[RandPos2].height;
}

void instruction (){
    gotoxy(1, 1);
    printf("Appuyez sur t pour tirer\n");
    printf("Appuyez sur q pour quitter\n");
}

void trajectoire(struct Joueur *J1, struct Joueur *J2, int coorTete[])  {

  int tour = 1;
  nostdoutbuff();
  double x, y, t, v0, alpha;
  const float g = 10;
  
  int scoreJ1 = 0, scoreJ2 = 0;

  if (getch() == 't' && tour == 1) {

  gotoxy(8,8);
  printf("%s\n", J1->nom);
  gotoxy(8,9);
  printf("Score J1 : %d", scoreJ1);

  gotoxy(62,8);
  printf("%s\n", J2->nom);
  gotoxy(62,9);
  printf("Score J2 : %d", scoreJ2);

  gotoxy(coorTete[6],coorTete[7]);
  printf("//_\\\\");
    
  gotoxy(coorTete[4],coorTete[5]);
  printf("\\/_\\\\");
    
  gotoxy(1,1);
  clrline();
  gotoxy(1,2);
  clrline();
  gotoxy(1, 1);
  printf("Donnez la vitesse du projectile ( entre 1.0 et 100.0 m/s ) : ");
  scanf("%lf", &v0);
  gotoxy(1, 1);
  clrline();
    
  for (int j = 0; j < 80; j++)
    printf("\b");

  gotoxy(1, 1);
  printf("Donnez l'angle du projectile ( entre 1 et 89 degre ) : ");
  scanf("%lf", &alpha);
  gotoxy(1, 1);
  clrline();
    
  for (int j = 0; j < 80; j++)
    printf("\b");

  if (v0 > 100.0) {
    v0 = 100.0;
  }
  if (v0 < 1.0) {
    v0 = 1.0;
  }
  if (alpha > 89.0) {
    alpha = 89.0;
  }
  if (alpha < 1.0) {
    alpha = 1.0;
  }
  gotoxy(1, 1);
  printf("Vitesse et angle choisis : %f m/s et %f degre ", v0, alpha);
  }

  alpha = alpha * M_PI / 180.0;
  
  for (t = 0.0; t <= 45.0; t = t + 0.1) {
      x = v0 * cos(alpha) * t + coorTete[0];
      y =(- 0.5) * g * (t*t) + v0 * sin(alpha) * t + coorTete[1];
      if (x > 0 && x < 80 && y > 0) 
      {
        gotoxy(x,45 - y);
        printf("*");
        delai(0.01);
      }
  }
    
  for (t = 0.0; t <= 45.0; t = t + 0.1) {
      x = v0 * cos(alpha) * t + coorTete[0];
      y =(- 0.5) * g * (t*t) + v0 * sin(alpha) * t + coorTete[1];
      if (x > 0 && x < 80 && y > 0) 
      {
        gotoxy(x,45 - y);
        printf(" ");
        delai(0.001);
      }
  }

  scoreJ1 = scoreJ1 + 1;
  tour = 2;
  flushstdin(); 
  gotoxy(1, 1);
  clrline();
  setstdoutbuff();

  if (getch() == 't' && tour == 2) {

  gotoxy(8,8);
  printf("%s\n", J1->nom);
  gotoxy(8,9);
  printf("Score J1 : %d", scoreJ1);  

  gotoxy(62,8);
  printf("%s\n", J2->nom);
  gotoxy(62,9);
  printf("Score J2 : %d" , scoreJ2);

  gotoxy(coorTete[4],coorTete[5]);
  printf("//_\\\\");

  gotoxy(coorTete[6],coorTete[7]);
  printf("//_\\/");
    
  gotoxy(1,1);
  clrline();
  gotoxy(1,2);
  clrline();
    
  gotoxy(1, 1);
  printf("Donnez la vitesse du projectile ( entre 1.0 et 100.0 m/s ) : ");
  scanf("%lf", &v0);
  gotoxy(1, 1);
  clrline();
  for (int j = 0; j < 80; j++)
    printf("\b");

  gotoxy(1, 1);
  printf("Donnez l'angle du projectile ( entre 1 et 89 degre ) : ");
  scanf("%lf", &alpha);
  gotoxy(1, 1);
  clrline();
    
  for (int j = 0; j < 80; j++)
    printf("\b");

  if (v0 > 100.0) {
    v0 = 100.0;
  }
  if (v0 < 1.0) {
    v0 = 1.0;
  }
  if (alpha > 89.0) {
    alpha = 89.0;
  }
  if (alpha < 1.0) {
    alpha = 1.0;
  }
  gotoxy(1, 1);
  printf("Vitesse et angle choisis : %f m/s et %f degre ", v0, alpha);
  }

  alpha = alpha * M_PI / 180.0;
  
  for (t = 0.0; t <= 45.0; t = t + 0.1) {
      x = -(v0 * cos(alpha) * t) + coorTete[2];
      y =(- 0.5) * g * (t*t) + v0 * sin(alpha) * t + coorTete[3];
      if (x > 0 && x < 80 && y > 0) 
      {
        gotoxy(x,45 - y);
        printf("*");
        delai(0.01);
      }
  }
   
  for (t = 0.0; t <= 45.0; t = t + 0.1) {
      x = -(v0 * cos(alpha) * t) + coorTete[2];
      y =(- 0.5) * g * (t*t) + v0 * sin(alpha) * t + coorTete[3];
      if (x > 0 && x < 80 && y > 0) 
      {
        gotoxy(x,45 - y);
        printf(" ");
        delai(0.001);
      }
  }

  scoreJ2 = scoreJ2 + 1;
  tour = 1;
  flushstdin(); 
  gotoxy(1, 1);
  clrline();
  setstdoutbuff();
}

