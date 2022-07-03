#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"
#include "fonctions.h"


/**------------------[Login]------------------**/
void
on_login_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *username, *password,*w_admin, *w_login, *msg1, *msg2, *msg3;


    char user[50];
    char pasw[50];
    int a;
    int trouve;

    username = lookup_widget (objet, "entry_log");
    password = lookup_widget (objet, "entry_pw");

    strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
    strcpy(pasw,gtk_entry_get_text(GTK_ENTRY(password)));
    a=verif(user,pasw);
    trouve=verification(user,pasw);

/*-------------------------------------------------*/
int o;

msg1 = lookup_widget (objet, "user_erreur");
msg2 = lookup_widget (objet, "pw_erreur");
msg3 = lookup_widget (objet, "champs_vide");
if (strcmp (user,"")==0)
{o=1;
gtk_widget_show(msg1);
gtk_widget_show(msg3);
}
else
{o=0;
gtk_widget_hide(msg1);
gtk_widget_hide(msg3);
}
if (strcmp (pasw,"")==0)
{o=1;
gtk_widget_show(msg2);
gtk_widget_show(msg3);
}
else
{o=0;
gtk_widget_hide(msg2);
gtk_widget_hide(msg3);
}


/*---------------------------------------------------*/
if(trouve==1)
{
/**--------------[Cases Users path]--------------------**/
switch (a)
{
case 1:
{
GtkWidget *gestion_user, *w_login;
w_login=lookup_widget(objet,"w_login");
gestion_user=lookup_widget(objet,"gestion_user");
gestion_user=create_gestion_user();
gtk_widget_destroy(w_login); 
gtk_widget_show (gestion_user);
break;
}
case 2:
{
GtkWidget *w_etud, *w_login;
w_login=lookup_widget(objet,"w_login");
w_etud=lookup_widget(objet,"w_etud");
w_etud=create_w_etud();
//gtk_widget_destroy(w_login); 
gtk_widget_show (w_etud);
break;
}
case 3:
{
GtkWidget *w_tech, *w_login;
w_login=lookup_widget(objet,"w_login");
w_tech=lookup_widget(objet,"w_tech");
w_tech=create_afficher_cap();
gtk_widget_destroy(w_login); 
gtk_widget_show (w_tech);
break;
}
case 4:
{
GtkWidget *w_nutr, *window1;
w_login=lookup_widget(objet,"w_login");
w_nutr=lookup_widget(objet,"w_nutr");
w_nutr=create_w_nutr();
//gtk_widget_destroy(w_login); 
gtk_widget_show (w_nutr);
break;
}
case 5:
{
GtkWidget *w_foyer, *w_login;
w_login=lookup_widget(objet,"w_login");
w_foyer=lookup_widget(objet,"w_foyer");
w_foyer=create_w_foyer();
//gtk_widget_destroy(w_login); 
gtk_widget_show (w_foyer);
break;
}
case 6:
{
GtkWidget *gerer_le_stock, *w_login;
w_login=lookup_widget(objet,"w_login");
gerer_le_stock=lookup_widget(objet,"gerer_le_stock");
gerer_le_stock=create_gerer_le_stock();
//gtk_widget_destroy(w_login); 
gtk_widget_show (gerer_le_stock);
break;
}
default:
{
GtkWidget *not_found;
not_found = create_not_found ();
gtk_widget_show (not_found);
}
}
}
else 
{
GtkWidget *not_found;
not_found = create_not_found ();
gtk_widget_show (not_found);
}
}

/**---------------------[Go From Login -> Inscription]--------------------**/
void
on_inscription_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *w_login, *inscription;

w_login=lookup_widget(objet,"w_login");

gtk_widget_destroy(w_login);
inscription=create_inscription();
gtk_widget_show(inscription);
}

/**---------------------[Back from Inscription -> Login]--------------------**/
void
on_insc_retour_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *w_login, *inscription;

inscription=lookup_widget(objet,"inscription");

gtk_widget_destroy(inscription);
w_login=create_w_login();
gtk_widget_show(w_login);
}

/**-----------[INSCRIPTION]-----------**/
void
on_inscri_ok_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne p;
int c;

char sj [100];
char sm [100];
char sa [100];
char dt [100];
int j;
int m;
int n;

GtkWidget *input_nom, *input_prenom, *input_username, *input_password, *input_CIN, *input_jour, *input_mois, *input_annee, *input_role;
GtkWidget *inscription;
inscription=lookup_widget(objet,"inscription");
input_nom=lookup_widget(objet,"ins_nom");
input_prenom=lookup_widget(objet,"ins_prenom");
input_username=lookup_widget(objet,"ins_username");
input_password=lookup_widget(objet,"ins_password");
input_CIN=lookup_widget(objet,"ins_cin");
input_role=lookup_widget(objet,"ins_role");

strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input_CIN)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(input_username)));
strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(input_password)));

/*--------------------[Date Entry]-------------------------*/

input_jour=lookup_widget(objet,"ins_spin_jour");
input_mois=lookup_widget(objet,"ins_spin_mois");
input_annee=lookup_widget(objet,"ins_spin_annee");


j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_mois));
n=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_annee));

sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",n);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dt,sj);
/*--------------------------------------------------------------*/
strcpy(p.date,dt);

