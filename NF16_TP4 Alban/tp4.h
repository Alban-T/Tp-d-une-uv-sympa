#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct sommet{
    int val;
    struct sommet *fg;
    struct sommet *fd;
    struct sommet *pere;
}Sommet;

typedef struct arbre{
    Sommet *racine;
}Arbre;

Arbre* initABR();

Sommet* creerSommet(int cle);

void insererSommet(Arbre* a,Sommet* s);

void afficherArbre(Arbre* a);

Sommet* min(Sommet* s);

void parcours_infixe(Sommet* s);

int rechercheSommet(Arbre* a,int cle);

void compteur(Sommet* s);

int tailleArbre(Arbre* a);

#endif // TP4_H_INCLUDED
