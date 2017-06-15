#include "tp4.h"
#define max(a,b) (a>=b?a:b)




// REPRESENTATION CLASSIQUE DE L'ABR

// initialisation d'un ABR, renvoie un pointeur vers un ABR vide
Arbre* initABR(){
	Arbre *newArbre=malloc(sizeof(Arbre)); //allocation de la mémoire nécessaire
	if(!newArbre){
		printf("Erreur de creation de l'arbre\n");
		return NULL;
	}
	newArbre->racine=NULL; //définition de l'ABR
	return newArbre;
}

// création d'un sommet, renvoie un pointeur vers un nouveau sommet à partir d'un clé entrée en paramètre
Sommet* creerSommet(int cle){
	Sommet* newSommet=malloc(sizeof(Sommet)); //allocation de la mémoire nécessaire
	if(!newSommet){
		printf("Erreur de creation du sommet\n");
		return NULL;
	}
	newSommet->val = cle; // définitions des valeurs de base du sommet
	newSommet->fg = NULL;
	newSommet->fd = NULL;
	newSommet->pere = NULL;
	return newSommet;
}

//insère un sommmet dans un ABR
void insererSommet(Arbre* a,Sommet* s){
	Sommet* actuel=a->racine;
	if(actuel==NULL){ //si l'arbre est vide, le premier sommet inséré est sa racine
		a->racine=s;
		printf("Le sommet insere est la racine de l'arbre, de valeur %d ! \n",s->val);
	}
	else{
        int t=rechercheSommet(a,s->val);
        if(t==1){
            printf("On ne peut pas avoir 2 fois  la meme valeur dans le meme arbre\n");
        }
        else{
            Sommet* prev = NULL; //va nous servir à garder trace du père du sommet à insérer
            while(actuel!= NULL){
                prev = actuel;
                if(actuel->val < s->val)
                    actuel=actuel->fd; //selon les règles de construction d'un ABR : clé(père) < clé(fils droit)
                else
                    actuel=actuel->fg; //selon les règles de construction d'un ABR : clé(père) > clé(fils gauche)
            }
            s->pere = prev; //établissement du père de notre sommet à insérer et de son emplacement par rapport à celui-ci
            if(s->val < prev->val)
                prev->fg = s;
            else
                prev->fd = s;
            printf("vous avez bien inserer le sommet de valeur %d, dont le pere est %d. \n",s->val,s->pere->val);
        }
	}
}



// parcours des sommets de façon infixe avec affichage
void parcours_infixe(Sommet* s){
	if(s!=NULL){
		parcours_infixe(s->fg);
		printf("\t %d",s->val);
		parcours_infixe(s->fd);
	}
}

// affiche tous les éléments d'un arbre triés par ordre croissant
void afficherArbre(Sommet* s){
	Sommet* actuel=s;
	if(actuel==NULL)
		printf("ARBRE NULL !!! \n");
	else{
		parcours_infixe(actuel); //fonction récursive
	}
}



// vérifie si une clé existe dans l'ABR
int rechercheSommet(Arbre* a,int cle){
	Sommet* actuel = a->racine; //on se place à la racine de notre arbre
	if(actuel==NULL){
		printf("ARBRE NULL !!! \n");
		return 0;
	}
	while(actuel!=NULL && actuel->val != cle){ //et on le parcourt jusqu'au bout ou jusqu'à trouver notre sommet recherché
		if(cle<actuel->val)
			actuel = actuel->fg;
		else
			actuel = actuel->fd;
	}
	if(actuel==NULL)
		return 0; // sommet pas trouvé
	else
		return 1; // sommet trouvé
}



// compte le nombre de sommet à partir d'un sommet donné
void compteur(Sommet* s,int* c){
	if(s!=NULL){
		compteur(s->fg,c);
		*c=*c+1;
		compteur(s->fd,c);
	}
}

// renvoie le nombre d'octets utilisés pour représenter l'ABR
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


//libération de la mémoire allouée dynamiquement pour un arbre classique
void libererArbre(Sommet* s){
    Sommet* tmp = s; //on se place à la racine de notre arbre
    if(!tmp) return; //pas besoin de libérer l'espace mémoire

    if(tmp->fg)  libererArbre(tmp->fg);
    if(tmp->fd)  libererArbre(tmp->fd);
    free(tmp);

    s = NULL;
}




// UNE REPRESENTATION PLUS COMPACTE

// initialisation d'un ABR compacte, renvoie un pointeur vers un ABR compacte vide
ArbreCompact* initABRCompact(){
	ArbreCompact* newArbre=malloc(sizeof(ArbreCompact)); //allocation de la mémoire nécessaire
	if(!newArbre){
		printf("Erreur de creation de l'arbre\n");
		return NULL;
	}
	newArbre->racine=NULL; //définiion de l'ABR compacte vide
	return newArbre;
}