if (strcmp(strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Etudiant")==0)
{
GtkWidget *etud_niv, *inscription;

inscription=lookup_widget(objet,"inscription");

etud_niv=create_etud_niv();
gtk_widget_show(etud_niv);
c = choix(p);
}
else
{
GtkWidget *insc_succe;
insc_succe = create_insc_succe ();
gtk_widget_show (insc_succe);
}
if (strcmp(strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Admin")==0)
{
c = choix(p);
ajouter_user("users.txt",p,c);
}
if (strcmp(strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Technicien")==0)
{
c = choix(p);
ajouter_user("users.txt",p,c);
}
if (strcmp(strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Nutritionniste")==0)
{
c = choix(p);
ajouter_user("users.txt",p,c);
}
if (strcmp(strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Gest_foyer")==0)
{
c = choix(p);
ajouter_user("users.txt",p,c);
}
if (strcmp(strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Etudiant")==0)
{
c = choix(p);
ajouter_user("users.txt",p,c);
}
}
/**-----------[NIVEAU ETUDIANT]-----------**/
void
on_valid_niv_etud_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
int c;
personne p;

GtkWidget *input_niv;
GtkWidget *etud_niv;

etud_niv=lookup_widget(objet,"etude_niv");

input_niv=lookup_widget(objet,"spin_niv_etud");

p.niv=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_niv));

ajouter_Niveau(p);

GtkWidget *insc_succe;
insc_succe = create_insc_succe ();
gtk_widget_show (insc_succe);
}

/**-----------[Treeview]-----------**/
personne p;
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* cin;
	gchar* prenom;
	gchar* nom;
	gchar* username;
	gchar* password;
	gchar* role;
	gchar* date;
	gchar* id;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0, &cin,1, &prenom,2, &nom,3, &username,4, &password,5, &role,6, &date,7, &id, -1);
//copie des valeurs dans la variable P de type personne pour le passer  à la fonction de suppression
		strcpy(p.cin,cin);
		strcpy(p.prenom,prenom);
		strcpy(p.nom,nom);
		strcpy(p.username,username);
		strcpy(p.password,password);
		strcpy(p.role,role);
		strcpy(p.date,date);
		strcpy(id,id);
}
}

/**---------------[From DashBoard -> Add user]-------------------**/
void
on_gu_ajouter_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_user, *inscription;

gestion_user=lookup_widget(objet,"gestion_user");

//gtk_widget_destroy(inscription);
inscription=create_inscription();
gtk_widget_show(inscription);
}

/**---------------[From DashBoard -> Search + Edit]-------------------**/
void
on_gu_recherche_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *gestion_user, *modifier_user;
gestion_user=lookup_widget(objet,"gestion_user");

//gtk_widget_destroy(w_login);
modifier_user=create_modifier_user();
gtk_widget_show(modifier_user);
}

/**---------------[From DashBoard -> Students Levels]-------------------**/
void
on_gu_niv_etud_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_user, *niv_etud;

gestion_user=lookup_widget(objet,"gestion_user");

//gtk_widget_destroy(w_login);
niv_etud=create_niv_etud();
gtk_widget_show(niv_etud);
}

/**---------------[From DashBoard -> Login]-------------------**/
void
on_gu_retour_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *w_login, *gestion_user;

gestion_user=lookup_widget(objet,"gestion_user");

gtk_widget_destroy(gestion_user);
w_login=create_w_login();
gtk_widget_show(w_login);
}

/**-----------------[Actualiser]------------------------**/
void
on_gu_F5_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_user;
GtkWidget *treeview1;
gestion_user = lookup_widget(objet,"gestion_user");
gtk_widget_destroy(gestion_user);
gestion_user=create_gestion_user ();
gtk_widget_show (gestion_user);
treeview1 = lookup_widget(gestion_user,"treeview1");
afficher_user("users.txt",treeview1);
}

/**-----------------[Search Button]------------------------**/
void
on_recherche_ok_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char cin[30];
	char nom[30];
	char prenom[30];
	char username[30];
	char password[30];
	char role[30];
	char date[100];
	char id[10];

GtkWidget	*input_cin	=	lookup_widget(objet,"entry_edit_cin");
GtkWidget	*input_nom	=	lookup_widget(objet,"entry_edit_nom");
GtkWidget	*input_prenom	=	lookup_widget(objet,"entry_edit_prenom");
GtkWidget	*input_username	=	lookup_widget(objet,"entry_edit_username");
GtkWidget	*input_password	=	lookup_widget(objet,"entry_edit_password");
GtkWidget	*input_role	=	lookup_widget(objet,"combo_edit_role");

char nom_cin[20];
GtkWidget	*input		=	lookup_widget(objet,"entry_rech");

strcpy(nom_cin,gtk_entry_get_text(GTK_ENTRY(input)));
int a=0;
a=recherche(nom_cin);
if (a==-1)
{
/*---------------------------------*/
GtkWidget *pInfo;
gtk_window_set_title(GTK_WINDOW(pInfo), "Information");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"User introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
/*-------------------------------------*/
}
else 
{
modif(a,cin,nom,prenom,username,password,date,role,id);
gtk_entry_set_text (GTK_ENTRY(input_cin),cin);
gtk_entry_set_text (GTK_ENTRY(input_nom),nom);
gtk_entry_set_text (GTK_ENTRY(input_prenom),prenom);
gtk_entry_set_text (GTK_ENTRY(input_username),username);
gtk_entry_set_text (GTK_ENTRY(input_password),password);
gtk_entry_set_text (GTK_COMBO_BOX(input_role),role);
}
}

/**-----------------[Edit Button]------------------------**/
void
on_modifier_ok_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
calander c;
personne p;
char nom_cin[20];

GtkWidget	* input_jour;
GtkWidget	* input_mois;
GtkWidget	* input_annee;
GtkWidget	* input_role;
GtkWidget	* calander_JOE;

GtkWidget	*input		=	lookup_widget(objet,"entry_rech");
GtkWidget	*input_cin	=	lookup_widget(objet,"entry_edit_cin");
GtkWidget	*input_nom	=	lookup_widget(objet,"entry_edit_nom");
GtkWidget	*input_prenom	=	lookup_widget(objet,"entry_edit_prenom");
GtkWidget	*input_username	=	lookup_widget(objet,"entry_edit_username");
GtkWidget	*input_password	=	lookup_widget(objet,"entry_edit_password");
input_role = lookup_widget(objet,"combo_edit_role");

/**---------------[Calander]-------------**/
int j;
int m;
int a;
char sj [100];
char sm [100];
char sa [100];
char date [100];
/**--**/
calander_JOE=lookup_widget(objet,"calendar_Jawhar");

gtk_calendar_get_date(GTK_CALENDAR(calander_JOE),
                          &c.a,
                          &c.m,
                          &c.j);  // copier le jour / mois / annee

