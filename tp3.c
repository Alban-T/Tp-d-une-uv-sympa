#include "tp3.h"

Element* constructElement()
{
	Element* newElement=NULL;		//Creation d'un pointeur sur element et initialisation a NULL
	newElement=(Element *)malloc(sizeof(Element));	//Allocation dynamique d element avec un cast
	 												//pour recuperer un pointeur avec le type voulu
	if(newElement==NULL){	//Verification de l allocation
		printf("Erreur lors de la creation de l element\n");
		exit(0);
	}
	return newElement;	//on renvoie l element
}

Liste_ligne* constructTab(int k)
{
	Liste_ligne* newTab=NULL;
	newTab=(Liste_ligne *)malloc(k*sizeof(Liste_ligne));
	if(newTab==NULL){
		printf("Erreur d'allocation du tab\n");
		exit(0);
	}
	return newTab;
}

Matrice_creuse* constructMatCreuse(int n,int m)
{
	int i;
	Matrice_creuse* newMatrice=NULL;
	newMatrice=(Matrice_creuse *)malloc(sizeof(Matrice_creuse));
	if(newMatrice==NULL) {
		printf("Erreur d'allocation de la matrice\n");
		exit(0);
	}
	newMatrice->tab=constructTab(n);	//on appelle la fonction constructTab qui alloue n*sizeof(Liste_ligne)
										//et qui retourne cette valeur a newMatrice->tab
	for(i=0;i<n;i++) newMatrice->tab[i] = NULL;	//on initialise chaque case du tableau a NULL

	//Initialisation des valeurs des attributs de la matrice
	newMatrice->Nlignes=n;
	newMatrice->Ncolonnes=m;
	return(newMatrice);
}

void constructMat(Matrice_creuse *m, int t[N][M],int Nlig, int Ncol)
{
	int i,j;
	m->Nlignes=Nlig;	//Initialisation des valeurs des attributs de la matrice
	m->Ncolonnes=Ncol;
	//printf("lignes : %d, Colonnes : %d \n",m->Nlignes,m->Ncolonnes );//Verification
	for(i=0;i<Nlig;i++){
		for(j=0;j<Ncol;j++){
			if(t[i][j]!=0){		//si la case de la matrice a une valeur differente de 0
				Element* e1=constructElement();	//on cree un nouvel element
				e1->colonne=j;
				e1->valeur=t[i][j];
				e1->suivant=NULL;
				if(m->tab[i]==NULL){
					m->tab[i]=e1;
					printf("CONSTRUCTION1 : valeur : %d, colonne : %d\n",e1->valeur,e1->colonne);
				}
				else{
					if(e1->colonne!=0){
						while(m->tab[i]->suivant!=NULL) m->tab[i]=m->tab[i]->suivant;	//on parcours tab[i] jusqu au dernier element
						m->tab[i]->suivant=e1;
						printf("CONSTRUCTION2 : valeur : %d, colonne : %d\n",e1->valeur,e1->colonne);
					}
				}
			}
		}
	}
}


void afficherMat(Matrice_creuse m)
{
	int i,j;
	for(i=0;i<m.Nlignes;i++){
		int compteur=0;
		printf("af1 colonne : %d,valeur : %d\n",m.tab[i]->colonne,m.tab[i]->valeur);
		Element* e1=m.tab[i];
		if(e1==NULL){	//SI LA LIGNE EST VIDE ON A AFFICHE Ncolonnes de 0
			for(j=0;j<m.Ncolonnes;j++) printf("0\t");
			printf("\n");
		}
		else{
			while(e1!=NULL){	//tant qu il reste des element sur la ligne
				if(compteur!=e1->colonne){	//si on a saute une/plusieurs colonne a cause d un 0 on en affiche un
					printf("colonne : %d,compteur : %d\n",e1->colonne,compteur );
					printf("0\t");
					compteur++;
				}
				else{
					printf("%d\t",e1->valeur);	//on affiche les valeurs differentes de 0
					e1=e1->suivant;
					compteur++;
				}
			}
			if(compteur!=m.Ncolonnes){	//si le dernier element de la ligne vaut 0 on l affiche aussi
					int tmp=m.Ncolonnes-compteur;
					int k;
					for(k=0;k<tmp;k++) printf("0\t");
				}
			printf("\n");
		}
	}
}


void libererMat(Matrice_creuse m)
{
	int i,j;
	Element* e1;
	for(i=0;i<m.Nlignes;i++){	//on balaye toutes les lignes
		if(m.tab[i]==NULL){	//si la ligne est vide on la libere
			free(m.tab[i]);
		}
		else{
			do{
				e1=m.tab[i]->suivant;	//on stocke l element suivant dans e1
				free(m.tab[i]);			//et on libere l element acutel
			}while(e1->suivant!=NULL);	//tant qu il existe un element suivant
		}
	}
	free(m.tab);	//on libere le tableau global
	free(&m);		//on libere m
}

