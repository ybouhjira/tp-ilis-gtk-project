#ifndef BOUTON_H
#define BOUTON_H

#include "macors.h"

#include <string.h>

/** Entrées :
  *   texte : texte du bouton
  *   icon : icon du bouton
  *   callback : fonction appele lorsque le bouton est cliqué
  *   data : parametere pour le callback
  * Description :
  *   Cree un bouton
  */
func_declare(Widget*, bouton_creer,
  char *texte;
  char *icon;
  void (*callback)(Widget* widget, void* data);
  void* data;)

#define bouton_creer(...) func_link(bouton_creer, __VA_ARGS__)

func_head(Widget*, bouton_creer)
{
  char* param_default(texte, "");
  char* param_default(icon, "");
  void* param_default(callback, NULL);
  void* param_default(data, NULL);

  Widget* bouton = gtk_button_new_with_label(texte);

  if(strlen(icon))
    gtk_button_set_image(GTK_BUTTON(bouton),
                         gtk_image_new_from_file(icon));

  if(callback)
    g_signal_connect(G_OBJECT(bouton), "clicked", callback, data);

  return bouton;
}

#endif // BOUTON_H
