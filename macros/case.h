#ifndef CASE_H
#define CASE_H

#include "macors.h"

#include <gtk/gtk.h>

Widget *case_creer(boolean motDePasse)
{
  GtkWidget *entry = gtk_entry_new();

  if(motDePasse)
    {
      gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE);
      gtk_entry_set_invisible_char(GTK_ENTRY(entry), '*');
    }

  return entry;
}

#endif // CASE_H
