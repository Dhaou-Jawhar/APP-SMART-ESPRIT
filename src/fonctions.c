#include "fonctions.h"

enum
{
	BHYIDENTIFIANT,
	BHYNOM,
	BHYTYPE,	
	BHYFOURNISSEUR,	
	BHYCOUT,
	BHYQUANTITE,
	BHYDATE,
	BHYSTOCK,
	BHYCOLUMNS
};


void bhyajouter (char fname[], information inf)
{
    FILE *f,*fw;
    f=fopen(fname,"a+");
    fw=fopen("liste_ajouter.txt","a+");
    fprintf(f,"%s %s %s %s %s %s %s\n",inf.bhyidentifiant,inf.bhynom,inf.bhytype,inf.bhyfournisseur,inf.bhycout,inf.bhyquantite,inf.bhydate);
    

int etas;
    etas= bhystock("liste_produit.txt",inf.bhyquantite);
	if(etas==2)
	strcpy(inf.bhystock,"en_stock");
	else if (etas==1)
	strcpy(inf.bhystock,"alert_de_repture");
	else if(etas==0)
	strcpy(inf.bhystock,"en_rupture_stock");
    f=fopen(fname,"a+");
    fprintf(fw,"%s %s %s %s %s %s %s %s\n",inf.bhyidentifiant,inf.bhynom,inf.bhytype,inf.bhyfournisseur,inf.bhycout,inf.bhyquantite,inf.bhydate,inf.bhystock);
    fclose(f);

fclose(fw);
}


void bhyAfficher(char fname [],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",BHYIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",BHYNOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",BHYTYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("fournisseur",renderer,"text",BHYFOURNISSEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("cout",renderer,"text",BHYCOUT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",BHYQUANTITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",BHYDATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("stock",renderer,"text",BHYSTOCK,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(BHYCOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(fname,"r");
if (f==NULL)
{
return;
}
else
{f=fopen(fname,"a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock)!=EOF)
{
gtk_list_store_append(store,&iter);	 		     gtk_list_store_set(store,&iter,BHYIDENTIFIANT,identifiant,BHYNOM,nom,BHYTYPE,type,BHYFOURNISSEUR,fournisseur,BHYCOUT,cout,BHYQUANTITE,quantite,BHYDATE,date,BHYSTOCK,stock,-1); 
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}


void bhysupprimer ( char fname[] ,char bhyid [])
{
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];

FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock)!=EOF)
{
if(strcmp(identifiant,bhyid)!=0)
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock);
}
}
fclose(f);
fclose(fw);
remove("liste_ajouter.txt");
rename("dump.txt","liste_ajouter.txt");
}

void bhymodifier (char fname [],char bhyid [],information info)
{
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];
FILE *f,*fw;
f=fopen(fname,"r");
fw=fopen("dump.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock)!=EOF)
{
if(strcmp(identifiant,bhyid)!=0)
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock);
}
else
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,info.bhynom,info.bhytype,info.bhyfournisseur,info.bhycout,info.bhyquantite,info.bhydate,info.bhystock);
}
}
fclose(f);
fclose(fw);
remove("liste_ajouter.txt");
rename("dump.txt","liste_ajouter.txt");

}



void bhyrecherche (char fname [],char bhyid [])
{
FILE *f, *fw;
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];

f=fopen(fname,"r");
fw=fopen("liste_recherchee.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock )!=EOF)
{
if((strcmp(identifiant,bhyid))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock);
}
fclose(f);
fclose(fw);
}


void recherche_stock (char fname [],char st [])
{
FILE *f, *fw;
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];

f=fopen(fname,"r");
fw=fopen("liste_recherchee_stock.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock )!=EOF)
{
if((strcmp(stock,st))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock);
}
fclose(f);
fclose(fw);
}




int bhystock (char fname[], char bhyquantite[])
{ 
 int quant;
 int etat;

quant =atoi(bhyquantite);
if(quant >50)
etat=2;
else if ((quant<50)&&(quant>10))
etat=1;
else if (quant<10)
etat=0;

return (etat);
}


void pos_car(char T[], char c, int *p_occ, int *d_occ)
{

int i;
    for(i=0;i<strlen(T);i++)
    {
        if (T[i]==c)
        {
            if (*p_occ==-1)
            {
                *p_occ=i;

            }
            else
            {
                *d_occ=i;
            }

        }

    }

}


int is_unique(char fname[], char id [])
{
FILE *f;
int x=1;
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];


f=fopen(fname,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock)!=EOF)
{
if((strcmp(identifiant,id))==0) x=-1;
}
return x;
}