c.m=c.m+1;
/*--*/
sprintf(sj,"%d",c.j); //changer l'entier jour a un char ( sj ) 
sprintf(sm,"%d",c.m);
sprintf(sa,"%d",c.a);
strcat(sj,"/");   //   jour/
strcat(sm,"/");   //   mois/
strcat(sm,sa);    //   mois/annee
strcat(sj,sm);    //   jours/mois/annee
strcpy(date,sj);  // copy to date 
/*--------------------------------------------------------------------*/
personne pr;
strcpy(pr.date,date);
strcpy(pr.cin,gtk_entry_get_text(GTK_ENTRY(input_cin)));
strcpy(pr.nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(pr.prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(pr.username,gtk_entry_get_text(GTK_ENTRY(input_username)));
strcpy(pr.password,gtk_entry_get_text(GTK_ENTRY(input_password)));
strcpy(pr.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role)));


strcpy(nom_cin,gtk_entry_get_text(GTK_ENTRY(input)));

if (strcmp(strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Etudiant")==0)
{
int c;
char ident[10];


///////////////////////////////////////////////////////////
/**--------[Choix Niveau]--------------
GtkWidget *edit_niv_etud;
edit_niv_etud=create_edit_niv_etud();
gtk_widget_show(edit_niv_etud);------**/
///////////////////////////////////////////////////////////



modifier_user ("users.txt",pr.cin,pr,ident);
}
else
{

/*------------------------[Modifier l'id avec le role]-----------------------------*/
int d;
char ident[10];

if (strcmp(strcpy(pr.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Admin")==0)
{
d==1;
sprintf(ident,"%d",d); //ident prend le num 1 en char
modifier_user ("users.txt",pr.cin,pr,ident); //ident = id dans la fonction pour changer l'id
}
if (strcmp(strcpy(pr.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Technicien")==0)
{
d==2;
sprintf(ident,"%d",d); //ident prend le num 2 en char
modifier_user ("users.txt",pr.cin,pr,ident); 
}
if (strcmp(strcpy(pr.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Nutritionniste")==0)
{
d==3;
sprintf(ident,"%d",d); //ident prend le num 3 en char
modifier_user ("users.txt",pr.cin,pr,ident);
}
if (strcmp(strcpy(pr.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input_role))),"Gest_foyer")==0)
{
d==4;
sprintf(ident,"%d",d); //ident prend le num 4 en char
modifier_user ("users.txt",pr.cin,pr,ident);
}
}
}

/**-----------------[Search Students Levels Button]------------------------**/
void
on_rech_niveau_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
char niveau[10];
int n1=0 , n2=0 , n3=0 , n4=0 , n5=0;
char niv1[20];
char niv2[20];
char niv3[20];
char niv4[20];
char niv5[20];

GtkWidget	*output1	=	lookup_widget(objet,"niv1");
GtkWidget	*output2	=	lookup_widget(objet,"niv2");
GtkWidget	*output3	=	lookup_widget(objet,"niv3");
GtkWidget	*output4	=	lookup_widget(objet,"niv4");
GtkWidget	*output5	=	lookup_widget(objet,"niv5");
//strcpy(niveau,gtk_entry_get_text(GTK_ENTRY(input)));

FILE*f;
f=fopen("niv.txt","r"); 
if(f!=NULL)

while (fscanf(f,"%s\n",niveau)!=EOF)
	{
           if (strcmp(niveau,"1") == 0)
	   n1++;
	   else if (strcmp(niveau,"2") == 0)
	   n2++;
	   else if (strcmp(niveau,"3") == 0)
	   n3++;
	   else if (strcmp(niveau,"4") == 0)
	   n4++;
	   else if (strcmp(niveau,"5") == 0)
	   n5++;
	}


sprintf(niv1 ,"%d", n1);
sprintf(niv2 ,"%d", n2);
sprintf(niv3 ,"%d", n3);
sprintf(niv4 ,"%d", n4);
sprintf(niv5 ,"%d", n5);

gtk_label_set_text(output1,niv1);
gtk_label_set_text(output2,niv2);
gtk_label_set_text(output3,niv3);
gtk_label_set_text(output4,niv4);
gtk_label_set_text(output5,niv5);
}

/**------------[Delete Button -> Confirmation window]------------------**/
void
on_supp_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *confirm_supp, *gestion_user;

gestion_user=lookup_widget(objet,"gestion_user");

confirm_supp=create_confirm_supp();
gtk_widget_show(confirm_supp);
}


int g[2];
/**-----------------[Check Box's]------------------------**/
void
on_check_supp_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[0]=1;
}


void
on_check_annul_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
g[1]=3;
}

/**-----------------[Delete Validation Button]------------------------**/
void
on_valid_supp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
if (g[0]==1)
{
supprimer_user("users.txt",p.cin);
GtkWidget *confirm_supp;
confirm_supp=lookup_widget(objet,"confirm_supp");
gtk_widget_destroy(confirm_supp);
}
if (g[1]==3)
{
GtkWidget *confirm_supp;
confirm_supp=lookup_widget(objet,"confirm_supp");
gtk_widget_destroy(confirm_supp);
}
}


///////////////////////////////////////////////////////////////////////////
/**-----------------[Edit Student Level]------------------------**/
void
on_edit_niv_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
personne pr;


GtkWidget *input_niv;
input_niv=lookup_widget(objet,"spin_niv_etud");

pr.niv=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input_niv));

//modifier_niveau ("niv.txt",pr.niv,pr);
}


