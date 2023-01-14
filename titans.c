/*Déclaration des bibliotheques*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "console.h"
#include <time.h>
#include "titans.h"

/*Structure*/

struct Build{
    int height;
    int width;
    };

struct Joueur{
    int x;
    int y;
    char nom[];
};


/*Variable Globale*/
int coorTete[4];


/*Fonction secondaires*/

int GetColor(struct Build *BuildList, int a){
    int somme = 0, cpt = 0;
    int cpt2;
    for (cpt2 = 0; cpt2< 10 ; cpt2++){
        somme += BuildList[cpt2].width;
        if ( a <= somme ){
            return cpt;
        }
        else {
            cpt++;
            somme++;
        }
    }  
}

void delai(int nbsecondes)
{
    int pause = nbsecondes * CLOCKS_PER_SEC;
    clock_t start_time = clock();
    while (clock() < start_time + pause);
}

/*Fonctions Principales*/

void creeVille(char ville[45][80])
{
    int i,j,k;
    const int NBRBuild = 10, L =80, H = 45;

    srand(time(NULL));
    struct Build BuildList[NBRBuild];

    //initialisation de la buildList
    for(i =0;i<NBRBuild;i++){
        BuildList[i].height = -1;
        BuildList[i].width = -1;
    }

    //Initialisation
    for(i = 0; i < H; i++){ 
        for(j = 0; j < L; j++){ 
            ville[i][j] = ' ';
        }
    }

    int valeur[] = {5,5,7,7,7,7,7,7,9,9};
    int nbValeur = NBRBuild;
    int randIndex;

    //generation
    for(i = 0;i < NBRBuild; i++){

        //générer ses coo 
        //générer sa hauteur
        BuildList[i].height = 5 + rand()%16;
        randIndex = rand()%nbValeur; 
        BuildList[i].width = valeur[randIndex];

        //retire la valeur que l'on vient de prendre
        for (j = randIndex;j < nbValeur - 1;j++){
            *(valeur + j) = *(valeur + j + 1);
        }
        nbValeur--;
    }
    
    //remplir la ville avec les buildings
    //On passe en revue les buildings

    int Xoffset = 0;
    for(i = 0;i < NBRBuild;i++){
        for(j = 0;j<BuildList[i].height;j++){
                for(k = 0;k < BuildList[i].width;k++){ 
                    if (Xoffset + k < L){
                        ville[j][Xoffset+k] = '='; 
                    }   
                }            
        }
        Xoffset += BuildList[i].width+1;  
    }
}