// création d'un sommet compacte, renvoie un pointeur vers un nouveau sommet à partir d'un clé entrée en paramètre
SommetCompact* creerSommetCompact(int cle){
	SommetCompact* newSommet=malloc(sizeof(SommetCompact)); //allocation de la mémoire nécessaire
	if(!newSommet){
		printf("Erreur de creation du sommet\n");
		return NULL;
	}
	newSommet->fg = NULL; // définitions des valeurs de base du sommet compacte
	newSommet->fd = NULL;
	newSommet->pere = NULL;
	newSommet->inf = cle;
	newSommet->sup = cle;
	return newSommet;
}




// renvoie le sommet ayant la clé minimale du sous-arbre compacte dont on donne la racine en paramètre
SommetCompact* minimum(SommetCompact* s){
	while(s->fg != NULL){
		s = s->fg;
	}
	return s;
}

// renvoie le sommet ayant la clé maximale du sous-arbre compacte dont on donne la racine en paramètre
SommetCompact* maximum(SommetCompact* s){
	while(s->fd != NULL){
		s = s->fd;
	}
	return s;
}

// crée et insère un sommmet compacte dont la clé est entrée en paramètres dans un ABR compacte
void insererElement(ArbreCompact* a, int c){
	SommetCompact* actuel=a->racine; // on se place à la racine de notre arbre
	if(actuel==NULL){
		a->racine=creerSommetCompact(c);
		printf("On cree un sommet compacte de cle %d, qui est la racine de votre Arbre Compacte !\n",c );
	}
	else{
		int test=0;
		int test1=0;
		while(test==0 && test1==0){
			if(actuel->inf > c){ // la valeur est "en dessous" de l'intervalle considéré
				if(actuel->inf-1 == c){ // si elle est "consécutive" à l'intervalle (càd le chiffre précédent la borne inf ici)
					test=1; //il faudra changer la borne de notre intervalle
					continue;
				}
				else
					if(actuel->fg == NULL){ // si l'intervalle considéré n'a pas d'intervalle fils à gauche
						test1=1; // il faudra créer un nouvel intervalle
						continue;
					}
					actuel = actuel->fg; //sinon on vérifira qu'il peut s'insérer dans l'intervalle fils gauche
			}
			else{
				if(actuel->sup >= c){ //la valeur est plus grande que inf mais plus petite que sup donc elle appartient à l'intervalle
					printf("Erreur, element deja existant\n");
					return;
				}
				else{
					if(actuel->sup+1 == c){ // si la valeur est "consécutive" à l'intervalle (càd le chiffre suivant la borne sup ici)
						test=1; // il faudra modifier la borne sup pour l'inclure
						continue;
					}
					else{
						if(actuel->fd == NULL){ // si l'intervalle considéré n'a pas d'intervalle fils à droite
							test1=1; // il faudra créer un nouvel intervalle
							continue;
						}
						actuel=actuel->fd; //sinon on vérifira qu'il peut s'insérer dans l'intervalle fils droit
					}
				}
			}
		}
		if(test1 == 1){ // on doit créer un nouvel intervalle fils
			if(c < actuel->inf){ // il s'agit de créer un fils gauche
				actuel->fg = creerSommetCompact(c);
				printf("On cree un sommet compact de cle %d\n",c );
				actuel->fg->pere = actuel;
			}
			else{
				if(c > actuel->sup){ // il s'agit d'un fils droit
					actuel->fd = creerSommetCompact(c);
					printf("On cree un sommet compact de cle %d\n",c );
					actuel->fd->pere = actuel;
				}
				else
					printf("Erreur, le test ne marche pas\n");
			}
		}
		else{
			if(actuel->inf-1 == c){ //modification de la borne inf de notre intervalle
				if(actuel->fg == NULL){
					actuel->inf = c;
					printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
				}
				else{
					SommetCompact* pred = maximum(actuel->fg);
					if(pred->sup+1 == c){
						actuel->inf = pred->inf;
						if(pred->fg != NULL)
							pred->fg->pere = pred->pere;
						if(pred->pere == actuel)
							actuel->fg = NULL;
						else
							pred->pere->fd = pred->fg;
						printf("On detruit le sommet compact de borne inf : %d, sup : %d et On modifie le sommet compact, borne inf : %d, sup : %d\n",pred->inf, pred->sup,actuel->inf,actuel->sup);
						free(pred);
					}
					else{
						actuel->inf = c;
						printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
					}
				}
			}
			else{	//if(actuel->sup+1==c) càd modification de la borne sup de notre intervalle
				if(actuel->fd == NULL){
					actuel->sup = c;
					printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
				}
				else{
					SommetCompact* succ = minimum(actuel->fd);
					if(succ->inf-1 == c){
						actuel->sup = succ->sup;
						if(succ->fd != NULL)
							succ->fd->pere = succ->pere;
						if(succ->pere == actuel)
							actuel->fd = NULL;
						else
							succ->pere->fg = succ->fd;
						printf("On detruit le sommet compact de borne inf : %d, sup : %d et On modifie le sommet compact, borne inf : %d, sup : %d\n",succ->inf, succ->sup,actuel->inf,actuel->sup);
						free(succ);
					}
					else{
						actuel->sup = c;
						printf("On modifie le sommet compact, borne inf : %d, sup : %d\n",actuel->inf,actuel->sup);
					}
				}
			}
		}
	}
}




