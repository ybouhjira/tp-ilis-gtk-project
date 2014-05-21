#ifndef CASE_H
#define CASE_H

#include "macors.h"

#include <gtk/gtk.h>

typedef GtkInputPurpose TypeCase;

Widget *case_creer(boolean motDePasse);

#define case_text(entry) gtk_entry_get_text(GTK_ENTRY(entry))
#define case_set_text(entry, text) gtk_entry_set_text(GTK_ENTRY(entry), text)

#endif // CASE_H
