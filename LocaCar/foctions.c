#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototypes.h"

void hi(void)
{
printf("      \xDA\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xBF\n");
printf("      \xb3   ZAKARIA MAZIH SMI4 G3a   \xb3\n");
printf("      \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xD9\n");
}
void welcome(void)
{
hi();
printf("\n\n");
    printf("         \xdb\n");
    printf("         \xdb             \xdb\xdb\xdb\xdb SERVICE \n");
    printf("         \xdb             \xdb     \xdc\xdc  \n");
    printf("         \xdb     \xdb\xdb\xdb \xdb\xdb\xdb \xdb       \xdb \n");
    printf("         \xdb     \xdb \xdb \xdb   \xdb    \xdb\xdb\xdb\xdb \xdb\xdf\n");
    printf("         \xdbLUXE \xdb \xdb \xdb   \xdb    \xdb  \xdb \xdb\n");
    printf("         \xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb \xdb\xdb\xdb \xdb\xdb\xdb\xdb \xdf\xdb\xdb\xdb \xdb\n");
    printf("\n");

 Sleep(1333);
printf("   LOCATION");
 Sleep(1000);
printf("   DES   ");
 Sleep(1000);
printf(" VOITURES ");
 Sleep(1000);
printf("   DE   ");
 Sleep(1000);
printf(" LUXE ");
printf("\n\n\n");

}


int find_id( int id)
{
  int var,trouve=0;
 FILE  *ptfich = NULL;

ptfich= fopen("file_id.txt","r");
   if (!ptfich)
     {
      printf("Impossible d'ouvrir %s.\n", "file_id.txt");
      exit(1);
     }
  while (!feof(ptfich) && !trouve)
     {
        fscanf(ptfich,"%d\n",&var);
      if(var==id)
        {
          trouve=1;
        }
      }
   fclose(ptfich);
           return trouve;
}

void new_id( int id)
{
 FILE  *ptfich = NULL;

ptfich= fopen("file_id.txt","a");
   if (!ptfich)
     {
      printf("Impossible d'ouvrir %s.\n", "file_id.txt");
      exit(1);
     }

        fprintf(ptfich,"%d\n",id);

   fclose(ptfich);
}

void supprimer_id( int id)
{
  int var;
FILE* file_src= NULL;
FILE* file_dst= NULL;

 coppy_file("file_id.txt","file_aide.txt");
file_src= fopen("file_aide.txt","r");
  if (!file_src)
    {
      printf("Impossible d'ouvrir %s.\n", "file_aide.txt");
      exit(1);
    }
file_dst= fopen("file_id.txt","w");
if(!file_dst)
    {
    printf("Impossible d'ouvrir %s.\n", "file_id.txt");
    exit(1);
    }

    while(!feof(file_src))
     {
        fscanf(file_src,"%d\n",&var);

        if( var!=id)
        {
         fprintf(file_dst,"%d\n",var);
        }

     }
      fclose(file_dst);
      fclose(file_src);
}




void coppy_file(char *lefichier,char *fcoppy)
{
  char ligne[Maxcar];
  FILE  *file_src= NULL;
  FILE  *file_dst= NULL;

file_dst= fopen(fcoppy,"w");
file_src= fopen(lefichier,"r");

  if (file_dst == NULL)
    {
    printf("Impossible d'ouvrir le fichier %s",fcoppy);
    }
  if (file_src == NULL)
    {
    printf("Impossible d'ouvrir le fichier %s",lefichier);
    }

  else
    {
      while(fgets(ligne,Maxcar,file_src)!=NULL)
        {
          fprintf(file_dst,"%s",ligne);
        }
      fclose(file_src);
      fclose(file_dst);
    }
}

void MenuPrincipal(st_date today)
{	int choix;
do{
  printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
  printf("\n                               \xb3 Menu Principal  \xb3");
  printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n               \xba                                              \xba");
    printf("\n               \xba    Location..............................1   \xba");
    printf("\n               \xba    Gestion voitures......................2   \xba");
    printf("\n               \xba    Gestion clients.......................3   \xba");
    printf("\n               \xba    Quitter...............................4   \xba");
    printf("\n               \xba                                              \xba");
    printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                Votre choix  :  ");

    scanf("%d",&choix);
    } while(choix >4 || choix <0);

    switch(choix)
   {
    case 1:Menu_L_voitures(today);
    break;
    case 2:Menu_G_voitures();
    break;
    case 3:Menu_G_clients();
    break;
    case 4:exit(1);
    break;

  }
}
