#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// variables n�cessaires pour l'interface
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

Sommet* creerSommet(int cle); // cr�ation d'un sommet, renvoie un pointeur vers un nouveau sommet � partir d'un cl� entr�e en param�tre
void insererSommet(Arbre* a,Sommet* s); //ins�re un sommmet dans un ABR

void parcours_infixe(Sommet* s); // parcours des sommets de fa�on infixe avec affichage
void afficherArbre(Sommet* s); // affiche tous les �l�ments d'un arbre tri�s par ordre croissant


int rechercheSommet(Arbre* a,int cle); // v�rifie si une cl� exsite dans l'ABR

void compteur(Sommet* s,int* c); // compte le nombre de sommet � partir d'un sommet donn�
int tailleArbre(Arbre* a); // renvoie le nombre d'octets utilis�s pour repr�senter l'ABR


void libererArbre(Sommet* s); //lib�ration de la m�moire allou�e dynamiquement pour un arbre classique




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

SommetCompact* creerSommetCompact(int cle); // cr�ation d'un sommet compacte, renvoie un pointeur vers un nouveau sommet � partir d'un cl� entr�e en param�tre

SommetCompact* minimum(SommetCompact* s); // renvoie le sommet ayant la cl� minimale du sous-arbre compacte dont on donne la racine en param�tre
SommetCompact* maximum(SommetCompact* s); // renvoie le sommet ayant la cl� maximale du sous-arbre compacte dont on donne la racine en param�tre
void insererElement(ArbreCompact* a, int c); // cr�e et ins�re un sommmet compacte dont la cl� est entr�e en param�tres dans un ABR compacte


void parcours_infixe_compact(SommetCompact* s); // parcours des sommets compactes de fa�on infixe avec affichage des intervalles
void afficherArbreCompact(SommetCompact* s); // affiche tous les �l�ments d'un arbre compactes tri�s par ordre croissant

int rechercheElement(ArbreCompact* a,int cle); // v�rifie si une valeur exsite dans l'ABR compacte


 void compteurCompact(SommetCompact* s,int* c); // compte le nombre de sommet compacte � partir d'un sommet donn�
 int tailleArbreCompacte(ArbreCompact* a); // renvoie le nombre d'octets utilis�s pour repr�senter l'ABR compacte


void libererArbreCompact(SommetCompact* s); //lib�ration de la m�moire allou�e dynamiquement pour un arbre compacte


#endif // TP4_H_INCLUDED
