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
  conteneur_largeur_bordure(stack, 20);

  conteneur_pile_ajouter(stack, login_page_creer(), "login");
  conteneur_pile_ajouter(stack, page_etudiant_creer(), "etudiant");

  // this is temporary
  conteneur_pile_afficher(stack, "etudiant");

  fenetre_afficher(f);
  lancer();
  return 0;
}

