#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"


int main()
{
	int i, j;
    printf("entrer les element de la matrice\n");
    int matrice[N][M];
    for(i=0;i<N;i++){
    	for(j=0;j<M;j++) scanf("%d",&matrice[i][j]);
    }

    for(i=0;i<N;i++){
    	printf("\n");
    	for(j=0;j<M;j++) printf("%d\t",matrice[i][j]);
    }
	printf("\n");


	Matrice_creuse *m1;
	constructMat(m1,matrice,N,M);
	printf("ok on passe a l affichage\n");
	printf("nb lignes : %d\n",m1->Nlignes);
	//afficherMat(*m1);
	//libererMat(*m1);
	
	/*Matrice_creuse *m2;
	m2=NULL;
	m2=(Matrice_creuse *) malloc(sizeof(Matrice_creuse));
	//m2=malloc(sizeof(Matrice_creuse));
	if(m2==NULL) {
		printf("Erreur d'allocation de m\n");
		exit(0);
	}
	m2->Nlignes=N;
	m2->Ncolonnes=M;
	m2->tab=NULL;
	printf("lignes : %d, Colonnes : %d \n",m2->Nlignes,m2->Ncolonnes );
	printf("lignes : %d \n",*m2);
	printf("colonnes : %d \n",*(m2+1));
	free(m2);*/
    printf("Hello world!\n");
    return 0;
}
