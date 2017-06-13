#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// variables nécessaires pour l'interface
int deb=0;
char choix;




// REPRESENTATION CLASSIQUE DE L'ABR


typedef struct sommet{ // strcuture "sommet de l'arbre"
    int val;
    struct sommet *fg; // fils gauche
    struct sommet *fd; // fils droit
    struct sommet *pere;
}Sommet;

typedef struct arbre{ // structure "ABR"
    Sommet *racine;
}Arbre;



Arbre* initABR(); // initialisation d'un ABR, renvoie un pointeur vers un ABR vide

Sommet* creerSommet(int cle); // création d'un sommet, renvoie un pointeur vers un nouveau sommet à partir d'un clé entrée en paramètre
void insererSommet(Arbre* a,Sommet* s); //insère un sommmet dans un ABR

void parcours_infixe(Sommet* s); // parcours des sommets de façon infixe avec affichage
void afficherArbre(Sommet* s); // affiche tous les éléments d'un arbre triés par ordre croissant


int rechercheSommet(Arbre* a,int cle); // vérifie si une clé exsite dans l'ABR

void compteur(Sommet* s,int* c); // compte le nombre de sommet à partir d'un sommet donné
int tailleArbre(Arbre* a); // renvoie le nombre d'octets utilisés pour représenter l'ABR


void libererArbre(Sommet* s); //libération de la mémoire allouée dynamiquement pour un arbre classique




// UNE REPRESENTATION PLUS COMPACTE


typedef struct sommetCompact{ // structure "sommet de l'arbre compacte"
	struct sommetCompact* fg; // fils gauche
	struct sommetCompact* fd; // fils droit
	struct sommetCompact* pere;
	int inf;
	int sup;
}SommetCompact;


typedef struct arbreCompact{ // structure "ABR compacte"
	SommetCompact* racine;
}ArbreCompact;

ArbreCompact* initABRCompact(); // initialisation d'un ABR compacte, renvoie un pointeur vers un ABR compacte vide

SommetCompact* creerSommetCompact(int cle); // création d'un sommet compacte, renvoie un pointeur vers un nouveau sommet à partir d'un clé entrée en paramètre

SommetCompact* minimum(SommetCompact* s); // renvoie le sommet ayant la clé minimale du sous-arbre compacte dont on donne la racine en paramètre
SommetCompact* maximum(SommetCompact* s); // renvoie le sommet ayant la clé maximale du sous-arbre compacte dont on donne la racine en paramètre
void insererElement(ArbreCompact* a, int c); // crée et insère un sommmet compacte dont la clé est entrée en paramètres dans un ABR compacte


void parcours_infixe_compact(SommetCompact* s); // parcours des sommets compactes de façon infixe avec affichage des intervalles
void afficherArbreCompact(SommetCompact* s); // affiche tous les éléments d'un arbre compactes triés par ordre croissant

int rechercheElement(ArbreCompact* a,int cle); // vérifie si une valeur exsite dans l'ABR compacte


 void compteurCompact(SommetCompact* s,int* c); // compte le nombre de sommet compacte à partir d'un sommet donné
 int tailleArbreCompacte(ArbreCompact* a); // renvoie le nombre d'octets utilisés pour représenter l'ABR compacte


void libererArbreCompact(SommetCompact* s); //libération de la mémoire allouée dynamiquement pour un arbre compacte


#endif // TP4_H_INCLUDED
