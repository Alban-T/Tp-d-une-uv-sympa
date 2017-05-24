#include "tp4.h"

Arbre* initABR(){
	Arbre *newArbre=malloc(sizeof(Arbre));
	if(!newArbre){
		printf("Erreur de creation de l'arbre\n");
		return NULL;
	}
	newArbre->racine=NULL;
	return newArbre;
}

Sommet* creerSommet(int cle){
	Sommet* newSommet=malloc(sizeof(Sommet));
	if(!newSommet){
		printf("Erreur de creation du sommet\n");
		return NULL;
	}
	newSommet->val=cle;
	newSommet->fg=NULL;
	newSommet->fd=NULL;
	newSommet->pere=NULL;
	return newSommet;
}

void insererSommet(Arbre* a,Sommet* s){
	Sommet* actuel=a->racine;
	if(actuel==NULL){
		a->racine=s;
		printf("le sommet inserer est la racine de l'arbre, val=%d\n",s->val);
	}
	else{
		Sommet* prev=NULL;
		while(actuel!=NULL){
			prev=actuel;
			if(actuel->val<s->val)
				actuel=actuel->fd;
			else
				actuel=actuel->fg;
		}
		if(prev->val==s->val){
			printf("On ne peut pas avoir 2fois  la meme valeur dans le meme arbre\n");
			exit(1);
		}
		else{
			s->pere=prev;
			if(s->val<prev->val)
				prev->fg=s;
			else
				prev->fd=s;
			printf("vous avez bien inserer le sommet, val=%d, val(pere)=%d\n",s->val,s->pere->val);
		}
	}
}

Sommet* min(Sommet* s){
	Sommet* actuel=s;
	if(actuel==NULL)
		return NULL;
	while(actuel->fg!=NULL)
		actuel=actuel->fg;
	return actuel;
}

void parcours_infixe(Sommet* s){
	if(s!=NULL){
		parcours_infixe(s->fg);
		printf("%d\t",s->val);
		parcours_infixe(s->fd);
	}
}

void afficherArbre(Arbre* a){
	Sommet* actuel=a->racine;
	if(actuel==NULL)
		printf("ARBRE NULL !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	else{
		parcours_infixe(actuel);
	}
}

int rechercheSommet(Arbre* a,int cle){
	Sommet* actuel=a->racine;
	if(actuel==NULL){
		printf("ARBRE NULL !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		return 0;
	}
	while(actuel!=NULL && actuel->val!=cle){
		if(cle<actuel->val)
			actuel=actuel->fg;
		else
			actuel=actuel->fd;
	}
	if(actuel==NULL)
		return 0;
	else 
		return 1;
}

int compteur(Sommet* s){
	int c;
	if(actuel!=NULL){
		compteur(s->fg);
		return 
		compteur(s->fd);
	}
}

int tailleArbre(Arbre* a){
	int tABR,compteur;
	tABR=sizeof(Arbre);
	printf("le nombre d'octet d'espace memoire alloue a l'abr : %d\n",tABR);
	Sommet* actuel=a->racine;
	if(actuel!=NULL){
		parcours_infixe(s->fg);
		compteur++;
		parcours_infixe(s->fd);
	}
}