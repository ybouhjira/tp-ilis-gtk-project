#include <stdio.h>
#include "macros/fenetre.h"
#include "macros/css.h"
#include "macros/conteneurs.h"
#include "macros/warn.h"

#include "pages.h"
#include "mainstack.h"

// conteneur principale
Widget *mainStack;

gboolean switch_page(gpointer stack)
{
  Widget *wstack = stack;
  conteneur_pile_afficher(wstack, "etudiant");
  return FALSE;
}

int main(int argc, char *argv[])
{
  initialiser(&argc, &argv);

  css_appliquer("style.css");

  Widget *f = fenetre_creer("Inscription ILIS", TRUE, {1000, 500});
  mainStack = conteneur_pile_creer();

  conteneur_ajouter(f, mainStack);
  conteneur_largeur_bordure(mainStack, 20);

  Widget *pgLogin = page_login_creer()
       , *pgEtud = page_etudiant_creer();

  conteneur_pile_ajouter(mainStack, pgLogin, "login");
  conteneur_pile_ajouter(mainStack, pgEtud, "etudiant");

  //g_timeout_add(500, switch_page, stack);

  fenetre_afficher(f);
  lancer();
  return 0;
}

