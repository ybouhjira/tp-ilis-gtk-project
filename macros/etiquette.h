#ifndef LABEL_H
#define LABEL_H

#include "macors.h"

#include <gtk/gtk.h>

#define etiquette_creer gtk_label_new
#define etiquette_text(lbl, txt) gtk_label_set_text(GTK_LABEL(lbl), txt)


#endif // LABEL_H
