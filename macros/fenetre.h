#ifndef FENETRE_H
#define FENETRE_H

#include "macors.h"

#include <string.h>

/** Entrées :
  *   titre : Le titre de la fenetre
  *   icon : le chemin de l'icon
  *   redimonsionable : indique si la fenetre peut etre redimonsionée
  *   padding : espace entre le bord de la fenetre et son contenu
  *   estPrincipale : ferme le programe
  * Description :
  *   Cree une fenetre
  */
func_declare(Widget*, fenetre_creer,
  char *titre;
  boolean estPrincipale;
  Dimensions dim;
  char *icon;
  boolean redimonsinable;
  int padding;
)

#define fenetre_creer(...) func_link(fenetre_creer, __VA_ARGS__)
func_head(Widget*, fenetre_creer)
{

  // Valeurs par défault des pramètres
  char* param_default(titre, "");
  char* param_default(icon, "");
  boolean param_default(redimonsinable, TRUE);
  int  param_default(padding, 10);
  boolean param_default(estPrincipale, FALSE);
  Dimensions dim;
  param_default(dim.l, 200);
  param_default(dim.L, 400);

  // Création de la fenetre
  GtkWidget *widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWindow *win = GTK_WINDOW(widget);

  //// Titre
  gtk_window_set_title(win, titre);

  //// Icon
  if(strlen(icon) > 0)
    gtk_window_set_icon_from_file(win, icon, NULL);

  //// Dimensions
  gtk_window_set_default_size(win, dim.l, dim.L );

  //// Redimonsionable
  gtk_window_set_resizable(win, redimonsinable);

  //// Fermer le programme lors de la femeture
  if(estPrincipale)
    g_signal_connect(G_OBJECT(widget), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

  //// padding
  gtk_container_set_border_width(GTK_CONTAINER(widget), padding);

  ////
  gtk_window_set_position(GTK_WINDOW(widget), GTK_WIN_POS_CENTER);

  return widget;
}

// afficher la fenetre
#define fenetre_afficher gtk_widget_show_all


#endif // FENETRE_H
