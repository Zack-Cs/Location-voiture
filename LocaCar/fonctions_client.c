#include"prototypes.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void direction_client(int choix_c)
{
	switch(choix_c)
	{
	 case 1:lister_client("file_client.txt");
	 break;
	 case 2:Ajouter_client();
	 break;
	 case 3:{
       coppy_file("file_client.txt","file_aide.txt");
       modifier_client();
           };
   break;
   case 4:{
       coppy_file("file_client.txt","file_aide.txt");
       suppri_client();
           };
   break;
	 case 5:MenuPrincipal(today);
	 break;
	}
}

void Menu_G_clients(void)
{	int choix_c;
do{
  printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
  printf("\n                               \xb3  Gestion des Clients  \xb3");
  printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Liste des clients.....................1   \xba");
    printf("\n               \xba    Ajouter un client.....................2   \xba");
    printf("\n               \xba    Modifier un client....................3   \xba");
    printf("\n               \xba    Supprimer un client...................4   \xba");
    printf("\n               \xba    Retour................................5   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix_c);
}while(choix_c>5 || choix_c <0);
  direction_client(choix_c);
  Menu_G_clients();
}

void lister_client(char* fichier)
{
    client clt;
  FILE* ptfich = NULL;
ptfich = fopen(fichier, "r");

if (!ptfich)
 {
  printf("Impossible d'ouvrir le fichier %s",fichier);
  exit(1);
  }

  while(!feof(ptfich))
    {
   fscanf(ptfich,"%d \n%s \n%s \n%d \n%s \n%d \n\n",&clt.idClient,clt.nom,clt.prenom,&clt.cin,clt.adresse,&clt.telephone);

   printf("\n\xb0\xb0\xb0 id du client  %d \n",clt.idClient);
   printf("   le nom          : %s \n",clt.nom);
   printf("   le prenom       : %s \n",clt.prenom);
   printf("   le CIN          : %d \n",clt.cin);
   printf("   l'adresse       : %s \n",clt.adresse);
   printf("   le num de tel   : +212 %d\n",clt.telephone);
   printf("  \xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\xb0\n");
    }
  fclose(ptfich);
}


int controle_num_tele(int tel)
{ int i=0,num;
  num=tel;
  while(num)
  {
    num=num/10;
    i++;
  }
  if(i==9) return 1;
  else return 0;
}

void Ajouter_client(void)
{
  client clt;
  int tel,test_id;
  FILE* ptfich = NULL;

ptfich = fopen("file_client.txt", "a+");
if (ptfich != NULL)
{
  do{
    printf("\nEntrer idClient : ");
   fflush(stdin);
    scanf("%d",&clt.idClient);
      test_id=find_id(clt.idClient);
    }while(test_id);
    new_id(clt.idClient);

    printf("\nEntrer le nom : ");
   fflush(stdin);
    gets(clt.nom);
    printf("\nEntrer le prenom : ");
   fflush(stdin);
    gets(clt.prenom);
    printf("\nEntrer le CIN : ");
   fflush(stdin);
    scanf("%d",&clt.cin);
    printf("\nEntrer l'adresse : ");
   fflush(stdin);
    gets(clt.adresse);
    do{
        printf("\nEntrer le num de telephone : +212 ");
        fflush(stdin);
        scanf("%d",&clt.telephone);
        tel=controle_num_tele(clt.telephone);
    } while (!tel);


fprintf(ptfich,"%d \n%s \n%s \n%d \n%s \n%d \n\n",clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
  fclose(ptfich);
  printf("\n      Operation accomplie    \n\n");
}
else {
    printf("Impossible d'ouvrir le fichier !!");
     }
}

void suppri_client(void)
{ int trouve=0;
FILE* pt_src=NULL;
FILE* pt_dst=NULL;
client clt,clt1;

  pt_src = fopen( "file_aide.txt", "r");
   if (!pt_src)
     {
      printf("Impossible d'ouvrir %s.\n",  "file_aide.txt");
      exit(1);
     }

  pt_dst = fopen("file_client.txt", "w");
   if (!pt_dst)
     {
      printf("Impossible d'ouvrir %s.\n", "file_client.txt");
      exit(1);
     }
   printf("\nEntrer le nom et prenom du client a Supprimer : ");
   scanf("%s %s",clt1.nom,clt1.prenom);
  while (!feof(pt_src))
    {
        fscanf(pt_src,"%d \n%s \n%s \n%d \n%s \n%d \n\n",&clt.idClient,clt.nom,clt.prenom,&clt.cin,clt.adresse,&clt.telephone);

     if(strcmp(clt.nom,clt1.nom)!=0 || strcmp(clt.prenom,clt1.prenom)!=0)
        {
        fprintf(pt_dst,"%d \n%s \n%s \n%d \n%s \n%d \n\n",clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
        }
     else { trouve=1;
            supprimer_id(clt.idClient);
         }

    }
  fclose(pt_dst);
  fclose(pt_src);
    if(!trouve) printf("\n Ce client n'existe pas dans la base de donnees \n\n");
    else printf("\n      Operation accomplie    \n\n");
}

void modifier_client(void)
{ int tel ,trouve=0;
    int test_id;
FILE* pt_src=NULL;
FILE* pt_dst=NULL;
client clt,clt1;

  pt_src = fopen( "file_aide.txt", "r");
   if (!pt_src)
     {
      printf("Impossible d'ouvrir %s.\n",  "file_aide.txt");
      exit(1);
     }

  pt_dst = fopen("file_client.txt", "w");
   if (!pt_dst)
     {
      printf("Impossible d'ouvrir %s.\n", "file_client.txt");
      exit(1);
     }
   printf("\nEntrer le nom et prenom du client a modifier :  ");
   scanf("%s %s",clt1.nom,clt1.prenom);
  while (!feof(pt_src))
    {
        fscanf(pt_src,"%d \n%s \n%s \n%d \n%s \n%d \n\n",&clt.idClient,clt.nom,clt.prenom,&clt.cin,clt.adresse,&clt.telephone);

     if (strcmp(clt.nom,clt1.nom)!=0 || strcmp(clt.prenom,clt1.prenom)!=0)
        {
        fprintf(pt_dst,"%d \n%s \n%s \n%d \n%s \n%d \n\n",clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
        }
     else
      {

        printf("\nPour modifier Entrer le nouveau  idClient (sinon Entrer 0) : ");
       fflush(stdin);
        scanf("%d",&clt1.idClient);

        if (clt1.idClient!=0)
          {
              test_id=find_id(clt1.idClient);
             do{
           if(test_id){
           			 printf("\n id entrer est ivalid ");
                     printf("\n Entrer de nouveau  idClient :");
                     fflush(stdin);
                    scanf("%d",&clt1.idClient);
                    test_id=find_id(clt1.idClient);
                    }
                 }while(test_id );
               new_id(clt1.idClient);
               supprimer_id(clt.idClient);
               clt.idClient=clt1.idClient;

           }

        printf("\nPour modifier Entrer le nouveau  nom (sinon Entrer n) : ");
       fflush(stdin);
        gets(clt1.nom);
        if (strcmp("n",clt1.nom)!=0 && strcmp("",clt1.nom)!=0 )
                {  strcpy(clt.nom,clt1.nom); }


        printf("\nPour modifier Entrer le nouveau  prenom (sinon Entrer n) : ");
       fflush(stdin);
        gets(clt1.prenom);
        if (strcmp("n",clt1.prenom)!=0  && strcmp("",clt1.prenom)!=0)
                {  strcpy(clt.prenom,clt1.prenom); }


        printf("\nPour modifier Entrer le nouveau CIN (sinon Entrer 0) : ");
       fflush(stdin);
        scanf("%d",&clt1.cin);
        if (clt1.cin!=0)
                {  clt.cin=clt1.cin; }


        printf("\nPour modifier Entrer la nouvelle adresse (sinon Entrer n) : ");
       fflush(stdin);
        gets(clt1.adresse);
        if (strcmp("n",clt1.adresse)!=0  && strcmp("",clt1.adresse)!=0)
                {  strcpy(clt.adresse,clt1.adresse); }


        printf("\nPour modifier le num de telephone entrer 1 (sinon Entrer 0) :  ");
       fflush(stdin);
        scanf("%d",&clt1.telephone);
        if (clt1.telephone!=0)
            {
              do{
            printf("\nEntrer le nouveau num de telephone :\n");
            printf("                 +212 ");
            fflush(stdin);
            scanf("%d",&clt1.telephone);
        tel=controle_num_tele(clt1.telephone);
         clt.telephone=clt1.telephone;
              }while(!tel);
}
        trouve=1;
      fprintf(pt_dst,"%d \n%s \n%s \n%d \n%s \n%d \n\n",clt.idClient,clt.nom,clt.prenom,clt.cin,clt.adresse,clt.telephone);
      }
    }

  fclose(pt_dst);
  fclose(pt_src);
    if(!trouve)
        { printf("\n Ce client n'existe pas dans la base de donnees \n\n"); }
    else
        { printf("\n      Operation accomplie    \n\n"); }


}
