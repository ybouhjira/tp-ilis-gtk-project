#include "list.h"

Widget* list_creer(int count, ...)
{
  Widget *combo = gtk_combo_box_text_new();

  va_list args;
  int i;

  va_start(args, count);
  for (i = 0; i < count; ++i)
    gtk_combo_box_text_append(
          GTK_COMBO_BOX_TEXT(combo), NULL, va_arg(args, char*));
  va_end(args);

  gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);

  return combo;
}
