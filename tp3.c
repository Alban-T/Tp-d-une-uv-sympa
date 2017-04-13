#include "tp3.h"

void constructMat(Matrice_creuse *m, int t[N][M],int Nlig, int Ncol)
{
	int i=0,j=0;
	Liste_ligne* tab;
	m=malloc(2*sizeof(int));
	m->Nlignes=Nlig;
	m->Ncolonnes=Ncol;
	printf("lignes : %d, Colonnes : %d \n",m->Nlignes,m->Ncolonnes );
	m=malloc(sizeof(Liste_ligne*));
	tab=malloc(Nlig*sizeof(Liste_ligne));
	m->tab=tab;
	for(i=0;i<Nlig;i++){
		Element* newElement=malloc(sizeof(Element));
		m->tab[i].ligne=newElement;
		m->tab[i].ligne->colonne=0;
		m->tab[i].ligne->valeur=0;
		m->tab[i].ligne->suivant=NULL;
		for(j=0;j<Ncol;j++){
			if(t[i][j]!=0){
				printf("\ntest ok, !=0\n" );
				Element* newElement2=malloc(sizeof(Element));
				m->tab[i].ligne->suivant=newElement2;
				//m->tab[i].ligne=m->tab[i].ligne->suivant;
				printf("adresse de l element %d\n",newElement2);
				printf("pointeur de l element precedent : %d\n",m->tab[i].ligne->suivant );
				m->tab[i].ligne++;
				m->tab[i].ligne=newElement2;
				m->tab[i].ligne->colonne=j;
				printf("colonne : %d\n",m->tab[i].ligne->colonne );
				m->tab[i].ligne->valeur=t[i][j];
				printf("valeur : %d\n",m->tab[i].ligne->valeur );
				m->tab[i].ligne->suivant=NULL;
				printf("adresse de l element suivant : %d\n",m->tab[i].ligne->suivant );

			}
		}
		//m->tab->ligne++;
	}
}

void afficherMat(Matrice_creuse m)
{
	int i,j,tmp1=0,tmp2=0,dif=0;;
	Element* e1;
	for(i=0;i<m.Nlignes;i++){
		printf("coucou\n");
		printf("%d\n",&m.Nlignes );
		printf("%d\n",m.tab[i].ligne[0].suivant);
		if(m.tab[i].ligne->suivant==NULL){
			printf("bite\n");
			for(j=0;j<m.Ncolonnes;j++) printf("0\t");
		}
		else{
			do{
				e1=m.tab[i].ligne;
				//tmp1=m.tab[i].ligne->colonne;
				tmp1=e1->colonne;
				e1=m.tab[i].ligne->suivant;
				//tmp2=m.tab[i].ligne->colonne;
				tmp2=e1->colonne;
				dif=tmp2-tmp1;
				if(dif>1){
					for(j=1;j<dif;j++) printf("0\t");
				}
				printf("%d\t",e1->valeur);
			}while(e1->suivant !=NULL);
		}
	}
}
