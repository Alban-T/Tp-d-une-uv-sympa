#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"


int main()
{
	int i, j;
	/*int** matrice;

	printf("entrer nombre de lignes\n");
	scanf("%d",&Nlig);
	printf("entrer nombre de colonnes\n");
	scanf("%d",&Ncol);

	matrice=malloc(Nlig*sizeof(int*));
	for(i=0; i<Nlig; i++)
    matrice[i]=malloc(Ncol*sizeof(int));*/
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


	Matrice_creuse m1;
	constructMat(&m1,matrice,N,M);
	printf("ok \n");

	//Element* actuel=m1->tab->ligne->suivant;
	//printf("valeur : %d \n",actuel->valeur);
	afficherMat(m1);
	//free(m1->tab);
	 /*for(i=0;i<N;i++){
    	for(j=0;j<M;j++) scanf("%d",&matrice[i][j]);
    }*/
	free(matrice);
    printf("Hello world!\n");
    return 0;
}
