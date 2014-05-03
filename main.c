#include <stdio.h>
#include "macros/fenetre.h"

int main(int argc, char *argv[])
{
  initialiser(&argc, &argv);

  Widget *f = fenetre_creer(.titre="Ma fenetre", .estPrincipale=TRUE, .dim={1000, 500});

  fenetre_afficher(f);
  lancer();
  return 0;
}

