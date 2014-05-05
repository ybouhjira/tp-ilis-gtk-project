
#include "conteneurs.h"

Widget *grille_creer(int row, int col)
{
  Widget *w = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(w), row);
  gtk_grid_set_column_spacing(GTK_GRID(w), col);
  gtk_grid_set_column_homogeneous(GTK_GRID(w), FALSE);
  return w;
}
