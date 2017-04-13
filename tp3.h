#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 2

typedef struct element
{
	int colonne;
	int valeur;
	struct element* suivant;
}Element;

typedef struct liste_ligne
{
	Element* ligne;
}Liste_ligne;

typedef struct matrice_creuse
{
	Liste_ligne* tab;
	int Nlignes;
	int Ncolonnes;
}Matrice_creuse;

void constructMat(Matrice_creuse *m, int t[N][M],int Nlig, int Ncol);
void afficherMat(Matrice_creuse m);
#endif // TP3_H_INCLUDED
