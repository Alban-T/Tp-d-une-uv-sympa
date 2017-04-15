#include "tp3.h"

void constructMat(Matrice_creuse *m, int t[N][M],int Nlig, int Ncol)
{
	int i=0,j=0;

	//-------------ALLOCATION DE m----------------------//
	m=NULL;
	m=(Matrice_creuse *) malloc(sizeof(Matrice_creuse));
	if(m==NULL) {
		printf("Erreur d'allocation de m\n");
		exit(0);
	}
	m->Nlignes=Nlig;
	m->Ncolonnes=Ncol;
	m->tab=NULL;
	m->tab=(Liste_ligne *) malloc(Nlig*sizeof(Liste_ligne));
	if(m->tab==NULL){
		printf("Erreur d'allocation du tab\n");
		exit(0);
	}
	printf("lignes : %d, Colonnes : %d \n",m->Nlignes,m->Ncolonnes );//Verification

	//----------ALLOCATION+REMPLISSAGE DU TABLEAU------------------//
	for(i=0;i<Nlig;i++){
		//---------INITIALISATION DE LA PREMIERE CASE DE CHAQUE LIGNE-----------//
		Element* newElement=NULL;
		newElement=(Element *) malloc(sizeof(Element));
		if(newElement==NULL){
			printf("Erreur d'allocation du premier element\n");
			exit(0);
		}
		m->tab[i].ligne=newElement;
		m->tab[i].ligne->colonne=-1;
		m->tab[i].ligne->valeur=0;
		m->tab[i].ligne->suivant=NULL;
		for(j=0;j<Ncol;j++){
			if(t[i][j]!=0){	//si la case de t est nulle on passe a la suivante
				Element* newElement2=NULL;
				newElement2=(Element *) malloc(sizeof(Element));
				if(newElement2==NULL){
					printf("Erreur d'allocation du nouvel element\n");
					exit(0);
				}
				m->tab[i].ligne->suivant=newElement2;	//on fait pointer suivant vers le nouvel element
				printf("\nadresse de l element %d\n",newElement2);
				printf("pointeur de l element precedent : %d\n",m->tab[i].ligne->suivant );
				m->tab[i].ligne=m->tab[i].ligne->suivant;
				m->tab[i].ligne->colonne=j;
				printf("colonne : %d\n",m->tab[i].ligne->colonne );
				m->tab[i].ligne->valeur=t[i][j];
				printf("valeur : %d\n",m->tab[i].ligne->valeur );
				m->tab[i].ligne->suivant=NULL;
				printf("adresse de l element suivant : %d\n",m->tab[i].ligne->suivant );
			}
		}
	}
}

void afficherMat(Matrice_creuse m)
{
	int i,j,tmp1=0,tmp2=0,dif=0;;
	Element* e1;
	//--------------ON BALAYE tab POUR CHAQUE ELEMENT-----------------//
	printf("%d\n",m.Nlignes);
	for(i=0;i<m.Nlignes;i++){
		//printf("coucou\n");
		if(m.tab[i].ligne->suivant==NULL){	//SI LA LIGNE EST VIDE ON A AFFICHE Ncolonnes de 0
			printf("\nligne vide\n");
			for(j=0;j<m.Ncolonnes;j++) printf("0\t");
			printf("\n");
		}
		else{
			e1=m.tab[i].ligne->suivant;
			printf("\n%d\t",e1->valeur);
			while(e1->suivant!=NULL){
				tmp1=e1->colonne;
				e1=e1->suivant;
				tmp2=e1->colonne;
				dif=tmp2-tmp1;
				if(dif>1){
					for(j=1;j<dif;j++) printf("0\t");
				}
				printf("%d\t",e1->valeur);
			}
		}
	}
}

void libererMat(Matrice_creuse *m)
{
	int i,j;
	Element* e1;
	for(i=0;i<m->Nlignes;i++){
		if(m->tab[i].ligne->suivant==NULL){
			free(m->tab[i].ligne);
		}
		else{
			e1=m->tab[i].ligne->suivant;
			free(m->tab[i].ligne);
			while(e1->suivant!=NULL){
				e1=m->tab[i].ligne->suivant;
				free(m->tab[i].ligne);
			}
		}
	}
	free(m->tab);
	free(m);
}
