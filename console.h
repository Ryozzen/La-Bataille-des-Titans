/*
 * console.h
 * PoPS ESR v1.3
 *
 */

#ifndef __CONSOLE_H
#define __CONSOLE_H

#define BLACK   30
#define RED     31
#define GREEN   32
#define YELLOW  33
#define BLUE    34
#define MAGENTA 35
#define CYAN    36
#define WHITE   37

/* Couleurs supplémentaires
 * ce sont les mêmes qui sont utilisées
 * pour le mode "bold" de la police de caractères
 */
#define BRIGHTBLACK   90
#define BRIGHTRED     91
#define BRIGHTGREEN   92
#define BRIGHTYELLOW  93
#define BRIGHTBLUE    94
#define BRIGHTMAGENTA 95
#define BRIGHTCYAN    96
#define BRIGHTWHITE   97

#define BLOCK_BLINK     1
#define BLOCK           2
#define UNDERLINE_BLINK 3
#define UNDERLINE       4
#define BAR_BLINK       5
#define BAR             6
#define INVERT          7
#define HIDDEN          8

#define TRUE    1
#define FALSE   0

struct termsize {
    int cols;
    int rows;
};


void wait(void);

void clrscr(void);

void gotoxy(int x, int y);

void setfontcolor(int color);

void setbgrcolor(int color);

void setfontbold(int status);

void setunderline(int status);

void setblink(int status);

void settitle(char const* title);

void hidecursor(void);
void unhidecursor(void);

void setcurshape(int shape);

struct termsize gettermsize(void);

int getch(void);

int getche(void);

void clrline(void);

void resetcolors(void);
void resetterminal(void);

void nostdoutbuff(void);
void setstdoutbuff(void);
void flushstdin(void);
#endif
