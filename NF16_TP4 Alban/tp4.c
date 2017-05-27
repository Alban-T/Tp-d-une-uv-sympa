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

void compteur(Sommet* s,int* c){
	if(s!=NULL){
		compteur(s->fg,c);
		//printf("element compte : %d\n",*c);
		*c=*c+1;
		compteur(s->fd,c);
	}
}

int tailleArbre(Arbre* a){
	int tABR=0;
	int* cmpt;
	*cmpt=0;
	tABR=sizeof(Arbre);
	//printf("le nombre d'octet d'espace memoire alloue a l'abr : %d\n",tABR);
	Sommet* actuel=a->racine;
	compteur(actuel,cmpt);
	//printf("le nombre d'octet d'espace memoire alloue a un sommet : %d\n",sizeof(Sommet));
	//printf("le nombre d'element de l'abr vaut : %d\n",*cmpt);
	return *cmpt*sizeof(Sommet)+tABR;
}


ArbreCompact* initABRCompact(){
	ArbreCompact* newArbre=malloc(sizeof(ArbreCompact));
	if(!newArbre){
		printf("Erreur de creation de l'arbre\n");
		return NULL;
	}
	newArbre->racine=NULL;
	return newArbre;
}

SommetCompact* creerSommetCompact(int cle){
	SommetCompact* newSommet=malloc(sizeof(SommetCompact));
	if(!newSommet){
		printf("Erreur de creation du sommet\n");
		return NULL;
	}
	newSommet->fg=NULL;
	newSommet->fd=NULL;
	newSommet->pere=NULL;
	newSommet->inf=cle;
	newSommet->sup=cle;
	return newSommet;
}

SommetCompact* minimum(SommetCompact* s){
	while(s->fg!=NULL){
		s=s->fg;
	}
	return s;
}

SommetCompact* maximum(SommetCompact* s){
	while(s->fd!=NULL){
		s=s->fd;
	}
	return s;
}


void insererElement(ArbreCompact* a, int c){
	SommetCompact* actuel=a->racine;
	if(actuel==NULL){
		a->racine=creerSommetCompact(c);
		printf("On cree un sommet compact de cle %d\n",c );
	}
	else{
		int test=0;
		int test1=0;
		while(test==0 && test1==0){
			if(actuel->inf > c){
				if(actuel->inf-1==c){
					test=1;
					continue;
				}
				else
					if(actuel->fg==NULL){
						test1=1;
						continue;
					}
					actuel=actuel->fg;
			}
			else{
				if(actuel->sup >= c){
					printf("Erreur, element deja existant\n");
					exit(2);
				}
				else{
					if(actuel->sup+1==c){
						test=1;
						continue;
					}
					else{
						if(actuel->fd==NULL){
							test1=1;
							continue;
						}
						actuel=actuel->fd;
					}
				}
			}
		}
		if(test1==1){
			if(c < actuel->inf){
				actuel->fg=creerSommetCompact(c);
				printf("On cree un sommet compact de cle %d\n",c );
				actuel->fg->pere=actuel;
			}
			else{
				if(c > actuel->sup){
					actuel->fd=creerSommetCompact(c);
					printf("On cree un sommet compact de cle %d\n",c );
					actuel->fd->pere=actuel;
				}
				else
					printf("Erreur, le test ne marche pas\n");
			}
		}
		else{
			if(actuel->inf-1==c){
				if(actuel->fg==NULL){
					actuel->inf=c;
					printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
				}
				else{
					SommetCompact* pred=maximum(actuel->fg);
					if(pred->sup+1==c){
						actuel->inf=pred->inf;
						if(pred->fg!=NULL)
							pred->fg->pere=pred->pere;
						if(pred->pere==actuel)
							actuel->fg=NULL;
						else
							pred->pere->fd=pred->fg;
						printf("On detruit le sommet compact de borne inf : %d, sup : %d et On modifie le sommet compact, borne inf : %d, sup : %d\n",pred->inf, pred->sup,actuel->inf,actuel->sup);
						free(pred);
					}
					else{
						actuel->inf=c;
						printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
					}
				}
			}
			else{	//if(actuel->sup+1==c)
				if(actuel->fd==NULL){
					actuel->sup=c;
					printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
				}
				else{
					SommetCompact* succ=minimum(actuel->fd);
					if(succ->inf-1==c){
						actuel->sup=succ->sup;
						if(succ->fd!=NULL)
							succ->fd->pere=succ->pere;
						if(succ->pere==actuel)
							actuel->fd=NULL;
						else
							succ->pere->fg=succ->fd;
						printf("On detruit le sommet compact de borne inf : %d, sup : %d et On modifie le sommet compact, borne inf : %d, sup : %d\n",succ->inf, succ->sup,actuel->inf,actuel->sup);
						free(succ);
					}
					else{
						actuel->sup=c;
						printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
					}
				}
			}
		}
	}
}