void
on_color_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
/*---------------------------------------------------*/

  GtkWidget *name;
  GtkWidget *name1;
  GtkWidget *name2;
  GtkWidget *name3;
  GtkWidget *name4;
  GtkWidget *name5;
  GtkWidget *name6;

  GtkResponseType result;
  GtkColorSelection *colorsel;

  name = lookup_widget (objet, "label26");
  name1 = lookup_widget (objet, "label27");
  name2 = lookup_widget (objet, "label28");
  name3 = lookup_widget (objet, "label29");
  name4 = lookup_widget (objet, "label30");
  name5 = lookup_widget (objet, "label31");
  name6 = lookup_widget (objet, "label32");
  GtkWidget *dialog = gtk_color_selection_dialog_new("Font Color");

  result = gtk_dialog_run(GTK_DIALOG(dialog));

  if (result == GTK_RESPONSE_OK) {

    GdkColor color;

    colorsel = GTK_COLOR_SELECTION(
                   GTK_COLOR_SELECTION_DIALOG(dialog)->colorsel);
    gtk_color_selection_get_current_color(colorsel,
                                &color);

    gtk_widget_modify_fg(GTK_WIDGET(name),
                             GTK_STATE_NORMAL,
                             &color);
    gtk_widget_modify_fg(GTK_WIDGET(name1),
                             GTK_STATE_NORMAL,
                             &color);
    gtk_widget_modify_fg(GTK_WIDGET(name2),
                             GTK_STATE_NORMAL,
                             &color);
    gtk_widget_modify_fg(GTK_WIDGET(name3),
                             GTK_STATE_NORMAL,
                             &color);
    gtk_widget_modify_fg(GTK_WIDGET(name4),
                             GTK_STATE_NORMAL,
                             &color);
    gtk_widget_modify_fg(GTK_WIDGET(name5),
                             GTK_STATE_NORMAL,
                             &color);
    gtk_widget_modify_fg(GTK_WIDGET(name6),
                             GTK_STATE_NORMAL,
                             &color);
  } 

  gtk_widget_destroy(dialog);

/*---------------------------------------------------*/
}


void
on_copyright_user_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *copyright, *gestion_user;

gestion_user=lookup_widget(objet,"gestion_user");

copyright=create_copyright();
gtk_widget_show(copyright);
}


void
on_copyright_ok_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cpy1, *cpy2, *cpy3;

cpy1 = lookup_widget (objet, "copyright_msg1");
cpy2 = lookup_widget (objet, "copyright_msg2");
cpy3 = lookup_widget (objet, "copyright_logo");

gtk_widget_show(cpy2);
gtk_widget_show(cpy3);

/*-----------------------------------------*/
  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("Login.png", NULL);

  GtkWidget *dialog1 = gtk_about_dialog_new();
  gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog1), "SMART");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog1), "ESPRIT"); 
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog1),"(c) 3B7 engineering");
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog1), 
     "© Copyright 2021 Smart Esprit -PROJET-");
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog1), 
     "https://github.com/Dhaou-Jawhar/Smart_ESPRIT");
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog1),"Project Manager : Cherif Sami");
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog1), pixbuf);
  g_object_unref(pixbuf), pixbuf = NULL;
  gtk_dialog_run(GTK_DIALOG (dialog1));
  gtk_widget_destroy(dialog1);
/*---------------------------------------------*/
}


void
on_paint_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
/*---------------------------------------------------*/

  GtkWidget *name;
  GtkWidget *name1;
  GtkResponseType result;
  GtkColorSelection *colorsel;

  name = lookup_widget (objet, "copyright_msg1");
  name1 = lookup_widget (objet, "copyright_msg2");
  GtkWidget *dialog = gtk_color_selection_dialog_new("Font Color");

  result = gtk_dialog_run(GTK_DIALOG(dialog));

  if (result == GTK_RESPONSE_OK) {

    GdkColor color;

    colorsel = GTK_COLOR_SELECTION(
                   GTK_COLOR_SELECTION_DIALOG(dialog)->colorsel);
    gtk_color_selection_get_current_color(colorsel,
                                &color);

    gtk_widget_modify_fg(GTK_WIDGET(name),
                             GTK_STATE_NORMAL,
                             &color);
    gtk_widget_modify_fg(GTK_WIDGET(name1),
                             GTK_STATE_NORMAL,
                             &color);
  } 

  gtk_widget_destroy(dialog);

/*---------------------------------------------------*/
  GtkResponseType result1;
  GtkWidget *name2;
  GtkWidget *name3;
  
  name2 = lookup_widget (objet, "copyright_msg1");
  name3 = lookup_widget (objet, "copyright_msg2");

  GtkWidget *dialog1 = gtk_font_selection_dialog_new("Select Font");

  result1 = gtk_dialog_run(GTK_DIALOG(dialog1));

  if (result1 == GTK_RESPONSE_OK || result1 == GTK_RESPONSE_APPLY) {

     PangoFontDescription *font_desc;
     gchar *fontname = gtk_font_selection_dialog_get_font_name(
                            GTK_FONT_SELECTION_DIALOG(dialog1));

     font_desc = pango_font_description_from_string(fontname);

     gtk_widget_modify_font(GTK_WIDGET(name2), font_desc);
     gtk_widget_modify_font(GTK_WIDGET(name3), font_desc);

     g_free(fontname);
   }

  gtk_widget_destroy(dialog1);
}

/////////////////////////////////////////////////////////////////
/*-----------------[Majdi]----------------------*/

void
on_buttonbhyaffichera_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *bhy_afficher;
GtkWidget *treeview1bhy;
bhy_afficher=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_ajouter.txt",treeview1bhy);
}




void
on_buttonbhyAjouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input1;
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;

input1= lookup_widget(objet_graphique, "entrybhyidentifianta");
input2= lookup_widget(objet_graphique, "entrybhynoma");
input3= lookup_widget(objet_graphique, "comboboxentrybhytypea");
input4= lookup_widget(objet_graphique, "entrybhyfournisseura");
input5= lookup_widget(objet_graphique, "spinbuttonbhycouta");
input6= lookup_widget(objet_graphique, "entrybhyquantitea");
input7= lookup_widget(objet_graphique, "spinbuttonbhyjoura");
input8= lookup_widget(objet_graphique, "spinbuttonbhymoisa");
input9= lookup_widget(objet_graphique, "spinbuttonbhyanneea");

char i [100];
char n [100];
char t [100];
char f [100];
int c;
char q [100];
int j ;
int m;
int a;
char sc [100];
char sj [100];
char sm [100];
char sa [100];
char dn [100];
int unique;

