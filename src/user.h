#include <gtk/gtk.h>


typedef struct
{
int j;
int m;
int a;
} calander;


typedef struct 
{
char prenom[50];
char nom[50];
char username[50];
char password[50];
char role[50];
char cin[100];
int niv;
char date[100];
}personne;

void ajouter_user(char fname[], personne p, int c);
void ajouter_Niveau(personne p);
int choix(personne p);
void afficher_user(char fname [],GtkWidget *liste);
void supprimer_user( char fname[] ,char e []);
int verif(char username[], char password[]);
int verification(char log[], char Pw[]);
int recherche(char nom_cin[]);
void modif(int a,char cin[30],char nom[20],char prenom[20],char username[20],char password[10],char date[100],char role[30],char id[10]);
void modifier_user (char fname [],char e [],personne p,char id[]);
//void modifier_niveau (char fname[], int n, personne p);


