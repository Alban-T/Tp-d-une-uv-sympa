#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"
int main()
{
    /*
     Arbre* ABR1=initABR();
    Sommet* S1=creerSommet(3);
    insererSommet(ABR1,S1);
    insererSommet(ABR1,creerSommet(5));
    insererSommet(ABR1,creerSommet(7));
    insererSommet(ABR1,creerSommet(4));
    insererSommet(ABR1,creerSommet(2));
    printf("\n\n");
    afficherArbre(ABR1);
    printf("\n\n");
    printf("\nOn teste si un sommet de cle 1 existe dans l'ABR, 0 faux, 1 vrai\n");
    printf("%d\n",rechercheSommet(ABR1,1));
    printf("La taille de l'arbre vaut : %d octets\n",tailleArbre(ABR1));
    */

    ArbreCompact* A2=initABRCompact();
    insererElement(A2,13);
    insererElement(A2,15);
    insererElement(A2,16);
    insererElement(A2,14);
    insererElement(A2,28);
    insererElement(A2,11);
    insererElement(A2,12);
    insererElement(A2,10);
    return 0;
}
