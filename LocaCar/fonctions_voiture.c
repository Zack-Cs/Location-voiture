#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototypes.h"

void direction_voiture(int choix_v)
{
   switch(choix_v)
   {
   case 1:lister_voiture("file_voiture.txt");
   break;
   case 2:Ajouter_voiture();
   break;
   case 3:{
       coppy_file("file_voiture.txt","file_aide.txt");
       modifier_voiture();
           };
   break;
   case 4:{
       coppy_file("file_voiture.txt","file_aide.txt");
       suppri_voiture();
           };
   break;
   case 5:MenuPrincipal(today);
   break;
  }
}

void Menu_G_voitures(void)
{   int choix_v;
do{
  printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
  printf("\n                               \xb3 Gestion des voitures  \xb3");
  printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Liste des voitures....................1   \xba");
    printf("\n               \xba    Ajouter une voiture...................2   \xba");
    printf("\n               \xba    Modifier une voiture..................3   \xba");
    printf("\n               \xba    Supprimer une voiture.................4   \xba");
    printf("\n               \xba    Retour................................5   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix_v);
}while(choix_v>5 || choix_v <0);
    direction_voiture(choix_v);
    Menu_G_voitures();
}

void lister_voiture(char* fichier)
{
   voiture vcar;
  FILE *ptfich = NULL;
ptfich = fopen(fichier, "r");

if (!ptfich)
 {
  printf("Impossible d'ouvrir le fichier %s",fichier);
  exit(1);
  }

  while(!feof(ptfich))
   {
  fscanf(ptfich,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",&vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,&vcar.nbplaces,&vcar.prixJour,vcar.EnLocation);

   printf("\n\xb0\xb0\xb0 id de la voiture  %d \n",vcar.idVoiture);
   printf("   la marque       : %s \n",vcar.marque);
   printf("   le nom          : %s \n",vcar.nomVoiture);
   printf("   la couleur      : %s \n",vcar.couleur);
   printf("   le nb de places : %d \n",vcar.nbplaces);
   printf("   le prix par jour: %d Dh\n",vcar.prixJour);
   printf("  statut de Location: %s \n",vcar.EnLocation);
   printf("  \xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n");
    }
  fclose(ptfich);
}

void Ajouter_voiture(void)
{    int test_id;
  voiture vcar;
  FILE* ptfich = NULL;

ptfich = fopen("file_voiture.txt", "a+");
if (ptfich != NULL)
{

   do{
    printf("\n Entrer idVoiture         : ");
   fflush(stdin);
    scanf("%d",&vcar.idVoiture);
      test_id=find_id(vcar.idVoiture);
    }while(test_id);
    new_id(vcar.idVoiture);


    printf("\n Entrer la marque         : ");
   fflush(stdin);
    gets(vcar.marque);
    printf("\n Entrer nom de Voiture    : ");
   fflush(stdin);
    gets(vcar.nomVoiture);
    printf("\n Entrer la couleur        : ");
   fflush(stdin);
    gets(vcar.couleur);
    printf("\n Entrer le nombre de places : ");
   fflush(stdin);
    scanf("%d",&vcar.nbplaces);
    printf("\n Entrer le prix par jour    : ");
   fflush(stdin);
    scanf("%d",&vcar.prixJour);
    printf("\n Entrer statut de Location  : ");
   fflush(stdin);
    gets(vcar.EnLocation);

    fprintf(ptfich,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,vcar.nbplaces,vcar.prixJour,vcar.EnLocation);
  fclose(ptfich);
  printf("\n      Operation accomplie    \n\n");
}
else {
        printf("Impossible d'ouvrir le fichier !!");
     }
}

void modifier_voiture(void)
{ int trouve=0;
  int test_id;
  voiture vcar,vcar1;
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
  printf("\n Entrer le idVoiture et le nom de voiture a modifier :  ");
  scanf("%d %s",&vcar1.idVoiture,vcar1.nomVoiture);

    while(!feof(file_src))
     {
        fscanf(file_src,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",&vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,&vcar.nbplaces,&vcar.prixJour,vcar.EnLocation);

        if( vcar1.idVoiture!=vcar.idVoiture || strcmp(vcar1.nomVoiture,vcar.nomVoiture)!=0)
        {
         fprintf(file_dst,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,vcar.nbplaces,vcar.prixJour,vcar.EnLocation);
        }
        else
        {
         if (strcmp("oui",vcar.EnLocation)==0)
            {
             printf(" la voiture demande est en location pour le moment\n d\x82s son retour vous pouvez effectuer des modifications !!");
            }
          else {

        printf("\nPour modifier Entrer le nouveau  idVoiture (sinon Entrer 0) : ");
       fflush(stdin);
        scanf("%d",&vcar1.idVoiture);

    if (vcar1.idVoiture!=0)
      {
          test_id=find_id(vcar1.idVoiture);
         do{
       if(test_id){
       			 printf("\n id entrer est ivalid ");
                 printf("\n Entrer de nouveau  idVoiture :");
                 fflush(stdin);
                scanf("%d",&vcar1.idVoiture);
                test_id=find_id(vcar1.idVoiture);
                }
             }while(test_id );
           new_id(vcar1.idVoiture);
           supprimer_id(vcar.idVoiture);
           vcar.idVoiture=vcar1.idVoiture;
      }


        printf("\nPour modifier Entrer la nouvelle marque (sinon Entrer n) : ");
       fflush(stdin);
        gets(vcar1.marque);
        if (strcmp("n",vcar1.marque)!=0 && strcmp("",vcar1.marque)!=0)
                {  strcpy(vcar.marque,vcar1.marque); }


        printf("\nPour modifier Entrer le nouveau  nom (sinon Entrer n) : ");
       fflush(stdin);
        gets(vcar1.nomVoiture);
        if (strcmp("n",vcar1.nomVoiture)!=0 && strcmp("",vcar1.nomVoiture)!=0)
                {  strcpy(vcar.nomVoiture,vcar1.nomVoiture); }



        printf("\nPour modifier Entrer la nouvelle couleur (sinon Entrer n) : ");
       fflush(stdin);
        gets(vcar1.couleur);
        if (strcmp("n",vcar1.couleur)!=0 && strcmp("",vcar1.couleur)!=0)
                {  strcpy(vcar.couleur,vcar1.couleur); }


        printf("\nPour modifier Entrer le nouveau nombre de places (sinon Entrer 0) : ");
       fflush(stdin);
        scanf("%d",&vcar1.nbplaces);
        if (vcar1.nbplaces!=0)
                {  vcar.nbplaces=vcar1.nbplaces; }
        printf("\nPour modifier Entrer le nouveau prix par jour (sinon Entrer 0) : ");
       fflush(stdin);
        scanf("%d",&vcar1.prixJour);
        if (vcar1.prixJour!=0)
                {  vcar.prixJour=vcar1.prixJour; }


        printf("\nPour modifier Entrer le nouveau statut de Location (sinon Entrer n) : ");
       fflush(stdin);
        gets(vcar1.EnLocation);
        if (strcmp("n",vcar1.EnLocation)!=0 && strcmp("",vcar1.EnLocation)!=0)
                {  strcpy(vcar.EnLocation,vcar1.EnLocation); }


        trouve=1;
    fprintf(file_dst,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,vcar.nbplaces,vcar.prixJour,vcar.EnLocation);
            }
        }
     }
      fclose(file_dst);
      fclose(file_src);
     if(!trouve) printf("\n Cette voiture n'existe pas dans la base de donnees \n\n");
     else printf("\n      Operation accomplie    \n\n");
}

void suppri_voiture(void)
{  int trouve=0;
  voiture vcar,vcar1;
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
  printf("\n Entrer le idVoiture et le nom de voiture a Supprimer :  ");
  scanf("%d %s",&vcar1.idVoiture,vcar1.nomVoiture);

    while(!feof(file_src))
     {
        fscanf(file_src,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",&vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,&vcar.nbplaces,&vcar.prixJour,vcar.EnLocation);

      if( vcar1.idVoiture!=vcar.idVoiture || strcmp(vcar1.nomVoiture,vcar.nomVoiture)!=0)
        {
         fprintf(file_dst,"%d \n%s \n%s \n%s \n%d \n%d \n%s \n\n",vcar.idVoiture,vcar.marque,vcar.nomVoiture,vcar.couleur,vcar.nbplaces,vcar.prixJour,vcar.EnLocation);
        }
     else { trouve=1;
            supprimer_id(vcar.idVoiture);
         }
     }
      fclose(file_src);
      fclose(file_dst);
     if(!trouve) printf("\n Cette voiture n'existe pas dans la base de donnees \n\n");
     else printf("\n      Operation accomplie    \n\n");
}
