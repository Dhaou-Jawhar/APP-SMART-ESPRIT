#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>


typedef struct
{char bhyidentifiant [100];
 char bhynom [100] ;
 char bhytype [100];
 char bhyfournisseur [100];
 char bhycout [100];
 char bhyquantite [100];
 char bhydate [100];
 char bhystock [100];
}information;

void bhyajouter (char fname[], information inf);
void bhysupprimer ( char fname[] ,char bhyid []);
void bhyrecherche (char fname[] ,char bhyid []);
void bhymodifier (char fname [],char bhyid [],information info);
void bhyAfficher(char fname [],GtkWidget *liste);
int bhystock(char fname [], char bhyquantite []);
void pos_car(char T[], char c, int *p_occ, int *d_occ);
void recherche_stock (char fname [],char st []);
int is_unique(char fname[], char id []);
