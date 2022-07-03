#include <gtk/gtk.h>


void
on_login_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_inscription_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_insc_retour_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_inscri_ok_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_valid_niv_etud_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gu_ajouter_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gu_recherche_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gu_niv_etud_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gu_retour_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_gu_F5_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_recherche_ok_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifier_ok_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_niveau_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supp_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_check_supp_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_annul_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_valid_supp_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_edit_niv_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_pw_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_color_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_copyright_user_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_copyright_ok_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_paint_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

/*---------------------[MAJDI]--------------------------*/

void
on_buttonbhyaffichera_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhyAjouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1bhy_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonbhyactualiser_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhyretour_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhyajouter_aff_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhysupprimer_aff_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhymodifier_aff_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhyrechercher_aff_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbuttonen_stock_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonalert_rupture_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonrupture_stock_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonrecherche_stock_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_entrybhyidentifiantm_grab_focus     (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_radiobuttonstockm_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonalert_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonrupture_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonbhymodifier_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhyretour_succ_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhymodretour_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonbhyerreur_retour_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobuttonrupture_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonalert_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonstockm_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


// eyaa

void
on_buttonOk_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAnnuler_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_aff_cap1_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_aj_cap1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_md_cap_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_spp_cap1_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_rech_cap1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_ann_suup__cap_activate              (GtkButton       *button,
                                        gpointer         user_data);

void
on_cnf_spp_cap_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ann_md5_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_moddd_cap_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_cap_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbutton1_cap_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_cap_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_cap_alarments_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_ret_tach2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_tmp_cap_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_debit_cap_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mouvement_cap_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fumee_cap_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_alarmei_cap_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_calcule_cap1_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_nbr_cap_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_ritty_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_debut_eya_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_mvt_eya_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_fume_eya_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_home_eya_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
