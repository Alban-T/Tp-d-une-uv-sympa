#include <stdio.h>
#include <stdlib.h>

#include "tp4.h"
#include "tp4.c"


int main(int argc, char* argv[])
{

// INTERFACE

printf("\t\t\t-------------------------------\n");
printf("\t\t\t| BIENVENUE DANS LE PROGRAMME |\n");
printf("\t\t\t-------------------------------\n\n\n");


char prenom[15];
printf("Quel est votre prenom cher utilisateur ?  ");
scanf("%s", prenom);
printf("\nBonjour %s, amuse toi bien avec les ABR !");



    do{
        printf("\n\n\n MENU PRINCIPAL : \n\n"
            "1: Contruire un ABR classique \n"
            "2: Construire un ABR compact \n\n"
            "3: Faire des operations sur un ABR classique \n"
            "4: Faire des operations sur un ABR compact \n\n"
            "5: Construire un ABR classique et un ABR compact avec les memes valeurs et comparer les tailles de representations \n\n"
            "6: Quitter \n\n"
            "Que voulez-vous faire ? (tapez le numero)  ");


        // pour éviter les problèmes de buffer
        choix='0';
        scanf ("%*[^\n]");
        getchar ();

        scanf("%c",&choix);


        //si jamais l'utilisateur entre autre chose que les propositions
        while(choix<'1' || choix>'6'){
            scanf ("%*[^\n]");
            getchar ();
            printf("Erreur! Veuillez entrez un des numeros proposes svp :  ");
            scanf("%c",&choix);
        }



        //pour s'assurer qu'un ABR est construit avant toute chose
        while(choix!='6' && deb==0 && choix!='1' && choix!='2' && choix!='5'){
            scanf ("%*[^\n]");
            getchar ();
            printf("Desole mais vous devez construire votre ABR dans un premier temps...\n Essayez, tapez 1 ou 2!    ");
            scanf("%c",&choix);
        }


        printf("\n\n\n");




    switch(choix){

            case '1': printf("Vous avez choisi de construire un ABR classique ! \n\n");
                      Arbre* ABR1=initABR();
                      if (deb==2 || deb==4) // est-ce qu'un autre ABR a déjà été construit ?
                        deb += 1;
                      else
                        deb=1; //ok un ABR classique est construit, plus d'inquiétudes

                      printf("Voulez-vous le remplir vous-meme (tapez 1) ou de facon aleatoire (tapez 2) ?   ");
                      int rep;
                      scanf("%d", &rep);


                      if(rep==1){
                            printf("Vous avez choisi de le remplir vous-meme, c est parti !\n");

                            int sommets, i;
                            int value[100];
                            printf("Combien de sommets contient votre arbre ?   "); scanf("%d", &sommets);

                            printf("Valeur de la racine =  "); scanf("%d", &value[0]);
                            Sommet* S1 = creerSommet(value[0]);
                            insererSommet(ABR1,S1);

                            for(i=0; i<(sommets-1); i++){
                                    printf("\n Valeur du %deme sommet = ", i+2);
                                    scanf("%d", &value[i+1]);
                                    insererSommet(ABR1,creerSommet(value[i+1]));
                            }
                            printf("\n Voila tous vos sommets sont inseres, maintenant vous pouvez effectue des operations sur votre ABR wouhou ! \n");
                      }


                      else if (rep==2){
                          printf("Vous avez choisi de le remplir aleatoirement, c est parti ! \n\n");

                          time_t t;
                          srand((unsigned) time(&t)); // Intializes random number generator

                          int j;
                          for(j=0; j<7; j++){
                              insererSommet(ABR1,creerSommet(rand() % 50));
                          }
                          printf("\n Voila des sommets ont ete inseres, maintenant vous pouvez effectue des operations sur votre ABR wouhou ! \n");
                      }


                      else {
                        printf("Erreur, vous n avez pas tape un des numeros proposes ... \n");
                        continue;
                      }

                      break;





            case '2': printf("Vous avez choisi de construire un ABR compacte ! \n\n");

                      ArbreCompact* ABR2 = initABRCompact();
                      if(deb==1 || deb==4)
                        deb+=2;
                      else
                        deb=2; //ok un ABR compacte est construit, plus d'inquiétudes

                      printf("Voulez-vous le remplir vous-meme (tapez 1) ou de facon aleatoire (tapez 2) ?   ");
                      int rep2;
                      scanf("%d", &rep2);


                      if(rep2==1){
                            printf("Vous avez choisi de le remplir vous-meme, c est parti !\n");

                            int sommets2, v;
                            int value2[100];
                            printf("Combien de valeurs voulez-vous entrer ?   "); scanf("%d", &sommets2);

                            for(v=0; v< sommets2; v++){
                                    printf("\n Valeur du %deme sommet = ", v+1);
                                    scanf("%d", &value2[v]);
                                    insererElement(ABR2,value2[v]);
                                    }
                            printf("\n Voila tous vos sommets sont inseres, maintenant vous pouvez effectue des operations sur votre ABR compacte wouhou ! \n");
                      }


                      else if (rep2==2){
                          printf("Vous avez choisi de le remplir aleatoirement, c est parti ! \n\n");

                          time_t t;
                          srand((unsigned) time(&t)); // Intializes random number generator

                          int w;
                          for(w=0; w<7; w++){
                              insererElement(ABR2,(rand()%80));
                          }
                          printf("\n Voila des sommets ont ete inseres, maintenant vous pouvez effectue des operations sur votre ABR compacte wouhou ! \n");
                      }


                      else {
                        printf("Erreur, vous n avez pas tape un des numeros proposes ... \n");
                        continue;
                      }

                      break;




            case '3': printf("Vous avez choisi de faire des operations sur un ABR classique ! \n\n");

                      if(deb>1){
                        printf("Vous n avez pas constuit d ABR classique exploitable pour cette partie encore ...\n"
                               "Essayez, tapez 1 dans le menu principal ! \n");
                        break;
                      }


                      //choix de l'opération a effectué
                      char choix2;
                      printf("Vous pouvez : \n"
                             "1 = afficher votre ABR \n"
                             "2 = rechercher un sommet par sa valeur \n"
                             "3 = inserer un nouveau sommet dans votre ABR \n"
                             "4 = savoir le nombre d octets utilises pour representer l ABR \n");
                      printf("Que voulez-vous faire ?  ");

                      // pour éviter les problèmes de buffer
                      choix2='0';
                      scanf ("%*[^\n]");
                      getchar ();

                      scanf("%c",&choix2);

                      //si jamais l'utilisateur entre autre chose que les propositions
                      while(choix2<'1' || choix2>'4'){
                            scanf ("%*[^\n]");
                            getchar ();
                            printf("Erreur! Veuillez entrez un des numeros proposes svp :  ");
                            scanf("%c",&choix2);
                            }



                      switch(choix2){

                          case '1':  printf("\n\n Vous avez choisi d afficher votre ABR (les elements sont tries par ordre croissant), le voici : \n");
                                     afficherArbre(ABR1->racine);
                                     break;


                          case '2':  printf("\n\n Vous avez choisi de rechercher un sommet par sa valeur. \n");
                                     int look, result;
                                     printf("Quelle valeur cherchez-vous ?   "); scanf("%d", &look);
                                     result = rechercheSommet(ABR1, look);
                                     if(result==1)
                                        printf("Ce sommet existe bien dans votre ABR ! \n");
                                     else
                                        printf("Sorry ce sommet n existe pas malheureusement ... \n");
                                     break;


                          case '3':  printf("\n\n Vous avez choisi d inserer un nouveau sommet dans votre ABR. \n");
                                     int nv;
                                     printf("\n Valeur du sommet a insere = "); scanf("%d", &nv);
                                     insererSommet(ABR1,creerSommet(nv));
                                     break;


                          case '4':  printf("\n\n Vous voulez savoir le nombre d octets utilises pour representer l ABR.\n");
                                     int NbOctects;
                                     NbOctects = tailleArbre(ABR1);
                                     printf("Et bien sachez que pour representer votre ABR classique il faut %d octects ! \n\n", NbOctects);
                                     break;

                      }
                      break;



            case '4': printf("Vous avez choisi de faire des operations sur un ABR compacte ! \n\n");

                      if(deb==1 || deb>3){
                        printf("Vous n avez pas constuit d ABR comapcte exploitable pour cette partie encore ...\n"
                               "Essayez, tapez 2 dans le menu principal ! \n");
                        break;
                        }


                      //choix de l'opération a effectué
                      char choix3;
                      printf("Vous pouvez : \n"
                             "1 = afficher votre ABR \n"
                             "2 = rechercher un sommet par sa valeur \n"
                             "3 = inserer un nouveau sommet dans votre ABR \n"
                             "4 = savoir le nombre d octets utilises pour representer l ABR \n");
                      printf("Que voulez-vous faire ?  ");

                      // pour éviter les problèmes de buffer
                      choix3='0';
                      scanf ("%*[^\n]");
                      getchar ();

                      scanf("%c",&choix3);

                      //si jamais l'utilisateur entre autre chose que les propositions
                      while(choix3<'1' || choix3>'4'){
                            scanf ("%*[^\n]");
                            getchar ();
                            printf("Erreur! Veuillez entrez un des numeros proposes svp :  ");
                            scanf("%c",&choix3);
                            }



                      switch(choix3){

                          case '1':  printf("\n\n Vous avez choisi d afficher votre ABR (les elements sont tries par ordre croissant), le voici : \n");
                                     afficherArbreCompacte(ABR2->racine) ;
                                     break;


                          case '2':  printf("\n\n Vous avez choisi de rechercher un element par sa valeur. \n");
                                     int look2, result2;
                                     printf("Quelle valeur cherchez-vous ?   "); scanf("%d", &look2);
                                     result2 = rechercheElement(ABR2, look2);
                                     if(result2==1)
                                        printf("DONC cette valeur existe bien dans votre ABR ! \n");
                                     else
                                        printf("Sorry cette valeur n existe pas malheureusement ... \n");
                                     break;


                          case '3':  printf("\n\n Vous avez choisi d inserer un nouveau sommet dans votre ABR. \n");
                                     int nv2;
                                     printf("\n Valeur du sommet a insere = "); scanf("%d", &nv2);
                                     insererElement(ABR2,nv2);
                                     break;


                          case '4':  printf("\n\n Vous voulez savoir le nombre d octets utilises pour representer l ABR.\n");
                                     int NbOctects2;
                                     NbOctects2 = tailleArbreCompacte(ABR2);
                                     printf("Et bien sachez que pour representer votre ABR compacte il faut %d octects ! \n\n", NbOctects2);
                                     break;
                      }
                      break;


            case '5':   printf("Vous avez choisi de construire un ABR classique et un ABR compact avec les memes valeurs et comparer les tailles de representations ! \n");
                        if(deb==0)
                            deb=4; //pas d'opérations sur les ABR créés ici, juste une comparaison des tailles de représentations
                        else
                            deb+=4;

                        //ABR classique
                        Arbre* ABR3=initABR();

                        // ABR compacte
                        ArbreCompact* ABR4 = initABRCompact();

                        int sommets, i;
                        int value[100];
                        printf("Combien de sommets contiennent vos arbres ?   "); scanf("%d", &sommets);

                        for(i=0; i<(sommets); i++){
                                printf("\n Valeur du %deme sommet = ", i+1);
                                scanf("%d", &value[i]);
                                insererSommet(ABR3,creerSommet(value[i]));
                                insererElement(ABR4,value[i]);
                        }

                        printf("Tout d'abord affichons ces jolis arbres ! \n");
                        printf("ARBRE CLASSIQUE :   "); afficherArbre(ABR3->racine);
                        printf("\n ARBRE COMPACTE :   "); afficherArbreCompacte(ABR4->racine) ;


                        printf("\n\n Maintenant comparons leurs tailles de representation : \n");

                        int NbOctects;
                        NbOctects = tailleArbre(ABR3);
                        printf("Et bien sachez que pour representer votre ABR en mode classique il faut %d octects ! \n\n", NbOctects);

                        int NbOctects2;
                        NbOctects2 = tailleArbreCompacte(ABR4);
                        printf("Et bien sachez que pour representer votre ABR en mode compacte il faut %d octects ! \n\n", NbOctects2);

                        break;



            case '6':   printf("Vous avez choisi quitter : BYE! \n");

                        // LIBERATION DE LA MEMOIRE ALLOUEE
                        if(deb==1) //seul un ABR a été créé
                            libererArbre(ABR1->racine);
                        else if(deb==2) // seul un ABR compacte a été créé
                                libererArbreCompact(ABR2->racine);
                        else if(deb==4){ // seuls les ABR de comparaison de tailles ont été créés
                                libererArbre(ABR3->racine);
                                libererArbreCompact(ABR4->racine);
                        }
                        else if(deb==5){ // 1 ABR classique et les ABR de comparaisons ont été créés
                                libererArbre(ABR1->racine);
                                libererArbre(ABR3->racine);
                                libererArbreCompact(ABR4->racine);
                        }
                        else if(deb==6){ // 1 ABR compacte et les ABR de comparaisons ont été créés
                                libererArbreCompact(ABR2->racine);
                                libererArbre(ABR3->racine);
                                libererArbreCompact(ABR4->racine);
                        }
                        else if(deb==7){ // Toutes les possibilités ont été créées
                                libererArbre(ABR1->racine);
                                libererArbreCompact(ABR2->racine);
                                libererArbre(ABR3->racine);
                                libererArbreCompact(ABR4->racine);
                        }
                        else
                            printf("Vous n avez rien cree donc aucune allocation memoire a liberer ! \n");


                        printf("(PS : Tous les ABR ont bien ete liberes!) \n\n");
                        break;

            default : printf(  "erreur!");
        }

    }  while(choix!='6'); //on continue les opérations tant que l'utilisateur ne souhaite pas quitter

    exit(6); //sortie du programme
    return 0;
}
