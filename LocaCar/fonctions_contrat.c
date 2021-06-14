#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototypes.h"

void direction_location(st_date today,int choix_l)
{
switch(choix_l)
  {
   case 1:Affiche_contrat();
   break;
   case 2:creation_contrat(today);
   break;
   case 3:retourner_voiture();
   break;
   case 4:modifier_contrat();
   break;
   case 5:MenuPrincipal(today);
   break;
  }
}

void Menu_L_voitures(st_date today)
{	int choix_l;
do{
  printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
  printf("\n                               \xb3  Loction des voitures \xb3");
  printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Visualiser contrat....................1   \xba");
    printf("\n               \xba    Louer une voiture.....................2   \xba");
    printf("\n               \xba    Retourner une voiture.................3   \xba");
    printf("\n               \xba    Modifier un contrat...................4   \xba");
    printf("\n               \xba    Retour................................5   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix_l);
}while(choix_l>5 || choix_l <0);
    direction_location(today,choix_l);
    Menu_L_voitures(today);
}

void Affiche_contrat(void)
{
  contrat ctrt ,ctrt1;
  int trouve=0;
  FILE* ptfich = NULL;

ptfich = fopen("file_contrats.txt", "r");
  if (!ptfich)
    {
      printf("Impossible d'ouvrir %s.\n", "file_contrats.txt");
      exit(1);
    }
  printf("\n Entrer le num du contrat a visualiser : ");
  scanf("%d",&ctrt1.numContrat);

    while(!feof(ptfich) && !trouve)
     {
        fscanf(ptfich,"%d \n%d \n%d \n%d %u %d \n%d %u %d \n%d \n\n",&ctrt.numContrat,&ctrt.idVoiture,&ctrt.idClient,&ctrt.debut.jour,&ctrt.debut.mois,&ctrt.debut.annee,&ctrt.fin.jour,&ctrt.fin.mois,&ctrt.fin.annee,&ctrt.cout);

        if( ctrt1.numContrat==ctrt.numContrat)
        {
          printf("\n\xb0\xb0\xb0 Contrat %d \n\n",ctrt.numContrat);
          printf("   id de voiture      : %d \n",ctrt.idVoiture);
          printf("   id du client       : %d \n",ctrt.idClient);
          printf("   la date de debut  ");
          Affiche_date(ctrt.debut);
          printf("   la date de fin    ");
          Affiche_date(ctrt.fin);
          printf("   le cout           %d Dh\n\n",ctrt.cout);
          printf("  \xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n");
          trouve=1;
        }
     }
  if (!trouve) printf("\n Ce contrat  n'existe pas dans la base de donnees\n\n");
    fclose(ptfich);
}



void retourner_voiture(void)
{
 voiture vcar,vcar1;
coppy_file("file_voiture.txt","file_aide.txt");

  FILE* file_src= NULL;
  FILE* file_dst= NULL;

file_src= fopen("file_aide.txt","r");
  if (!file_src)
    {
      printf("Impossible d'ouvrir %s.\n", "file_aide.txt");
      exit(1);
    }
file_dst= fopen("file_voiture.txt","w");
if(!file_dst)
    {
    printf("Impossible d'ouvrir %s.\n", "file_voiture.txt");
    exit(1);
    }

  printf("\n Entrer le idVoiture de voiture retourner : ");
  scanf("%d",&vcar1.idVoiture);

 while(!feof(file_src))
    {
   fscanf(file_src,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",&vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,&vcar.nbplaces,&vcar.prixJour,vcar.EnLocation);
    if(vcar1.idVoiture==vcar.idVoiture)  strcpy(vcar.EnLocation,"non");

     fprintf(file_dst,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,vcar.nbplaces,vcar.prixJour,vcar.EnLocation);
   }

   fclose(file_dst);
   fclose(file_src);


    suppri_contrat(&vcar1);

}

void suppri_contrat(voiture *vcar1)
{

  contrat ctrt;
  FILE* file_src= NULL;
  FILE* file_dst= NULL;

coppy_file("file_contrats.txt","file_aide.txt");

file_src= fopen("file_aide.txt","r");
  if (!file_src)
    {
      printf("Impossible d'ouvrir %s.\n", "file_aide.txt");
      exit(1);
    }
file_dst= fopen("file_contrats.txt","w");
if(!file_dst)
    {
    printf("Impossible d'ouvrir %s.\n", "file_contrats.txt");
    exit(1);
    }


while(!feof(file_src))
    {
     fscanf(file_src,"%d \n%d \n%d \n%d %u %d \n%d %u %d \n%d \n\n",&ctrt.numContrat,&ctrt.idVoiture,&ctrt.idClient,&ctrt.debut.jour,&ctrt.debut.mois,&ctrt.debut.annee,&ctrt.fin.jour,&ctrt.fin.mois,&ctrt.fin.annee,&ctrt.cout);

     if(ctrt.idVoiture!=vcar1->idVoiture)
      {
      fprintf(file_dst,"%d \n%d \n%d \n%d %u %d \n%d %u %d \n%d \n\n",ctrt.numContrat,ctrt.idVoiture,ctrt.idClient,ctrt.debut.jour,ctrt.debut.mois,ctrt.debut.annee,ctrt.fin.jour,ctrt.fin.mois,ctrt.fin.annee,ctrt.cout);
      }
    else supprimer_id(ctrt.numContrat);

   }

   fclose(file_dst);
   fclose(file_src);
   printf("\n      Operation accomplie    \n\n");
}


void modifier_contrat(void)
{ int trouve=0;
  int mod,prixParJour,a;
  int num, test_id;
  st_date date_retour;
  contrat ctrt,ctrt1;
  FILE* file_src= NULL;
  FILE* file_dst= NULL;

coppy_file("file_contrats.txt","file_aide.txt");

file_src= fopen("file_aide.txt","r");
  if (!file_src)
    {
      printf("Impossible d'ouvrir %s.\n", "file_aide.txt");
      exit(1);
    }
file_dst= fopen("file_contrats.txt","w");
if(!file_dst)
    {
    printf("Impossible d'ouvrir %s.\n", "file_contrats.txt");
    exit(1);
    }

  printf("\n Entrer le num du contrat a modifier : ");
  scanf("%d",&ctrt1.numContrat);

while(!feof(file_src))
    {
     fscanf(file_src,"%d \n%d \n%d \n%d %d %d \n%d %d %d \n%d \n\n",&ctrt.numContrat,&ctrt.idVoiture,&ctrt.idClient,&ctrt.debut.jour,&ctrt.debut.mois,&ctrt.debut.annee,&ctrt.fin.jour,&ctrt.fin.mois,&ctrt.fin.annee,&ctrt.cout);

     if(ctrt1.numContrat!=ctrt.numContrat)
      {
      fprintf(file_dst,"%d \n%d \n%d \n%d %d %d \n%d %d %d \n%d \n\n",ctrt.numContrat,ctrt.idVoiture,ctrt.idClient,ctrt.debut.jour,ctrt.debut.mois,ctrt.debut.annee,ctrt.fin.jour,ctrt.fin.mois,ctrt.fin.annee,ctrt.cout);
      }
      else
      { a=fct_Duree(ctrt.debut,ctrt.fin);
        prixParJour=(ctrt.cout/a);

        printf("\nPour modifier la nouvelle date de retour Entrer 1 (sinon 0): ");
        scanf("%d",&mod);
        if (mod!=0)
         {
         do{
           printf("\n Saisir la nouvelle date de retour \n");
           control_lireDate(&date_retour);
           } while (Comparer_date(ctrt.debut,date_retour)>=0);
         ctrt.fin=date_retour;
         }
       ctrt.cout=prixParJour*fct_Duree(ctrt.debut,ctrt.fin);

        printf("\nPour modifier Entrer le nouveau numero du contrat(sinon 0): ");
        scanf("%d",&num);
      if(num!=0)
          {
          test_id=find_id(num);
         do{
       if(test_id){
             printf("\n numero de contrat est ivalid ");
             printf("\n Entrer de nouveau  numero de contrat :");
             fflush(stdin);
             scanf("%d",&num);
                test_id=find_id(num);
                }
             }while(test_id );
           new_id(num);
           supprimer_id(ctrt.numContrat);
              ctrt.numContrat=num;
          }

fprintf(file_dst,"%d \n%d \n%d \n%d %u %d \n%d %u %d \n%d \n\n",ctrt.numContrat,ctrt.idVoiture,ctrt.idClient,ctrt.debut.jour,ctrt.debut.mois,ctrt.debut.annee,ctrt.fin.jour,ctrt.fin.mois,ctrt.fin.annee,ctrt.cout);
   trouve=1;
   }
      }
   fclose(file_dst);
   fclose(file_src);
if (!trouve) printf("\n Ce contrat  n'existe pas dans la base de donnees\n\n");
   else printf("\n      Operation accomplie    \n\n");
}

int find_client( client *c_clt)
{
  client clt ,clt1;
  int trouve_c=0;
 FILE  *ptfich = NULL;

ptfich= fopen("file_client.txt", "r");
   if (!ptfich)
     {
      printf("Impossible d'ouvrir %s.\n", "file_client.txt");
      exit(1);
     }
   printf("\n Entrer le nom et prenom du client : ");
   scanf("%s %s",clt1.nom,clt1.prenom);
  while (!feof(ptfich) && !trouve_c)
     {
        fscanf(ptfich,"%d \n%s \n%s \n%d \n%s \n%d \n\n",&clt.idClient,clt.nom,clt.prenom,&clt.cin,clt.adresse,&clt.telephone);

      if(strcmp(clt.nom,clt1.nom)==0 && strcmp(clt.prenom,clt1.prenom)==0)
        { *c_clt=clt;
          trouve_c=1;
        }
      }
   fclose(ptfich);
           return trouve_c;
}

int find_voiture(voiture *c_vcar)
{
  voiture vcar,vcar1;
  int trouve_v=0;
FILE* file_src= NULL;
FILE* file_dst= NULL;

 coppy_file("file_voiture.txt","file_aide.txt");
file_src= fopen("file_aide.txt","r");
  if (!file_src)
    {
      printf("Impossible d'ouvrir %s.\n", "file_aide.txt");
      exit(1);
    }
file_dst= fopen("file_voiture.txt","w");
if(!file_dst)
    {
    printf("Impossible d'ouvrir %s.\n", "file_voiture.txt");
    exit(1);
    }
  printf("\n Entrer le idVoiture et le nom de voiture : ");
  scanf("%d %s",&vcar1.idVoiture,vcar1.nomVoiture);

    while(!feof(file_src))
     {
        fscanf(file_src,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",&vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,&vcar.nbplaces,&vcar.prixJour,vcar.EnLocation);

        if( vcar1.idVoiture!=vcar.idVoiture || strcmp(vcar1.nomVoiture,vcar.nomVoiture)!=0)
        {
         fprintf(file_dst,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,vcar.nbplaces,vcar.prixJour,vcar.EnLocation);
        }
        else
        {     if (strcmp("non",vcar.EnLocation)==0)
                { strcpy(vcar.EnLocation,"oui");
                  trouve_v=1;
                  *c_vcar=vcar;
                 }
              else {trouve_v=2;
                   }

    fprintf(file_dst,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,vcar.nbplaces,vcar.prixJour,vcar.EnLocation);
        }
     }
      fclose(file_dst);
      fclose(file_src);
           return trouve_v;
}

void louer_voiture(st_date today,client *clt,voiture *vcar)
{ int test_id;
  contrat ctrt;
 FILE  *ptfich = NULL;

ptfich= fopen("file_contrats.txt","a");
   if (!ptfich)
     {
      printf("Impossible d'ouvrir %s.\n", "file_contrats.txt");
      exit(1);
     }
       do{
       printf("\n Entrer le num du contrat : ");
       fflush(stdin);
       scanf("%d",&ctrt.numContrat);
      test_id=find_id(ctrt.numContrat);
    }while(test_id);
    new_id(ctrt.numContrat);


       printf("\n Entrer la date de debut de location \n");

     do{
         control_lireDate(&ctrt.debut);
        } while (Comparer_date(today,ctrt.debut)>0);
           printf("\n Entrer la date de retour \n");
     do{
        control_lireDate(&ctrt.fin);
        } while (Comparer_date(ctrt.debut,ctrt.fin)>0);

         ctrt.cout=vcar->prixJour*fct_Duree(ctrt.debut,ctrt.fin);
         ctrt.idVoiture=vcar->idVoiture;
         ctrt.idClient=clt->idClient;

    fprintf(ptfich,"%d \n%d \n%d \n%d %u %d \n%d %u %d \n%d \n\n",ctrt.numContrat,ctrt.idVoiture,ctrt.idClient,ctrt.debut.jour,ctrt.debut.mois,ctrt.debut.annee,ctrt.fin.jour,ctrt.fin.mois,ctrt.fin.annee,ctrt.cout);
   fclose(ptfich);

}

void creation_contrat(st_date today)
{ int j=0,h,a;
  voiture vcar;
  client clt;

  j++;
  h=find_client(&clt);
  if(h==0 && j<2)
    {  printf("\n SVP essayer une 2 eme fois\n");
       h=find_client(&clt);
    }
  if (h==1)
  {
      a=find_voiture(&vcar);
      switch(a)
        { case 0:printf("\nla voiture demandee n'existe pas dans la base de donnees\n");
          break;
          case 1:louer_voiture(today,&clt,&vcar);
          break;
          case 2:printf("\nla voiture est en location (non disponible) \n");
          break;
        }
  }
  else { printf("\n Ce client n'existe pas dans la base de donnees\n\n");
         printf(">> redirection menu de gestion des clients\n\n");
         Ajouter_client();
          printf("\n >> redirection location dee voiture \n\n");
         creation_contrat(today);
         printf("\n      Operation accomplie    \n\n");
       }
}
