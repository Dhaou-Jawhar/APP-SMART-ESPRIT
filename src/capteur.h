#include <gtk/gtk.h>

typedef struct{
int jour;
int mois;
int annee;
}Date;

typedef struct capteur capteur ;
struct capteur{
char reference[30];
char type[30];
char heure[30];
int valeur;
int etage;
Date dt;
};



