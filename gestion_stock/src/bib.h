#ifndef BIB_H_INCLUDED
#define BIB_H_INCLUDED

typedef struct {
  int idCat;
  char NomCat[30];
  } Categorie ;

  typedef struct  {
  int idType;
  char NomType[30];
  Categorie Cat;
  }Type;

  typedef struct {
  int jj;
  int mm;
  int aa;
  }MaDate ;

  typedef struct {
  int id;
  char nom[30];
  Type Typ;
  MaDate Date_expiration;
  }Produit;

  void InitCat(Categorie* c){
    printf("L'identificateur du categorie :\n");
    scanf("%d",&c->idCat);
    printf("Nom du categorie :\n");
    scanf("%s",&c->NomCat);
  }

  void initType (Type* t) {
      printf("L'identificateur du type :\n");
      scanf("%d",&t->idType);
      printf("Nom du type :\n");
      scanf("%s",&t->NomType);
      InitCat(&(t->Cat));
  }

  void initDate (MaDate* md) {
      do {
      printf("Le jour est :\n");
      scanf("%d",&md->jj); }
      while (md->jj < 1 || md->jj > 31);
      do {
      printf("Le mois est :\n");
      scanf("%d",&md->mm); }
      while ( md->mm < 1 || md->mm > 12 );
      do {
      printf("L'annee est :\n");
      scanf("%d",&md->aa); }
      while ( md->aa < 1000 || md->aa > 9999);
  }

  void initPdt (Produit* p) {
    printf("L'identificateur du produit :\n");
    scanf("%d",&p->id);
    printf("Nom du produit:\n");
    scanf("%s",&p->nom);
    initType (&(p->Typ));
    initDate (&(p->Date_expiration));
  }

  void menu(){
  printf ("0-Menu principal\n");
  printf ("1-Gestion de Stock\n");
  printf ("2-Vente et statistiques\n");
  }

  void gestionstock(){
      printf ("1.1-Gestion des categories \n");
      printf ("1.2-Gestion des types \n");
      printf ("1.3-Gestion des produits \n");
      printf ("1.4-Affichage du stock \n");
      printf ("1.5-Retour au menu principal \n");}


  void ventes(){
    printf ("2.1-Vente de produits\n");
    printf ("2.2-Statistiques\n");
    printf ("2.3- Retour au menu principal\n");

  }
  void gestioncategories() {
      printf ("1.1.1-Ajout d'une nouvelle categorie\n");
      printf ("1.1.2-Suppression d'une categorie\n");
      printf ("1.1.3-Retour au menu gestion de stock\n");
  }
   void gestiontypes () {
      printf ("1.2.1-Ajout d'une nouveau type \n");
      printf ("1.2.2-Suppression d'un type\n");
      printf ("1.2.3-Retour au menu gestion de stock\n");
  }
  void gestionproduits () {
      printf ("1.3.1-Ajout d'une nouveau produit \n");
      printf ("1.3.2-Suppression d'un produit\n");
      printf ("1.3.3-Retour au menu gestion de stock\n");
  }
  void stat () {
      printf ("2.2.1-Statistiques par mois  \n");
      printf ("2.2.2-Statistiques par ann�e \n");
      printf ("2.2.3-Retour au menu ventes et statistiques");

  }

void  Afficherstock(Produit Stock[][50],Type TabType[],int NbTyp,Categorie TabCat[],int NbCat ,int TabQte[]){
      for (int j=0;j<NbTyp;j++)
            {
                printf("   %d  | ",TabQte[j]);
            }
      printf("Etat Du Stock:\n");
      printf(" Categorie     Type     Qte     id_Pdt   date \n");
      for (int i=0;i<NbCat;i++)
      {
      printf(" %s ",TabCat[i].NomCat);
            for (int j=0;j<NbTyp;j++)
            {
                if(TabType[i].Cat.idCat==TabCat[j].idCat)
                {
      printf("  %s  ",TabType[i].NomType);
      printf("   %d ",TabQte[i]);
                    for (int k=0;k<TabQte[i];k++)
                      {
     printf(" %d ",Stock[k][j].id);
     printf(" %d / %d / %d \n",Stock[k][j].Date_expiration.jj,Stock[k][i].Date_expiration.mm,Stock[k][i].Date_expiration.aa);
     printf(" \n ");
                      }
             printf("  \n ");
                }
            }
      }

  }

void AjouterCat(Categorie TabCat[], int *NbCat) {
    Categorie c;
    InitCat(&c);
    int Catexists = 0;
    if (*NbCat < 20)
    {
          for (int i = 0; i < *NbCat; ++i)
            {
            if (TabCat[i].idCat == c.idCat)
            {
                printf("Cette categorie existe deja dans TabCat \n");
                Catexists = 1;
                break;
            }
           }
        if (!Catexists)
            {
            TabCat[*NbCat]=c;
             printf("Nouvelle categorie est %d \n",TabCat[*NbCat].idCat);
            (*NbCat)++;

            printf("Nouvelle categorie ajoutee avec succes \n");

            }
    }
    else
    {
        printf("TabCat plein \n");
    }
}