void Affichage(int J1,int J2, char ville[45][80])
{
    int i,j,k;
    const int NBRBuild = 10, L = 80, H = 45;

    srand(time(NULL));
    struct Build BuildList[NBRBuild];

    //initialisation de la buildList
    for(i =0;i<NBRBuild;i++){
        BuildList[i].height = 0;
        BuildList[i].width = 0;
    }

    int cpt = 0;

    for(j = 0; j< 80; j++){
        if (ville[0][j] != ' ') {
            BuildList[cpt].width++;
        }   
        else {
            k=0;
            while (ville[k][j-1] != ' '){
                k++;
                BuildList[cpt].height++;  
            }
            cpt++;
        }      
    }

    //Affichage
    int color[NBRBuild];

    for (i = 0; i < NBRBuild; i++)
    {
        color[i] = (rand()% 5) + 30;
    }

    for(i = H-1;i >= 0;i--){ 
        for(j = 0; j < L; j++){ 
            setfontcolor(color[GetColor(BuildList, j)]);
            printf("%c",ville[i][j]); 
        }
        if (i != 0){
        printf("\n");
        }
    }
    setfontcolor(37);




    int RandPos = 1 + rand()%2; // aléatoire entre 1 et 2
    int PosX = 0;
    for (i = 0; i < RandPos; i++){
        PosX += BuildList[i].width + 1;
    }
    gotoxy(PosX + ((BuildList[RandPos].width -1) / 2)-1 , H - 4 - BuildList[RandPos].height); // H - 4 pour la taille du personnage
    printf("/\\-/\\");
    gotoxy(PosX + ((BuildList[RandPos].width -1) / 2)-1 , H - 3 - BuildList[RandPos].height);
    printf("\\* */");
    gotoxy(PosX + ((BuildList[RandPos].width -1) / 2)-1 , H - 2 - BuildList[RandPos].height);
    printf(" \\-/");
    gotoxy(PosX + ((BuildList[RandPos].width -1) / 2)-1 , H - 1 - BuildList[RandPos].height);
    printf("\\/ \\/");
    gotoxy(PosX + ((BuildList[RandPos].width -1) / 2)-1 , H - 0 - BuildList[RandPos].height);
    printf("/_*_\\");


    int RandPos2 = 7 + rand()%2; // aléatoire entre 7 et 8
    int PosX2 = 0;
    for (i = 0; i < RandPos2;i++){
        PosX2 += BuildList[i].width + 1 ;
    }
    
    gotoxy(PosX2 + ((BuildList[RandPos2].width -1) / 2)-1 , H - 4 - BuildList[RandPos2].height); // H - 4 pour la taille du personnage
    printf("/\\-/\\");
    gotoxy(PosX2 + ((BuildList[RandPos2].width -1) / 2)-1 , H - 3 - BuildList[RandPos2].height);
    printf("\\o.o/");
    gotoxy(PosX2 + ((BuildList[RandPos2].width -1) / 2)-1 , H - 2 - BuildList[RandPos2].height);
    printf(" \\-/");
    gotoxy(PosX2 + ((BuildList[RandPos2].width -1) / 2)-1 , H - 1 - BuildList[RandPos2].height);
    printf("\\/ \\/");
    gotoxy(PosX2 + ((BuildList[RandPos2].width -1) / 2)-1 , H - 0 - BuildList[RandPos2].height);
    printf("/_o_\\");

    coorTete[0] = PosX + BuildList[RandPos].width;
    coorTete[1] = H - 4 - BuildList[RandPos].height;
    coorTete[2] = PosX2 + BuildList[RandPos2].width -1;
    coorTete[3] = H - 4 - BuildList[RandPos2].height;

    gotoxy(0,10);
}

void refresh()
{
    int i,k;
    float vitesse, angle;
    const float g = 10;
    if (getch() == 't')
    {
        printf("Donnez la vitesse du projectile ( entre 1.0 et 100.0 m/s ) : ");
        scanf("%f", &vitesse);
        printf("Donnez l'angle du projectile ( entre 1 et 89 degre ) : ");
        scanf("%f", &angle);
        if (vitesse > 100.0){
            vitesse = 100.0;
        }
        if (vitesse < 1.0){
            vitesse = 1.0;
        }
        if (angle > 89.0){
            angle = 89.0;
        }
        if (angle < 1.0){
            angle = 1.0;
        }
        printf("Vitesse et angle choisis : %f m/s et %f degre ", vitesse, angle);
        angle = angle * (M_PI/180);
    }

    double traj[80 - coorTete[0] + 1];

    for (i=coorTete[0]; i<=80; i++){
        double x =i;
        double t = x/(vitesse * cos(angle));
        double y = vitesse * sin(angle) * t - 0.5 * g * t * t;
        traj[i] = y;
        printf("%f %f\n", x,y);
    }

    for (i = coorTete[0] + 1; i < 80; i++){
        delai(1);
        if (traj[i - coorTete[0]] < 45 && traj[i - coorTete[0]] > 0)
        {
            gotoxy(i,45-(coorTete[1]+traj[i-coorTete[0]]));
            printf("*");
        }   
        if(i != 1){
            gotoxy(i - 1,45-(coorTete[1]+traj[i-1-coorTete[0]]));
            printf(" ");
        }
    }

}







 









