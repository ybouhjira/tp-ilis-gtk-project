#ifndef GRILLE_H
#define GRILLE_H

#define grille_creer gtk_grid_new

#define grille_attacher(grid, widget, l, c, w, h) \
  gtk_grid_attach(GTK_GRID(grid), widget, l, c, w, h)

#endif // GRILLE_H
