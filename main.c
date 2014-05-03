#include <stdio.h>
#include "macros/fenetre.h"
#include "macros/grille.h"
#include "macros/bouton.h"
#include "macros/css.h"
#include "macros/conteneurs.h"

int main(int argc, char *argv[])
{
  initialiser(&argc, &argv);

  css_appliquer("style.css");

  Widget *f = fenetre_creer(
           .titre="Inscription ILIS",
           .estPrincipale=TRUE,
           .dim={1000, 500}),
         *grille = grille_creer(),
         *bouton = bouton_creer("Cliquer ici");

  conteneur_ajouter(f, grille);

  grille_attacher(grille, bouton, 0, 0, 1, 1);


  fenetre_afficher(f);
  lancer();
  return 0;
}

