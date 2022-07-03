#ifdef HAVE_CONFIG_H
#  include<config.h>
#endif



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "capteur.h"
#include <gtk/gtk.h>






enum
{
      EREF,
      ETYPE,
      EHR,
      EETAGE,
      EVALEUR,
      EDATE,
      COLUMNS,
};



void ajouter_capteur(capteur c)
{
FILE* f;
f=fopen("fichier.txt","a+");
if(f!=NULL)
  { fprintf(f,"%s %s %s %d %d %d %d %d \n",c.reference,c.type,c.heure,c.etage,c.valeur,c.dt.jour,c.dt.mois,c.dt.annee);}
fclose(f);

}


void afficher_capteur(GtkWidget *liste )

{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("REF",renderer,"text",EREF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("HEURE",renderer,"text",EHR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ETAGE",renderer,"text",EETAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("VALEUR",renderer,"text",EVALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("fichier.txt","r");

char ref[30];
char type[30];
char hr[30];
char etage[30];
char valeur[30];
char jj[30];
char mm[30];
char aa[30];
char y[30]="";


{
f=fopen("fichier.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s \n",ref,type,hr,etage,valeur,jj,mm,aa)!=EOF)
	{strcpy(y,"");
	strcat(y,jj);strcat(y,"-");strcat(y,mm);strcat(y,"-");strcat(y,aa);
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EREF,ref,ETYPE,type,EHR,hr,EETAGE,etage,EVALEUR,valeur,EDATE,y,-1);
	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}



void rechercher_capteur(GtkWidget *liste , char ch[])

{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("REF",renderer,"text",EREF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("HEURE",renderer,"text",EHR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ETAGE",renderer,"text",EETAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("VALEUR",renderer,"text",EVALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("fichier.txt","r");

char ref[30];
char type[30];
char hr[30];
char etage[30];
char valeur[30];
char jj[30];
char mm[30];
char aa[30];
char y[30]="";


{
f=fopen("fichier.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %s %s \n",ref,type,hr,etage,valeur,jj,mm,aa)!=EOF)
	{ if ( strcmp(ref,ch)==0 || strcmp(etage,ch)==0 || strcmp(type,ch)==0 ){  // comparer la valeur ajouter ch par [ ref / etage / type ]
	strcpy(y,"");
	strcat(y,jj);strcat(y,"-");strcat(y,mm);strcat(y,"-");strcat(y,aa); // concatination du date -> j-m-a 
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EREF,ref,ETYPE,type,EHR,hr,EETAGE,etage,EVALEUR,valeur,EDATE,y,-1); // ajouter les lignes dans le treeview
	}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}



void supprimer_capteur (char id[]){

char ref[30];
char type[30];
char hr[30];
char etage[30];
char valeur[30];
char jj[30];
char mm[30];
char aa[30];

FILE*f=NULL;
FILE*f1=NULL;

f=fopen("fichier.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s \n",ref,type,hr,etage,valeur,jj,mm,aa)!=EOF){
if(strcmp(id,ref)!=0){ // comparaison ref = id / ref !!  si egale donc supp ligne 
    fprintf(f1, "%s %s %s %s %s %s %s %s \n",ref,type,hr,etage,valeur,jj,mm,aa);  // ajouter tous les lignes dans un fichier temp nomer ancien
}}
fclose(f);
fclose(f1);
remove("fichier.txt");
rename("ancien.txt","fichier.txt"); // changer le nom ancien par fichier.txt
printf("supprimer avec succes\n");
}




void modifier_capteur(char id[],capteur r){

char ref[30];
char type[30];
char hr[30];
char etage[30];
char valeur[30];
char jj[30];
char mm[30];
char aa[30];
FILE*f=NULL;
FILE*f1=NULL;

f=fopen("fichier.txt","r"); 
f1=fopen("ancien.txt","w+");

while(fscanf(f, "%s %s %s %s %s %s %s %s \n",ref,type,hr,etage,valeur,jj,mm,aa)!=EOF){ //end of file (EOF)
if(strcmp(id,ref)==0){
fprintf(f1, "%s %s %s %s %d %s %s %s \n",ref,r.type,r.heure,etage,r.valeur,jj,mm,aa);
}
else
{
fprintf(f1, "%s %s %s %s %s %s %s %s \n",ref,type,hr,etage,valeur,jj,mm,aa);
}

}
fclose(f);
fclose(f1);
remove("fichier.txt");
rename("ancien.txt","fichier.txt");
printf("modifier avec succes \n");
}






void afficher_alarment(GtkWidget *liste,char typee[],int min,int max )

{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("REF",renderer,"text",EREF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("TYPE",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("HEURE",renderer,"text",EHR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ETAGE",renderer,"text",EETAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("VALEUR",renderer,"text",EVALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",EDATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("fichier.txt","r");

char ref[30];
char type[30];
char hr[30];
char etage[30];
int valeur;
char jj[30];
char mm[30];
char aa[30];
char y[30]="";
char a[30];

{
f=fopen("fichier.txt","a+");
	while(fscanf(f, "%s %s %s %s %d %s %s %s \n",ref,type,hr,etage,&valeur,jj,mm,aa)!=EOF)
	{if (strcmp(type,typee)==0){
		if (valeur > max || valeur < min ){
sprintf(a,"%d",valeur);
strcpy(y,"");
	strcat(y,jj);strcat(y,"-");strcat(y,mm);strcat(y,"-");strcat(y,aa);
gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter,EREF,ref,ETYPE,type,EHR,hr,EETAGE,etage,EVALEUR,a,EDATE,y,-1);
	}}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

// calcluer les capteurs dans chaque etage lorsque on appuie sur calcluer va faire la somme qui afficher fichier.txt//
int stat (int niv)
{int s=0;
char ref[30];
char type[30];
char hr[30];
int etage;
int valeur;
char jj[30];
char mm[30];
char aa[30];
char y[30]="";
char a[30];
FILE*f=NULL;
FILE*f1=NULL;


f=fopen("fichier.txt","r");
while(fscanf(f, "%s %s %s %d %d %s %s %s \n",ref,type,hr,&etage,&valeur,jj,mm,aa)!=EOF){
if(niv==etage){
s=s+1;
}


}

return s;  //lorsque on appuie sur calculer il va donner s //
}
