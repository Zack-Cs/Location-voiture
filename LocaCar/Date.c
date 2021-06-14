#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototypes.h"

void Affiche_mois(int m)
{ switch(m)
  { case 1:printf("janvier");
    break;
    case 2:printf("fevrier");
    break;
    case 3:printf("mars");
    break;
    case 4:printf("avril");
    break;
    case 5:printf("mai");
    break;
    case 6:printf("juin");
    break;
    case 7:printf("juillet");
    break;
    case 8:printf("aout");
    break;
    case 9:printf("septembre");
    break;
    case 10:printf("octobre");
    break;
    case 11:printf("novembre");
    break;
    case 12:printf("decembre");
    break;
  }
}

void Affiche_date(st_date date)
{ printf("%d ",date.jour);
Affiche_mois(date.mois);
printf(" %d \n",date.annee);
}


int Comparer_date(st_date debut, st_date fin)
{ int comp;
comp = debut.annee - fin.annee;
if(comp==0)
    { comp = debut.mois - fin.mois;
      if(comp==0) comp = debut.jour - fin.jour;
    }
return comp;
}

st_date date_AIDE(st_date date)
{ st_date copie = {date.jour,date.mois,date.annee};
return copie;
}

int Fev_29(int annee)
{ int letest;
if(annee%4==0 && annee%100!=0) letest = 1;
else letest = annee%400==0;
return letest;
}

int nb_jours_du_mois(int annee, int mois)
{ int nb_jr;
switch(mois)
  { case 1:;
    case 3:;
    case 5:;
    case 7:;
    case 8:;
    case 10:;
    case 12:nb_jr = 31;
    break;
    case 4:;
    case 6:;
    case 9:;
    case 11:nb_jr = 30;
    break;
    default:{   if(Fev_29(annee)) nb_jr = 29;
                else nb_jr = 28;
            };
  }
return nb_jr;
}

void control_lireDate(st_date *date)
{ int var,duree;

do{
    printf("Entrez l'annee (%d <= ) : ",2020);
    scanf("%d",&var);
  }while(var<2020);
date->annee = var;

do{
    printf("Entrez le mois  : ");
    scanf("%d",&var);
  }while(var<1 || var>12);
date->mois = var;

duree = nb_jours_du_mois(date->annee,date->mois);
do{
    printf("Entrez le jour (<=%d) : ",duree);
    scanf("%d",&var);
  }while(var<1 || var>duree);
date->jour = var;
}


void incrementation_jour(st_date* date)
{ int d;
d = nb_jours_du_mois(date->annee, date->mois);
if(date->jour<d) date->jour += 1;
else {
    date->jour = 1;
    if(date->mois==12)
        { date->mois = 1;
          date->annee +=  1;
        }
    else  date->mois += 1;
    }
}

int fct_Duree(st_date debut, st_date fin)
{ st_date c_debut,c_fin;
  int comp,duree=0;

comp = Comparer_date(debut,fin);

if(comp<0)
    { c_debut = date_AIDE(debut);
      c_fin = date_AIDE(fin);
    }
while(comp!=0)
    { incrementation_jour(&c_debut);
      duree++;
      comp = Comparer_date(c_debut,c_fin);
    }
return duree;
}
