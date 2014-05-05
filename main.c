#include <stdio.h>
#include "macros/fenetre.h"
#include "macros/css.h"
#include "macros/conteneurs.h"

#include "pages.h"

int main(int argc, char *argv[])
{
  initialiser(&argc, &argv);

  css_appliquer("style.css");

  Widget *f = fenetre_creer("Inscription ILIS", TRUE, {1000, 500}),
         *stack = conteneur_pile_creer();

  conteneur_ajouter(f, stack);

  conteneur_pile_ajouter(stack, login_page_creer(), "login");

  fenetre_afficher(f);
  lancer();
  return 0;
}

