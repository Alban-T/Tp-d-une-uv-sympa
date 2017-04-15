#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 3

typedef struct element
{
	int colonne;
	int valeur;
	struct element* suivant;
}Element;

typedef Element* Liste_ligne;

typedef struct matrice_creuse
{
    int Nlignes;
    int Ncolonnes;
	Liste_ligne* tab;
}Matrice_creuse;

Matrice_creuse* constructMatCreuse(int n,int m);
Liste_ligne* constructTab(int k);
Element* constructElement();
void constructMat(Matrice_creuse *m, int t[N][M],int Nlig, int Ncol);
void afficherMat(Matrice_creuse m);
void libererMat(Matrice_creuse m);
#endif // TP3_H_INCLUDED