strcpy(i,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(f,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(q,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(t,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));

c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
sprintf(sc,"%d",c);
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dn,sj);

information inf;
strcpy(inf.bhyidentifiant,i);
strcpy(inf.bhynom,n);
strcpy(inf.bhytype,t);
strcpy(inf.bhyfournisseur,f);
strcpy(inf.bhycout,sc);
strcpy(inf.bhyquantite,q);
strcpy(inf.bhydate,dn);

if((strlen(inf.bhyidentifiant)==0)||(strlen(inf.bhynom)==0)||(strlen(inf.bhyfournisseur)==0)||(strlen(inf.bhyquantite)==0))
{
GtkWidget *bhyerreur;
bhyerreur=create_bhyerreur();
gtk_widget_show(bhyerreur);
}
else
{
unique=is_unique("liste_ajouter.txt",inf.bhyidentifiant);
if((unique==-1))
{
GtkWidget *bhyerreur;
bhyerreur=create_bhyerreur();
gtk_widget_show(bhyerreur);
}
else
{
if((unique==1)&&(strlen(inf.bhyidentifiant)!=0)&&(strlen(inf.bhynom)!=0)&&(strlen(inf.bhyfournisseur)!=0)&&(strlen(inf.bhyquantite)!=0))
{
bhyajouter("liste_produit.txt",inf);

GtkWidget *input;
GtkWidget *bhysucc;
bhysucc=lookup_widget(objet_graphique,"bhysucc");
bhysucc=create_bhysucc();
gtk_widget_show(bhysucc);
}
}
}



/*
bhyajouter("liste_produit.txt",inf);

GtkWidget *input;
GtkWidget *bhysucc;
bhysucc=lookup_widget(objet_graphique,"bhysucc");
bhysucc=create_bhysucc();
gtk_widget_show(bhysucc);
*/
}

information i;
void
on_treeview1bhy_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *identifiant;
gchar *nom;
gchar *type;
gchar *fournisseur;
gchar *cout;
gchar *quantite;
gchar *date;
gchar *stock;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&identifiant,1,&nom,2,&type,3,&fournisseur,4,&cout,5,&quantite,6,&date,7,&stock,-1);
strcpy(i.bhyidentifiant,identifiant);
strcpy(i.bhynom,nom);
strcpy(i.bhytype,type);
strcpy(i.bhyfournisseur,fournisseur);
strcpy(i.bhycout,cout);
strcpy(i.bhyquantite,quantite);
strcpy(i.bhydate,date);
strcpy(i.bhystock,stock);
}
}

void
on_buttonbhyactualiser_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_ajouter.txt",treeview1bhy);
}


void
on_buttonbhyretour_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gerer_le_stock,*bhy_afficher;
bhy_afficher=lookup_widget(objet_graphique,"bhy_afficher");
gtk_widget_destroy(bhy_afficher);

gtk_widget_show(gerer_le_stock);
}


void
on_buttonbhyajouter_aff_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gerer_le_stock,*bhy_afficher;
bhy_afficher=lookup_widget(objet_graphique,"bhy_afficher");
gtk_widget_destroy(bhy_afficher);
gerer_le_stock=create_gerer_le_stock();
gtk_widget_show(gerer_le_stock);
}


void
on_buttonbhysupprimer_aff_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
/*-----------------------------------------------*/
GtkWidget *pInfo2;
pInfo2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer le produit?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo2)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo2);
        break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo2);
	break;
}
bhysupprimer("liste_ajouter.txt",i.bhyidentifiant);
}


void
on_buttonbhymodifier_aff_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *bhy_modifier;
bhy_modifier=lookup_widget(objet_graphique,"bhy_modifier");
bhy_modifier=create_bhy_modifier();
gtk_widget_show(bhy_modifier);

}


void
on_buttonbhyrechercher_aff_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input;
char c [100];
input= lookup_widget(objet_graphique, "entrybhyidentifiant_aff");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input)));
bhyrecherche("liste_ajouter.txt",c);
GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_recherchee.txt",treeview1bhy);
}

int choixbhy[10]={0,0,0};
void
on_checkbuttonen_stock_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixbhy[0]=1;
}


void
on_checkbuttonalert_rupture_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixbhy[1]=1;
}


void
on_checkbuttonrupture_stock_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixbhy[2]=1;
}


void
on_buttonrecherche_stock_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
if ((choixbhy[0]==0)&&(choixbhy[1]==0)&&(choixbhy[2]==1))
{ char c [100];
strcpy(c,"en_rupture_stock");
recherche_stock ("liste_ajouter.txt",c);
GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_recherchee_stock.txt",treeview1bhy);
choixbhy[0]=0;
choixbhy[1]=0;
choixbhy[2]=0;
}
else if ((choixbhy[0]==0)&&(choixbhy[1]==1)&&(choixbhy[2]==0))
{
char c [100];
strcpy(c,"alert_de_repture");
recherche_stock ("liste_ajouter.txt",c);
GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_recherchee_stock.txt",treeview1bhy);
choixbhy[0]=0;
choixbhy[1]=0;
choixbhy[2]=0;
}

else if ((choixbhy[0]==1)&&(choixbhy[1]==0)&&(choixbhy[2]==0))
{
char c [100];
strcpy(c,"en_stock");
recherche_stock ("liste_ajouter.txt",c);
GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_recherchee_stock.txt",treeview1bhy);
choixbhy[0]=0;
choixbhy[1]=0;
choixbhy[2]=0;
}
else if ((choixbhy[0]==1)&&(choixbhy[1]==1)&&(choixbhy[2]==1))
{
GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_ajouter.txt",treeview1bhy);
choixbhy[0]=0;
choixbhy[1]=0;
choixbhy[2]=0;
}

else if ((choixbhy[0]==0)&&(choixbhy[1]==1)&&(choixbhy[2]==1))
{

char c [100];
char cc [100];
strcpy(c,"en_rupture_stock");
strcpy(cc,"alert_de_repture");

FILE *f, *fw;
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];

