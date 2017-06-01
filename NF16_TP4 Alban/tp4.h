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

void compteur(Sommet* s,int* c);

int tailleArbre(Arbre* a);


typedef struct sommetCompact{
	struct sommetCompact* fg;
	struct sommetCompact* fd;
	struct sommetCompact* pere;
	int inf;
	int sup;
}SommetCompact;


typedef struct arbreCompact{
	SommetCompact* racine;
}ArbreCompact;

ArbreCompact* initABRCompact();

SommetCompact* creerSommetCompact(int cle);

SommetCompact* minimum(SommetCompact* s);

SommetCompact* maximum(SommetCompact* s);

void insererElement(ArbreCompact* a, int c);

void parcours_infixe_compact(SommetCompact* s);

void afficherArbreCompact(ArbreCompact* a);

int rechercheElement(ArbreCompact* a,int cle);

void compteurCompact(SommetCompact* s,int* c);

int tailleArbreCompact(ArbreCompact* a);

#endif // TP4_H_INCLUDED