int existtype(Type TabType[], int NbType, int idt) {
    for (int i = 0; i < NbType; i++) {
        if (TabType[i].idType == idt) {
            return i;
        }
    }
    return -1;
}


void AjouterTyp(Type TabType[], int *NbTyp, Categorie TabCat[], int NbCat,int TabQte[] ) {
    Type t;
    initType(&t);
    int Catexists = 0;
    printf("nbtype : %d \n",*NbTyp);
    int position = existtype(TabType,*NbTyp,t.idType);
    if (*NbTyp < 50)
    {
         for (int i = 0; i < NbCat; ++i)
          {
            if (TabCat[i].idCat == t.Cat.idCat)
            {
                Catexists = 1;
                break;
            }
           }

    if (Catexists==1)
        {
            if (position == -1)
            {
                TabType[*NbTyp]=t;
                TabQte[*NbTyp]=0;
                printf("Nouveau type est : %d\n",TabType[*NbTyp].idType);
                (*NbTyp)++;
                printf("Nouveau type ajoute avec succes\n");
            }
            else
            {
                printf("Ce type existe deja dans TabType\n");
            }
        }
    else
        {
            printf("La categorie du nouveau type n'existe pas dans TabCat\n");
        }
    }
    else
    {
        printf("TabType plein\n");
    }
}

int existproduit (Produit Stock[][50],int idp,int pos ,int l)
{
    for (int i=0;i<l;i++)
    {
        if (Stock[i][pos].id==idp)
        {
            return(i);
            break;
        }
    }
    return(-1);
}

void AjouterPdt (Produit Stock[][50],Type TabType[],int NbTyp, int TabQte[])
{
    int pos;
    Produit p ;
    initPdt(&p);


    pos=existtype(TabType,NbTyp,p.Typ.idType);
    printf("%d \n",pos);
    if (pos !=-1)
    {
        if ((TabQte[pos]<100)&& (existproduit(Stock,p.id,pos,TabQte[pos])==-1))
        {
            Stock[TabQte[pos]][pos]=p;
            (TabQte[pos])++;
            printf("%d",TabQte[pos]);
            printf(" Produit ajoute avec succes  ");
        }
        else if (existproduit(Stock,p.id,pos,TabQte[pos])!=-1)
        {
            printf ("Ce produit existe deja dans la matrice "); }

            else if (TabQte[pos]>=100)
                {
            printf("Il existe plus q'un 100 produit");
        }
    }
    else
    {
        printf("Type n'existe pas") ;
    }

}


int existcateg_tabtype(Type TabType[],int NbTyp,int idt)
{int i;
    for (i=0;i< NbTyp;i++)
    {
        if (TabType[i].Cat.idCat==idt)
        {
            return(i);
            break;
        }

    }
   return(-1);

}//////

void SupprimerCat(Categorie TabCat[], int *NbCat,Type TabType[],int NbTyp) {
    int categorieIndex = -1;
    int idc;
    printf(" Donner id du categorie que vous souhaitez le supprimer \n");
    scanf("%d",&idc);
    for (int i = 0; i <*NbCat; ++i) {
        if (TabCat[i].idCat==idc) {
            categorieIndex = i;
            break;
        }
    }
    if ((categorieIndex != -1) &&(existcateg_tabtype(TabType,NbTyp,idc)==-1))
    {
        for (int i = categorieIndex; i <*NbCat-1; ++i)
            {
            TabCat[i]= TabCat[i+1];
        }
        (*NbCat)--;
        printf("Categorie supprimee avec succes \n");
    }
     else if (existcateg_tabtype(TabType,NbTyp,idc)!=-1)
     {
         printf(" cette categorie contient des types vous ne pouvez pas la supp \n ");
     }
    else
    {
        printf("La categorie a supprimer n'existe pas dans TabCat \n");
    }
}

void SupprimerTyp(Type TabType[],int *NbTyp,int TabQte[])
 {
    int idType;
    int typeIndex = -1;
    printf("Entrez l'ID du type a supprimer : ");
    scanf("%d",&idType);
    for (int i=0;i<*NbTyp;i++)
        {
        if(TabType[i].idType==idType)
        {
                        typeIndex =i;
                        break;

        }

    }

    if ((typeIndex != -1) &&(TabQte[typeIndex]==0))
    {


       for (int i = typeIndex; i <*NbTyp-1; i++)
        {
        TabType[i] = TabType[i+1];
        }
      (*NbTyp)--;

       printf("Type supprime avec succes \n");
    }
     else if (typeIndex==-1)
     {
          printf(" Ce type n'existe pas deja  \n ");

     }
     else
     {
         printf(" Ce type  contient des produits vous ne pouvez pas le supp \n ");
     }
}

int type_pdt( Produit Stock[][50],int idp)
  {
      for(int i=0;i<100;i++)
      {
          for(int j=0;j<50;j++)
          {
              if (Stock[i][j].id==idp)
              {
                  return(j);
              }
          }
      }
      return(-1);
  }

