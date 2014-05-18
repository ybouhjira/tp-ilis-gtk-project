#include <stdio.h>
#include "macros/fenetre.h"
#include "macros/css.h"
#include "macros/conteneurs.h"

#include "pages.h"

int main(int argc, char *argv[])
{
  initialiser(&argc, &argv);

  css_appliquer("style.css");

  css_appliquer("gnome-applications.css");
  css_appliquer("gtk.css");
  css_appliquer("gtk-fallback.css");
  css_appliquer("gtk-main-common.css");
  css_appliquer("gtk-main.css");
  css_appliquer("gtk-widgets-assets.css");
  css_appliquer("gtk-widgets-backgrounds.css");
  css_appliquer("gtk-widgets-borders.css");
  css_appliquer("gtk-widgets.css");
  css_appliquer("other-applications.css");
  css_appliquer("unity.css");
  css_appliquer("window-controls.css");

  Widget *f = fenetre_creer("Inscription ILIS", TRUE, {1000, 500}),
         *stack = conteneur_pile_creer();

  conteneur_ajouter(f, stack);
  conteneur_largeur_bordure(stack, 20);

  //conteneur_pile_ajouter(stack, login_page_creer(), "login");
  conteneur_pile_ajouter(stack, page_etudiant_creer(), "etudiant");

  // this is temporary
  conteneur_pile_afficher(stack, "etudiant");

  fenetre_afficher(f);
  lancer();
  return 0;
}

