#include "pages.h"
#include "etudiant.h"

#include "macros/conteneurs.h"
#include "macros/case.h"
#include "macros/etiquette.h"
#include "macros/bouton.h"

#include <gtk/gtk.h>
#include <string.h>

Widget *login_page_creer()
{
  Widget *frame = cadre_creer("")
       , *grid = grille_creer(10, 10)
       , *align = alignement_creer(0.5, 0.5, 0, 0)

       , *emailCase = case_creer(FALSE)
       , *passCase = case_creer(TRUE)

       , *emailLbl = etiquette_creer("E-mail")
       , *passLbl = etiquette_creer("Mot de Passe")

       , *okBtn = bouton_creer("OK")
       , *signupBtn = bouton_creer("S'inscrire");

  conteneur_ajouter(align, frame);
  conteneur_ajouter(frame, grid);

  conteneur_largeur_bordure(grid, 40);

  grille_attacher(grid, emailLbl, 0, 0, 1, 1);
  grille_attacher(grid, emailCase, 1, 0, 1, 1);
  grille_attacher(grid, passLbl, 0, 1, 1, 1);
  grille_attacher(grid, passCase, 1, 1, 1, 1);
  grille_attacher(grid, okBtn, 0, 2, 2, 1);
  grille_attacher(grid, signupBtn, 0, 3, 2, 1);

  return align;
}

Widget *student_page_creer()
{
  Widget *frame = cadre_creer("")
       , *notbk = onglets_creer()
       , *mainGrid = grille_creer(10, 10)
       , *okBtn = bouton_creer("OK")

       , *pageInfo = grille_creer(10, 10)
       , *pageDiplome = grille_creer(10, 10)
       , *pageNote = grille_creer(10, 10)

       // Onglet informations personelles
       , *nom = case_creer(FALSE)
       , *prenom = case_creer(FALSE)
       , *email = case_creer(FALSE)
       , *cin = case_creer(FALSE)
       , *cne = case_creer(FALSE)

       // Onglet Diplome
       , *diplome = case_creer(FALSE)
       , *etab = case_creer(FALSE)
       , *specialite = case_creer(FALSE)
       , *nbrAns = case_creer(FALSE)
       , *anObtention = case_creer(FALSE)

       // Onglet notes
       , *notes[NBR_NOTES];
  int i;
  for(i = 0; i < NBR_NOTES; ++i) notes[i] = case_creer(FALSE);

  // conteneurs
  grille_attacher(mainGrid, frame, 0, 0, 1, 1);
  grille_attacher(mainGrid, okBtn, 0, 1, 1, 1);

  conteneur_ajouter(frame, notbk);

  onglets_ajouter(notbk, pageInfo, "Informations personelles");
  onglets_ajouter(notbk, pageDiplome, "Diplome");
  onglets_ajouter(notbk, pageNote, "Note");

  // Infos
  grille_attacher(pageInfo, etiquette_creer("Nom"),      0, 0, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("Prénom"),   0, 1, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("E-mail"),   0, 2, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("CIN"),      0, 3, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("CNE"),      0, 4, 1, 1);

  grille_attacher(pageInfo, nom,     1, 0, 1, 1);
  grille_attacher(pageInfo, prenom,  1, 1, 1, 1);
  grille_attacher(pageInfo, email,   1, 2, 1, 1);
  grille_attacher(pageInfo, cin,     1, 3, 1, 1);
  grille_attacher(pageInfo, cne,     1, 4, 1, 1);

  // Diplome
  grille_attacher(pageInfo, etiquette_creer("Diplome"),         0, 0, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("Spécialité"),      0, 1, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("Etablissement"),   0, 2, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("Nombre d'années"), 0, 3, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("An d'obtention"),  0, 4, 1, 1);

  grille_attacher(pageInfo, diplome,       1, 0, 1, 1);
  grille_attacher(pageInfo, etab,          1, 1, 1, 1);
  grille_attacher(pageInfo, specialite,    1, 2, 1, 1);
  grille_attacher(pageInfo, nbrAns,        1, 3, 1, 1);
  grille_attacher(pageInfo, anObtention,   1, 4, 1, 1);

  // Notes
  for(i = 0; i < NBR_NOTES; ++i)
    {
      char label[6];
      sprintf(label, "Note %d", i);
      grille_attacher(pageInfo, etiquette_creer(label), 0, i, 1, 1);
      grille_attacher(pageInfo, notes[i], 1, i, 1, 1);
    }


  return mainGrid;
}