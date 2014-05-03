#ifndef CONTENEURS_H
#define CONTENEURS_H

#include <gtk/gtk.h>

// GtkAlignement
#define alignement_creer gtk_alignment_new
#define conteneur_ajouter(container, widget) \
  gtk_container_add(GTK_CONTAINER(container), widget)

// Frame
#define cadre_creer gtk_frame_new

// Stack
#define conteneur_pile_creer gtk_stack_new
#define conteneur_pile_ajouter gtk_stack_add_named

#endif // CONTENEURS_H
