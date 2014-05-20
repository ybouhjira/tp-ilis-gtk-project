
#include "conteneurs.h"

Widget *grille_creer(int row, int col)
{
  Widget *w = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(w), row);
  gtk_grid_set_column_spacing(GTK_GRID(w), col);
  gtk_grid_set_column_homogeneous(GTK_GRID(w), FALSE);
  return w;
}

Widget *conteneur_pile_creer()
{
  GtkWidget *stack = gtk_stack_new();
  gtk_stack_set_transition_type(GTK_STACK(stack),
                                GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);
  gtk_stack_set_transition_duration(GTK_STACK(stack), 1000);
  return stack;
}
