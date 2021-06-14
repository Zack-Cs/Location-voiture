#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define  Maxcar 40


void welcome(void);
void hi(void);
void lister_voiture(char* fichier);
void lister_client(char* fichier);
void coppy_file(char *lefichier,char *fcoppy);


typedef struct
{ int jour;
  int mois;
  int annee;
} st_date;

st_date  today;

typedef struct voiture
{
int idVoiture;
char marque[15];
char nomVoiture[15];
char couleur[12];
int nbplaces;
int prixJour;
char EnLocation[4];
}voiture;

typedef struct contratLocation
{
int numContrat;
int idVoiture;
int idClient;
st_date debut;
st_date fin;
int cout;
}contrat;

typedef struct client
{
int idClient;
char nom[20];
char prenom[20];
int cin;
char adresse[15];
int telephone;
}client;

void direction_client(int choix_c);
void direction_location(st_date today,int choix_l);
void direction_voiture(int choix_v);

void MenuPrincipal(st_date today);
void Menu_G_voitures(void);
void Ajouter_voiture(void);
void modifier_voiture(void);
void suppri_voiture(void);
void Menu_G_clients(void);
int controle_num_tele(int tel);
void Ajouter_client(void);
void modifier_client(void);
void suppri_client(void);
void Menu_L_voitures(st_date today);
void Affiche_contrat(void);
int find_client( client *c_clt);
int find_voiture(voiture *c_vcar);
void louer_voiture(st_date today,client *clt,voiture *vcar);
void creation_contrat(st_date today);
void modifier_contrat(void);
void suppri_contrat(voiture *vcar1);
void retourner_voiture(void);


//ID

void new_id( int id);
int find_id( int id);
void supprimer_id( int id);

//DATE

void control_lireDate(st_date* date);
int Comparer_date(st_date debut,st_date fin);
int fct_Duree(st_date debut, st_date fin);
void Affiche_date(st_date date);

void Affiche_mois(int m);
st_date date_AIDE(st_date date);
int Fev_29(int annee);
int nb_jours_du_mois(int annee, int mois);
void incrementation_jour(st_date* date);