f=fopen("liste_ajouter.txt","r");
fw=fopen("liste_recherchee_stock.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock)!=EOF)
{
if((strcmp(stock,c)==0)||(strcmp(stock,cc)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock);
}
fclose(f);
fclose(fw);

GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_recherchee_stock.txt",treeview1bhy);
choixbhy[0]=0;
choixbhy[1]=0;
choixbhy[2]=0;
}
else if ((choixbhy[0]==1)&&(choixbhy[1]==0)&&(choixbhy[2]==1))
{

char c [100];
char cc [100];
strcpy(c,"en_stock");
strcpy(cc,"en_rupture_stock");

FILE *f, *fw;
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];

f=fopen("liste_ajouter.txt","r");
fw=fopen("liste_recherchee_stock.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock)!=EOF)
{
if((strcmp(stock,c)==0)||(strcmp(stock,cc)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock);
}
fclose(f);
fclose(fw);

GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_recherchee_stock.txt",treeview1bhy);
choixbhy[0]=0;
choixbhy[1]=0;
choixbhy[2]=0;
}

else if ((choixbhy[0]==1)&&(choixbhy[1]==1)&&(choixbhy[2]==0))
{

char c [100];
char cc [100];
strcpy(c,"en_stock");
strcpy(cc,"alert_de_repture");

FILE *f, *fw;
 char identifiant [100];
 char nom [100] ;
 char type [100];
 char fournisseur [100];
 char cout [100];
 char quantite [100];
 char date [100];
 char stock [100];

f=fopen("liste_ajouter.txt","r");
fw=fopen("liste_recherchee_stock.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock)!=EOF)
{
if((strcmp(stock,c)==0)||(strcmp(stock,cc)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",identifiant,nom,type,fournisseur,cout,quantite,date,stock);
}
fclose(f);
fclose(fw);

GtkWidget *bhy_afficher,*w1;
GtkWidget *treeview1bhy;
w1=lookup_widget(objet_graphique,"bhy_afficher");
bhy_afficher=create_bhy_afficher();
gtk_widget_show(bhy_afficher);
gtk_widget_hide(w1);
treeview1bhy=lookup_widget(bhy_afficher,"treeview1bhy");
bhyAfficher("liste_recherchee_stock.txt",treeview1bhy);
choixbhy[0]=0;
choixbhy[1]=0;
choixbhy[2]=0;
}
}

void
on_entrybhyidentifiantm_grab_focus     (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* widget1;
GtkWidget* widget2;
GtkWidget* widget3;
GtkWidget* widget4;
GtkWidget* widget5;
GtkWidget* widget6;
GtkWidget* widget7;
GtkWidget* widget8;
GtkWidget* widget9;
GtkWidget* widgets;
GtkWidget* widgeta;
GtkWidget* widgetr;

widget1=lookup_widget(widget, "entrybhyidentifiantm");
gtk_entry_set_text(GTK_ENTRY(widget1),i.bhyidentifiant);
widget2=lookup_widget(widget, "entrybhynomm");
gtk_entry_set_text(GTK_ENTRY(widget2),i.bhynom);
widget3= lookup_widget(widget, "comboboxentrybhytypem");
int b=0;
if(strcmp(i.bhytype,"produit1")==0)
b=0;
if(strcmp(i.bhytype,"produit2")==0)
b=1;
if(strcmp(i.bhytype,"produit3")==0)
b=2;
gtk_combo_box_set_active(GTK_COMBO_BOX(widget3),b);
widget4=lookup_widget(widget, "entrybhyfournisseurm");
gtk_entry_set_text(GTK_ENTRY(widget4),i.bhyfournisseur);
widget5=lookup_widget(widget, "entrybhyquantitem");
gtk_entry_set_text(GTK_ENTRY(widget5),i.bhyquantite);

widgets=lookup_widget(widget, "radiobuttonstockm");
widgeta=lookup_widget(widget, "radiobuttonalert");
widgetr=lookup_widget(widget, "radiobuttonrupture");
if(strcmp(i.bhystock,"en_stock")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgets),TRUE);
if(strcmp(i.bhystock,"alert_de_repture")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgeta),TRUE);
if(strcmp(i.bhystock,"en_rupture_stock")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgetr),TRUE);

widget6=lookup_widget(widget, "spinbuttonbhycout");
int o;
o=atoi(i.bhycout);
gtk_spin_button_set_value(widget6,o);

int p_occ=-1,d_occ=0;
pos_car(i.bhydate,'/',&p_occ,&d_occ);
int z;
char j [3];
for(z=0;z<p_occ;z++) j[z]=i.bhydate[z];
j[p_occ]='\0';
int zj=0;
zj=atoi(j);
widget7=lookup_widget(widget, "spinbuttonbhyjourm");
gtk_spin_button_set_value(widget7,zj);
char m [3];
for(z=p_occ+1;z<d_occ;z++) m[z-p_occ-1]=i.bhydate[z];
m[d_occ-p_occ-1]='\0';
int zm=0;
zm=atoi(m);
widget8=lookup_widget(widget, "spinbuttonbhymoism");
gtk_spin_button_set_value(widget8,zm);
char a [5];
for(z=d_occ+1;z<strlen(i.bhydate);z++) a[z-d_occ-1]=i.bhydate[z];
a[strlen(i.bhydate)-d_occ-1]='\0';
int za=0;
za=atoi(a);
widget9=lookup_widget(widget, "spinbuttonbhyanneem");
gtk_spin_button_set_value(widget9,za);



}

int e=1;
void
on_radiobuttonstockm_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) e=0;
}


void
on_radiobuttonalert_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) e=1;
}


void
on_radiobuttonrupture_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) e=2;
}


void
on_buttonbhymodifier_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;


input2= lookup_widget(objet_graphique, "entrybhynomm");
input3= lookup_widget(objet_graphique, "comboboxentrybhytypem");
input4= lookup_widget(objet_graphique, "entrybhyfournisseurm");
input5= lookup_widget(objet_graphique, "spinbuttonbhycout");
input6= lookup_widget(objet_graphique, "entrybhyquantitem");
input7= lookup_widget(objet_graphique, "spinbuttonbhyjourm");
input8= lookup_widget(objet_graphique, "spinbuttonbhymoism");
input9= lookup_widget(objet_graphique, "spinbuttonbhyanneem");


char n [100];
char t [100];
char f [100];
int c;
char q [100];
int j ;
int m;
int a;
char sc [100];
char sj [100];
char sm [100];
char sa [100];
char dn [100];
char s [100];

