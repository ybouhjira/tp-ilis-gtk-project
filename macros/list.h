#ifndef LIST_H
#define LIST_H

#include "macors.h"

/**
 * Entrées:
 *  count : nombre d'éléments
 *  ... : Les éléments de la liste
 * Sortie:
 *  La liste crée
 */
Widget* list_creer(int count, ...);


#define list_actif(combo) \
  gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(combo))
#endif // LIST_H