// parcours des sommets compactes de façon infixe avec affichage des intervalles
void parcours_infixe_compact(SommetCompact* s){
    if(s!=NULL){
            parcours_infixe_compact(s->fg);
            printf("\t [%d;%d]", s->inf, s->sup);
            parcours_infixe_compact(s->fd);
        }
}

// affiche tous les intervalles d'un arbre compacte triés par ordre croissant
void afficherArbreCompact(SommetCompact* s){
	SommetCompact* actuel=s;
	if(actuel==NULL)
		printf("ARBRE NULL !!! \n");
	else{
		parcours_infixe_compact(actuel); //fonction récursive
	}
}




// vérifie si une valeur existe dans l'ABR compacte
int rechercheElement(ArbreCompact* a,int cle){
	SommetCompact* actuel = a->racine; //on se place à la racine de notre arbre
	if(actuel==NULL){
		printf("ARBRE NULL !!! \n");
		return 0;
	}
	while(actuel!=NULL){ //et on le parcourt jusqu'au bout ou jusqu'à trouver notre sommet recherché
            if(actuel->inf > cle){// la valeur est "en dessous" de l'intervalle considéré -> on regarde son fils gauche
                if(actuel->fg == NULL){ // si en plus l'intervalle considéré n'a pas d'intervalle fils à gauche -> nope
                actuel = NULL;
                continue;
                }
                actuel = actuel->fg;

            }
            else{ // la valeur est égale ou supérieure à la borne inf de notre intervalle
                if(actuel->sup >= cle){ //la valeur est plus grande ou égale à inf mais plus petite ou égale à sup donc elle appartient à l'intervalle -> yes
                break;
                }
                else{ // la valeur est "au dessus" de l'intervalle considéré -> on regarde son fils droit
                    if(actuel->fd == NULL){ // intervalle considéré n'a pas d'intervalle fils à droite -> nope
                        actuel = NULL;
                        continue;
                    }
                    actuel = actuel->fd;
                }
            }
	}
	if(actuel==NULL)
		return 0; // valeur pas trouvée
	else {
		printf("Cette valeur est contenue dans l intervalle [%d;%d] ...", actuel->inf, actuel->sup);
        return 1; // valeur trouvée

		}
}



// compte le nombre de sommet à partir d'un sommet donné
void compteurCompact(SommetCompact* s,int* c){
	if(s!=NULL){
		compteurCompact(s->fg,c);
		*c=*c+1;
		compteurCompact(s->fd,c);
	}
}

// renvoie le nombre d'octets utilisés pour représenter l'ABR compacte
int tailleArbreCompact(ArbreCompact* a){
	int tABR=0;
	int* cmpt;
	*cmpt=0;
	tABR=sizeof(ArbreCompact);
	//printf("le nombre d'octet d'espace memoire alloue a l'abr : %d\n",tABR);
	SommetCompact* actuel=a->racine;
	compteurCompact(actuel,cmpt);
	//printf("le nombre d'octet d'espace memoire alloue a un sommet : %d\n",sizeof(Sommet));
	//printf("le nombre d'element de l'abr vaut : %d\n",*cmpt);
	return *cmpt*sizeof(SommetCompact)+tABR;
}


//libération de la mémoire allouée dynamiquement pour un arbre compacte
void libererArbreCompact(SommetCompact* s){
    SommetCompact* tmp = s; //on se place à la racine de notre arbre compacte
    if(!tmp) return; //pas besoin de libérer l'espace mémoire

    if(tmp->fg)  libererArbreCompact(tmp->fg);
    if(tmp->fd)  libererArbreCompact(tmp->fd);
    free(tmp);

    s = NULL;
}








