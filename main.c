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

	Matrice_creuse *m1=constructMatCreuse(N,M);
	constructMat(m1,matrice,N,M);
	printf("ok on passe a l affichage\n\n");
	//printf("nb lignes : %d\n",m1->Nlignes);
	afficherMat(*m1);
	libererMat(*m1);
    printf("Hello world!\n");
    return 0;
}