if (e==0) strcpy(s,"en_stock");
else if(e==1) 
strcpy(s,"alert_de_repture");
else strcpy(s,"en_rupture_stock");

strcpy(n,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(f,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(q,gtk_entry_get_text(GTK_ENTRY(input6)));

strcpy(t,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));

c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
sprintf(sc,"%d",c);
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dn,sj);

information infoo;
strcpy(infoo.bhyidentifiant,i.bhyidentifiant);
strcpy(infoo.bhynom,n);
strcpy(infoo.bhytype,t);
strcpy(infoo.bhyfournisseur,f);
strcpy(infoo.bhycout,sc);
strcpy(infoo.bhyquantite,q);
strcpy(infoo.bhydate,dn);
strcpy(infoo.bhystock,s);

bhymodifier("liste_ajouter.txt",i.bhyidentifiant,infoo);
}


void
on_buttonbhyretour_succ_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gerer_le_stock,*bhysucc;
bhysucc=lookup_widget(objet_graphique,"bhysucc");
gtk_widget_destroy(bhysucc);

gtk_widget_show(gerer_le_stock);
}


void
on_buttonbhymodretour_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *bhy_modifier,*bhy_afficher;
bhy_modifier=lookup_widget(objet_graphique,"bhy_modifier");
gtk_widget_destroy(bhy_modifier);

gtk_widget_show(bhy_afficher);
}


void
on_buttonbhyerreur_retour_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gerer_le_stock,*bhyerreur;
bhyerreur=lookup_widget(objet_graphique,"bhyerreur");
gtk_widget_destroy(bhyerreur);

gtk_widget_show(gerer_le_stock);
}
///////////////////////////////////////////////////////////////////////////////




#include "capteur.c"

char refff[20];
char typee[20]="temperature";
int cnf;
int cnf1;

/*----------------[Ajouter]-------------------------*/
void
on_buttonOk_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
capteur c;

GtkWidget *entryreference ,*entryType ,*entryheure ,*etage  ,*valeur;
GtkWidget *fenetre_ajouter;
fenetre_ajouter=lookup_widget(button,"ajouter_cap");

GtkWidget *date;
date = lookup_widget (button ,"calendar1_cap");
entryreference=lookup_widget(button,"ref_cap");
entryType=lookup_widget(button,"comboboxentry1_cap");
entryheure=lookup_widget(button,"heure_cap");

etage=lookup_widget(button,"spinbutton1_cap");
valeur=lookup_widget(button,"spinbutton2_cap");

GtkWidget *e_re_cap,*e_type_cap,*e_hr_cap,*e_conf_cap;


int o=0;

e_re_cap=lookup_widget(button,"e_ref_cap");
e_type_cap=lookup_widget(button,"e_type_cap");
e_hr_cap=lookup_widget(button,"e_hr_cap");
e_conf_cap=lookup_widget(button,"e_cnf_cap");



 strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(entryreference) ) );
 strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryType)));
 strcpy(c.heure,gtk_entry_get_text(GTK_ENTRY(entryheure) ) );

 c.etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(etage));
 c.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur));

gtk_calendar_get_date (GTK_CALENDAR(date),
                       &c.dt.annee,
                       &c.dt.mois,
                       &c.dt.jour);
c.dt.mois=c.dt.mois+1;

if (strcmp(c.reference,"")==0)
{o=1;
gtk_widget_show(e_re_cap);
}
else 
{o=0;
gtk_widget_hide(e_re_cap);
}

if (strcmp(c.type,"")==0)
{o=1;
gtk_widget_show(e_type_cap);
}
else 
{o=0;
gtk_widget_hide(e_type_cap);
}

if (strcmp(c.heure,"")==0)
{o=1;
gtk_widget_show(e_hr_cap);
}
else 
{o=0;
gtk_widget_hide(e_hr_cap);
}

if (cnf==0)
{
gtk_widget_show(e_conf_cap);
}
else 
{
gtk_widget_hide(e_conf_cap);
}


if (o==0 && cnf==1){

ajouter_capteur(c);
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"ajouter_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_afficher_cap ();
  gtk_widget_show (afficher_cap);
cnf=0;
}
}
/*-----------------[Annuler Ajouter]----------------------*/
void
on_buttonAnnuler_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"ajouter_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_afficher_cap ();
  gtk_widget_show (afficher_cap);
}

/*---------------------[Treeview]------------------------*/
void
on_aff_cap1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_cap;
GtkWidget *afficher_cap;
afficher_cap=lookup_widget(button,"afficher_cap");
treeview1_cap=lookup_widget(afficher_cap,"treeview1_cap");
afficher_capteur(treeview1_cap);
}

/*-----------------------------[de treeview -> Ajouter]---------------*/
void
on_aj_cap1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_cap;
afficher_cap=lookup_widget(button,"afficher_cap");
gtk_widget_destroy(afficher_cap);
GtkWidget *ajouter_cap;
ajouter_cap = create_ajouter_cap ();
  gtk_widget_show (ajouter_cap);

}

/*-----------------------[Modification]----------------------*/
void
on_md_cap_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_cap;
afficher_cap=lookup_widget(button,"afficher_cap");
gtk_widget_destroy(afficher_cap);
GtkWidget *modifeir_cap;
modifeir_cap = create_modifier_cap ();
  gtk_widget_show (modifeir_cap);


char ref[30];
char type[30];
char hr[30];
char etage[30];
char valeur[30];
char jj[30];
char mm[30];
char aa[30];
char y[30]="";

FILE *f;

f=fopen("fichier.txt","r");







while(fscanf(f, "%s %s %s %s %s %s %s %s \n",ref,type,hr,etage,valeur,jj,mm,aa)!=EOF){
 if (strcmp(refff,ref)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(modifeir_cap,"heure_cap1")),hr);
                
        

}}

}

/*---------------------[Supprimer]---------------------*/
void
on_spp_cap1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_cap;
afficher_cap=lookup_widget(button,"afficher_cap");

GtkWidget *supprimer_cap;
supprimer_cap = create_supprimer_cap ();
  gtk_widget_show (supprimer_cap);
}

