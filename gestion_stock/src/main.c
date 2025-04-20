#include <stdio.h>
#include <stdlib.h>
#include "bib.h"


int main()
{   Categorie  TabCat[20];
    int TabQte[50];
    Type TabType[50];
    int NbTyp=0;
    Produit Stock[100][50];
    Produit p;
    int NbCat=0;
    int nbprod;
    char categorie1;
    char categorie;
    int mois;
    int annee;
    FILE *f;
    int idt,idp;
    printf ("***********************************\n ********Bienvenue*******\n**************************************\n");

    menu();

    int choix;
    do{
    do{
        printf (" >> Entrer votre choix");
        scanf("%d",&choix);
   } while (choix < 0 && choix > 2);
    switch (choix) {
      case 1 :  gestionstock();
        int c1;
        do{
        printf (" >> Entrer votre choix");
        scanf ("%d",&c1);

         } while (c1 < 0 && c1 > 5);
           switch (c1) {
           case 1 :     gestioncategories();
           int c2;
             do{
               printf (" >> Entrer votre choix");
               scanf ("%d",&c2);

               } while (c2 < 0 &&  c2 > 2);
                  switch (c2) {
                   case 1 :  AjouterCat(TabCat,&NbCat);
                    break;
                   case 2 : SupprimerCat(TabCat,&NbCat,TabType,NbTyp);
                    break;
                }
            break;
           case 2 :     gestiontypes();
             int c3;
             do{
               printf (" >> Entrer votre choix");
               scanf ("%d",&c3);

                }while (c3 < 0 && c3 > 2);
                  switch (c3) {
                   case 1 : AjouterTyp(TabType,&NbTyp,TabCat,NbCat,TabQte);
                    break;
                   case 2 : SupprimerTyp(TabType,&NbTyp,TabQte);
                    break;
                }
             break;
           case 3 :     gestionproduits();
                        int c4;
             do{
               printf (" >> Entrer votre choix");
               scanf ("%d",&c4);

                }while (c4 < 0 &&  c4 > 2);
                  switch (c4) {
                   case 1 : AjouterPdt(Stock,TabType,NbTyp,TabQte);
                    break;
                   case 2 :printf(" >> donner id du produit  que vous souhaitez le supp : \n");
                           scanf("%d",&idp);
                           SupprimerPdt(Stock,TabQte,TabType,NbTyp,idp);
                    break;
                }
             break;
           case 4 : Afficherstock(Stock,TabType,NbTyp,TabCat,NbCat,TabQte);
               break;
           }
      break;
      case 2 :  ventes();
                 int c5;
             do{
               printf (" >> Entrer votre choix");
               scanf ("%d",&c5);

               } while (c5 < 0 &&  c5 > 2);
                  switch (c5) {
                   case 1 : printf(" >> donner id du type du produit  que vous souhaitez le vendre: \n");
                           scanf("%d",&idt);
                       VendrePdt(f,Stock,TabType,NbTyp,TabCat,NbCat,TabQte,idt);
                    break;
                   case 2 : stat ();
                   int c6;
                do{
               printf (" >> Entrer votre choix");
               scanf ("%d",&c6);

                }while (c6 < 0 &&  c6 > 2);
                switch (c6) {
            case 1 : StatMois(f,TabCat,NbCat);
                break;
                case 2 : StatAnnee(f,TabCat,NbCat);
                    break;
                }
                    break;

      break;
    }



    }

  }
  while(choix != 0);

    return 0;
}
