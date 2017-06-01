#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"
int main()
{

    Arbre* ABR1=initABR();
    Sommet* S1=creerSommet(13);
    insererSommet(ABR1,S1);
    insererSommet(ABR1,creerSommet(15));
    insererSommet(ABR1,creerSommet(16));
    insererSommet(ABR1,creerSommet(28));
    insererSommet(ABR1,creerSommet(11));
    insererSommet(ABR1,creerSommet(12));
    insererSommet(ABR1,creerSommet(10));
    printf("\n");
    afficherArbre(ABR1);
    printf("\n");
    printf("%d\n",rechercheSommet(ABR1,13));
    printf("La taille de l'arbre vaut : %d octets\n",tailleArbre(ABR1));

    printf("\n\n");
    ArbreCompact* A2=initABRCompact();
    insererElement(A2,13);
    insererElement(A2,15);
    insererElement(A2,16);
    //insererElement(A2,14);
    insererElement(A2,28);
    insererElement(A2,11);
    insererElement(A2,12);
    insererElement(A2,10);
    printf("\n");
    afficherArbreCompact(A2);
    printf("\n");
    printf("%d\n",rechercheElement(A2,13));
    printf("La taille de l'arbre compact vaut : %d octets\n",tailleArbreCompact(A2));

    return 0;
}
