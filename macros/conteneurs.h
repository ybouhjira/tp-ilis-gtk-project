#ifndef CONTENEURS_H
#define CONTENEURS_H

#include <gtk/gtk.h>
#include "macors.h"

#define conteneur_largeur_bordure(container, w)\
  gtk_container_set_border_width(GTK_CONTAINER(container), w)

// GtkAlignement
#define alignement_creer gtk_alignment_new
#define conteneur_ajouter(container, widget) \
  gtk_container_add(GTK_CONTAINER(container), widget)

// Frame
#define cadre_creer gtk_frame_new

// Stack
Widget *conteneur_pile_creer();

#define conteneur_pile_ajouter(stack, widget, nom) \
  gtk_stack_add_named(GTK_STACK(stack), widget, nom)

#define conteneur_pile_afficher(stack, nom) \
  gtk_stack_set_visible_child_name(GTK_STACK(stack), nom);

//Grid
Widget *grille_creer(int row, int col);

#define grille_attacher(grid, widget, l, c, w, h) \
  gtk_grid_attach(GTK_GRID(grid), widget, l, c, w, h)

// Expander
#define onglets_creer gtk_notebook_new
#define onglets_ajouter(notebook, wg, label) \
  gtk_notebook_append_page(GTK_NOTEBOOK(notebook), wg, gtk_label_new(label))

#endif // CONTENEURS_H
