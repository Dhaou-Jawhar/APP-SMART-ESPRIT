#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"
#define MAX 256

/**------------[Treeview COLUMNS]----------------**/
enum
{
	DJCIN,
	DJPRENOM,
	DJNOM,
	DJUSERNAME,
	DJPASSWORD,
	DJROLE,
	DJDATE,
	DJID,
	COLUMNS,
};




/**-----------------[Ajouter User]----------------**/
void ajouter_user(char fname[], personne p, int c)
{

FILE *f,*fw;
f=fopen(fname,"a+");
fw=fopen("users.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %d\n",p.cin,p.prenom,p.nom,p.username,p.password,p.role,p.date,c);
fclose(f);
fclose(fw);
}
}
/**-----------------[Ajouter Etudiant]----------------**/
void ajouter_Niveau(personne p)
{
FILE *f;
f=fopen("niv.txt","a+");
if (f!=NULL)
{
fprintf(f,"%d\n",p.niv);
fclose(f);
}
}
/**-----------------[Choix]----------------**/
int choix(personne p)
{
if (strcmp(p.role,"Admin")==0)
return 1;
if (strcmp(p.role,"Etudiant")==0)
return 2;
if (strcmp(p.role,"Technicien")==0)
return 3;
if (strcmp(p.role,"Nutritionniste")==0)
return 4;
if (strcmp(p.role,"Gest_foyer")==0)
return 5;
if (strcmp(p.role,"Gest_resto")==0)
return 6;
}

/**---------------[Verif comptes Windows]----------------**/

int verif(char username[], char password[])
{
int Role_id;
char ch1[30], ch2[20], cin[100], prenom[100], nom[100], date[100], role[100];
FILE*f;
f=fopen("users.txt","r"); 
if(f!=NULL) 
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %d\n",cin,prenom,nom,ch1,ch2,role,date,&Role_id)!=EOF)
		{
			if (strcmp(username,ch1)==0)
			{
				if(strcmp(password,ch2)==0)
					{
					fclose(f);
					return(Role_id);}
			}
		}
		fclose(f);
		return(-1);
	}
	return(-1);
}
/**------------------[Verif compte Validation]------------------------**/
int verification(char log[], char Pw[])
{
    /** Déclarer Le fichier **/
    int trouve=-1; // declaration de l'entier trouve
    FILE *f=NULL;
    int Role_id;
    char ch11[20];
    char ch22[20], cin[100], prenom[100], nom[100], date[100], role[100];
    /** Ouvrire Le fichier **/
    f=fopen("users.txt","r");
    if(f!=NULL)
    /** parcourire le fichier pour la recharche et la vérification l'existance **/
    /** Lire ch1 et ch2**/
    /**EOF = End Of File = wsel l e5er el fichier**/
    {
       while(fscanf(f,"%s %s %s %s %s %s %s %d\n",cin,prenom,nom,ch11,ch22,role,date,&Role_id)!=EOF)
    {
    /**comparer ch1=log & ch2=Pw **/  
    if((strcmp(ch11,log)==0)&&(strcmp(ch22,Pw)==0))
    trouve=1; //ch1=log & ch2=Pw 
    }
fclose(f);
}
return (trouve);
}
/**-----------------[Affichage Treeview]----------------**/
void afficher_user(char fname [],GtkWidget *liste)
{
	

personne p;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

char prenom[50];
char nom[50];
char username[50];
char password[50];
char role[50];
char cin[50];
char date[100];
char id[10];
	

	store=NULL;


	FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",DJCIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",DJPRENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",DJNOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("date", renderer, "text",DJDATE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("username", renderer, "text",DJUSERNAME,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("password", renderer, "text",DJPASSWORD,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("role", renderer, "text",DJROLE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("id", renderer, "text",DJID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	store=gtk_list_store_new (COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(fname,"r");
	if(f==NULL)
	{
	return;
	}
	else
	{
		f = fopen(fname,"a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,prenom,nom,username,password,role,date,id)!=EOF)

		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,DJCIN,cin,DJPRENOM,prenom,DJNOM,nom,DJUSERNAME,username,DJPASSWORD,password,DJROLE,role,DJDATE,date,DJID,id, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref(store);
}
}
}
/**------------------[Supprimer]--------------------**/
void supprimer_user( char fname[] ,char e [])
{


personne p;
	char cin[100];
	char nom[30];
	char prenom[30];
	char username[30];
	char password[30];
	char role[30];
	char date[100];
	char id[10];


FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,prenom,nom,username,password,role,date,id)!=EOF)
{
if(strcmp(cin,e)!=0)
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,prenom,nom,username,password,role,date,id);
}
}
fclose(f);
fclose(fw);
remove("users.txt");
rename("dump.txt","users.txt");
}
/**-------------[Search To PRINT]---------------**/
int recherche(char nom_cin[])
{
	char cin[30];
	char nom[30];
	char prenom[30];
	char username[30];
	char password[30];
	char role[30];
	char date[100];
	char id[10];
	int ligne=0;
FILE*f;
f=fopen("users.txt","r"); 
if(f!=NULL) 
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,prenom,nom,username,password,role,date,id)!=EOF)
		{
                        ligne++;
			if(strcmp(nom_cin,nom)==0)
			{
                        fclose(f);
			return(ligne);
			}
			if(strcmp(nom_cin,cin)==0)
			{
			fclose(f);
			return(ligne);
			}
		}
		fclose(f);
		return(-1);
	}
	return(-1);
}
/**-------------[PRINT INFOS]-----------------**/

void modif(int a,char cin[30],char nom[20],char prenom[20],char username[20],char password[10],char date[100],char role[30],char id[10])
{


    FILE *f;
    f=fopen("users.txt", "r");
    int line=0;
    while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,prenom,nom,username,password,role,date,id)!=EOF)
{
        line++;
        if(line == a) break;
}
fclose(f);
}

/**------------------[Modifier]--------------------**/

void modifier_user (char fname [],char e [],personne p,char id[])
{
	char cin[30];
	char nom[30];
	char prenom[30];
	char username[30];
	char password[30];
	char role[30];
	char date[100];

FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,prenom,nom,username,password,role,date,id)!=EOF)
{
if(strcmp(cin,e)!=0)
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,prenom,nom,username,password,role,date,id);
}
else
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",p.cin,p.prenom,p.nom,p.username,p.password,p.role,p.date,id);
}
}
fclose(f);
fclose(fw);
remove("users.txt");
rename("dump.txt","users.txt");
}
/////////////////////////////////////////////////////////////////////////
/**------------------[Modifier Niveau Etudiant]--------------------**/
/**
void modifier_niveau (char fname[], int n, personne p)
{

FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%d\n",niv)!=EOF)
{
if(strcmp(niv,n)!=0)
{
fprintf(fw,"%d\n",niv);
}
else
{
fprintf(fw,"%d\n",p.niv);
}
}
fclose(f);
fclose(fw);
remove("niv.txt");
rename("dump.txt","niv.txt");
}
**/