/*--------------------[Recherche]---------------------*/
void
on_rech_cap1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_cap;
GtkWidget *afficher_cap;
afficher_cap=lookup_widget(button,"afficher_cap");

treeview1_cap=lookup_widget(afficher_cap,"treeview1_cap");
cherch = lookup_widget (button ,"entre_rech_cap");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_capteur(treeview1_cap,ch);
}

/*----------------------[Annuler supp]-----------------------*/
void
on_ann_suup__cap_activate              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"supprimer_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;

  gtk_widget_show (afficher_cap);

}

/*--------------------[Confirmation supp]------------------------*/
void
on_cnf_spp_cap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_capteur(refff);
GtkWidget *supprimer_cap;
supprimer_cap=lookup_widget(button,"supprimer_cap");
gtk_widget_destroy(supprimer_cap);
GtkWidget *afficher_cap;

  gtk_widget_show (afficher_cap);
}

/*-------------------------[Annuler modification]-------------------*/
void
on_ann_md5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"modifier_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_afficher_cap ();
  gtk_widget_show (afficher_cap);

}

/*----------------[Treeview + select par type / ref / etage  + modification page]-------------------*/
void
on_moddd_cap_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
capteur c;

GtkWidget *entryreference ,*entryType ,*entryheure ,*etage  ,*valeur;
GtkWidget *fenetre_ajouter;


GtkWidget *date;

entryType=lookup_widget(button,"comboboxentry2_cap");
entryheure=lookup_widget(button,"heure_cap1");
valeur=lookup_widget(button,"spinbutton3_cap");

GtkWidget *e_re_cap,*e_type_cap,*e_hr_cap,*e_conf_cap;


int o=0;  // controle de saisie

e_conf_cap=lookup_widget(button,"e_cnf_cap1");
e_type_cap=lookup_widget(button,"e_type_cap1");
e_hr_cap=lookup_widget(button,"e_hr_cap1");


 strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryType)));
 strcpy(c.heure,gtk_entry_get_text(GTK_ENTRY(entryheure) ) );

 c.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur));




if (strcmp(c.type,"")==0)
{o=1;
gtk_widget_show(e_type_cap);
}
else 
{o=0;
gtk_widget_hide(e_type_cap);
}

if (strcmp(c.heure,"")==0)
{o=1;
gtk_widget_show(e_hr_cap);
}
else 
{o=0;
gtk_widget_hide(e_hr_cap);
}

if (cnf1==0)
{
gtk_widget_show(e_conf_cap);
}
else 
{
gtk_widget_hide(e_conf_cap);
}

if (o==0 && cnf1==1){


modifier_capteur(refff,c);
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"modifier_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_afficher_cap ();
  gtk_widget_show (afficher_cap);
cnf1=0;

}
/*--------------l'ajout d'une fenetre pour confiermer votre modification  ---------------------------*/
  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("Login.png", NULL);

  GtkWidget *dialog = gtk_about_dialog_new();
  gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "Modifier");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "avec succés "); 
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), 
     "vous pouvez voir votre modification sur l'affichage  .");
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
  g_object_unref(pixbuf), pixbuf = NULL;
  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);
/*---------------------------------------------*/}

/*-----------------[Treeview]----------------*/
void
on_treeview1_cap_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* ref;
	gchar* type;
	gchar* hr;
	gchar* etage;
	gchar* valeur;
	gchar* date;
	
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &ref, 1, &type,2,&hr,3,&etage,4,&valeur,5,&date,-1);
	strcpy(refff,ref);
	
	}
}

/****----------------[Check Buttton]----------------**/
void
on_checkbutton1_cap_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
cnf=1;
}


void
on_checkbutton2_cap_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
cnf1=1;
}

/*------------------[Alarme comparaison Min/Max]-------------------*/
void
on_cap_alarments_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *min;
GtkWidget *max;
min=lookup_widget(button,"spinbutton1_min");
max=lookup_widget(button,"spinbutton2_max");

int min1;
min1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
int max1;
max1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(max));

GtkWidget *treeview2_cap;
GtkWidget *tache2_cap;
tache2_cap=lookup_widget(button,"tache2_cap");
treeview2_cap=lookup_widget(tache2_cap,"treeview2_cap");
afficher_alarment(treeview2_cap,typee,min1,max1);
}

/*----------------[ ouvrire alarme window]----------------------*/
void
on_ret_tach2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"tache2_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_afficher_cap ();
  gtk_widget_show (afficher_cap);
}

/*------------------[Toggle button]---------------------------**/
void
on_tmp_cap_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
strcpy(typee,"temperature");

}


void
on_debit_cap_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(typee,"debit");
}


void
on_mouvement_cap_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(typee,"mouvement");
}


void
on_fumee_cap_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(typee,"fumee");
}

/*-----------------[Affichage de Treeview]-----------------------*/
void
on_alarmei_cap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"afficher_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_tache2_cap ();
  gtk_widget_show (afficher_cap);
}


void
on_calcule_cap1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"afficher_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_calcul_cap ();
  gtk_widget_show (afficher_cap);
}


void
on_nbr_cap_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
int nnn;
char a[200];
int s;
GtkWidget *aaa;
aaa=lookup_widget(button,"spinbutton111_cap");
nnn=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aaa));
GtkWidget *nbr_ettt;
nbr_ettt=lookup_widget(button,"label_nbr_cap");


s = stat(nnn);
sprintf(a,"%d",s);
gtk_label_set_text(GTK_LABEL(nbr_ettt),a);
}


void
on_ritty_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"calcul_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_afficher_cap ();
  gtk_widget_show (afficher_cap);
}



void
on_radiobutton_debut_eya_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(typee,"debit");
}


void
on_radiobutton_mvt_eya_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(typee,"mouvement");
}


void
on_radiobutton_fume_eya_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(typee,"fumee");
}


void
on_home_eya_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_cap;
ajouter_cap=lookup_widget(button,"afficher_cap");
gtk_widget_destroy(ajouter_cap);
GtkWidget *afficher_cap;
afficher_cap = create_w_login ();
  gtk_widget_show (afficher_cap);
}

