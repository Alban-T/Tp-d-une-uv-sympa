#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"
int main()
{
    Arbre* ABR1=initABR();
    Sommet* S1=creerSommet(3);
    insererSommet(ABR1,S1);
    insererSommet(ABR1,creerSommet(5));
    insererSommet(ABR1,creerSommet(7));
    insererSommet(ABR1,creerSommet(4));
    insererSommet(ABR1,creerSommet(2));
    afficherArbre(ABR1);
    printf("\n0 faux, 1 vrai\n");
    printf("%d\n",rechercheSommet(ABR1,1));
    return 0;
}