void SupprimerPdt(Produit Stock[][50],int TabQte[],Type TabType[],int NbTyp,int idp)
{
     int idt;
      int posp,post,qte;


      post=type_pdt(Stock,idp);
      qte=TabQte[post];
      posp=existproduit(Stock,idp,post,qte);



      if ( (post!=-1)&&(qte>10))
      {
          for (int i=posp;i<qte-1;i++)
          {
              Stock[i][post]=Stock[i+1][post];
          }
         printf("Produit supprime avec succes \n");
         TabQte[post]--;


      }

      else if (post==-1)
      {
           printf(" Ce produit ou ce type n'existe pas deja  \n ");
      }



      else
      {
           printf(" La quantite de ce type du produit est <10  \n ");
      }



}

int comparerdate(MaDate *mindate,MaDate date)
{
    if (date.aa < mindate->aa)
    {
       *mindate= date;
       return(0);
    }
    else if( (date.aa == mindate->aa)&&(date.mm < mindate->mm))
    {
        *mindate= date;
         return(0);
    }
    else if ((date.aa == mindate->aa)&&(date.mm == mindate->mm)&&(date.jj < mindate->jj))
    {
        *mindate= date;
         return(0);
    }
    return(-1);
}


void VendrePdt(FILE *f,Produit Stock [][50],Type TabType [],int NbTyp,Categorie TabCat[],int NbCat ,int TabQte[],int idt){
   int position ,pmin;
   MaDate mindate ,datevente;
   position = existtype(TabType,NbTyp,idt);
   if (position!=-1)
   {
       pmin=0;
       mindate=Stock[0][position].Date_expiration;

       for(int i=1;i<TabQte[position];i++)
       {
           if (comparerdate(&mindate,Stock[i][position].Date_expiration)==0)
           {
               pmin=i;
           }
       }
       printf("Date produit a vendre %d \n",mindate.jj);

       printf(" >> entrez la date de vente \n");
         initDate(&datevente);
         f=fopen("trace.txt","a");
         if (f!=NULL)
            {
              fprintf(f,"%d %s %d %s %d %s %d/%d/%d\n",Stock[pmin][position].id,Stock[pmin][position].nom,
                 TabType[position].idType,TabType[position].NomType,
                 TabType[position].Cat.idCat,TabType[position].Cat.NomCat,datevente.jj,datevente.mm,datevente.aa);

            }

   } else {
       printf ("Ce produit n'existe pas");
   }

    SupprimerPdt(Stock,TabQte,TabType,NbTyp,Stock[pmin][position].id);
   fclose(f);

 }
void StatMois(FILE *f,Categorie TabCat[], int NbCat) {
    int totalVentes = 0;
    int ventesParCategorie[20] = {0};

    f = fopen("Trace.txt", "r");
    int id, idType, idCat;
    char nom[30], NomType[30], NomCat[30];
    MaDate dateVente;
    int mois, annee;
    printf("Entrez le mois : ");
    scanf("%d", &mois);
    printf("Entrez l'annee : ");
    scanf("%d", &annee);

    while (fscanf(f, "%d %s %d %s %d %s %d/%d/%d",
                  &id, nom, &idType, NomType, &idCat, NomCat,
                  &dateVente.jj, &dateVente.mm, &dateVente.aa) == 9) {


        if (dateVente.mm == mois && dateVente.aa == annee && dateVente.aa!= 0) {
            totalVentes++;
            for (int k = 0; k < NbCat; k++) {
                if (TabCat[k].idCat == idCat) {
                    ventesParCategorie[k]++;
                    break;
                }
            }
        }
    }

    fclose(f);
    printf("Nombre total de ventes : %d\n", totalVentes);

    printf("Nombre de ventes par categorie :\n");
    for (int k = 0; k < NbCat; k++) {
        printf("%s : %d\n", TabCat[k].NomCat, ventesParCategorie[k]);
    }
    printf("Nombre de ventes par annee : %d\n", totalVentes);
}



void StatAnnee(FILE *f,Categorie TabCat[], int NbCat) {
    int totalVentes = 0;
    int ventesParCategorie[20] = {0};


    f = fopen("Trace.txt", "r");
    int id, idType, idCat;
    char nom[30], NomType[30], NomCat[30];
    MaDate dateVente;
    int annee;
    printf("Entrez l'annee : ");
    scanf("%d", &annee);
    while (fscanf(f, "%d %s %d %s %d %s %d/%d/%d",
                  &id, nom, &idType, NomType, &idCat, NomCat,
                  &dateVente.jj, &dateVente.mm, &dateVente.aa) == 9)
    {
        if (dateVente.aa == annee)
            {
            totalVentes++;

            for (int i = 0; i < NbCat; i++)
                {
                if (TabCat[i].idCat == idCat)
                {
                    ventesParCategorie[i]++;
                    break;
                }
            }
        }
    }

    fclose(f);
    printf("Nombre total de ventes : %d\n", totalVentes);
    printf("Nombre de ventes par categorie :\n");
    for (int i = 0; i < NbCat; i++) {
        printf("%s : %d\n", TabCat[i].NomCat, ventesParCategorie[i]);
    }

    printf("Nombre de ventes par annee : %d\n", totalVentes);
}

#endif // BIB_H_INCLUDED
