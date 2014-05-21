#include "pages.h"

#include "macros/conteneurs.h"
#include "macros/case.h"
#include "macros/etiquette.h"
#include "macros/bouton.h"
#include "macros/list.h"
#include "callbacks.h"

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

PageEtudiant pgEtud;

Widget *page_login_creer()
{
  Widget *frame = cadre_creer("")
       , *grid = grille_creer(10, 10)
       , *align = alignement_creer(0.5, 0.5, 0, 0)

       , *emailCase = case_creer(FALSE)
       , *passCase = case_creer(TRUE)

       , *emailLbl = etiquette_creer("E-mail")
       , *passLbl = etiquette_creer("Mot de Passe")

       , *okBtn = bouton_creer("Login");

  Widget **emailPass = malloc(sizeof(Widget*) * 2);
  emailPass[0] = emailCase;
  emailPass[1] = passCase;
  Widget *signupBtn = bouton_creer("S'inscrire", inscrire_etudiant, emailPass);


  conteneur_ajouter(align, frame);
  conteneur_ajouter(frame, grid);

  conteneur_largeur_bordure(grid, 40);

  grille_attacher(grid, emailLbl,     0, 0, 1, 1);
  grille_attacher(grid, emailCase,    1, 0, 1, 1);

  grille_attacher(grid, passLbl,      0, 1, 1, 1);
  grille_attacher(grid, passCase,     1, 1, 1, 1);

  grille_attacher(grid, okBtn,        0, 3, 2, 1);
  grille_attacher(grid, signupBtn,    0, 4, 2, 1);

  conteneur_largeur_bordure(frame, 20);

  // callbacks

  return align;
}

Widget *page_etudiant_creer()
{
  Widget *frame = cadre_creer("")
       , *notbk = onglets_creer()
       , *mainGrid = grille_creer(10, 10)
       , *okBtn = bouton_creer("OK")

       , *pageInfo = grille_creer(10, 10)
       , *pageDiplome = grille_creer(10, 10)
       , *pageNote = grille_creer(10, 10);

       //Onglet informations personelles
       pgEtud.nom = case_creer(FALSE);
       pgEtud.prenom = case_creer(FALSE);
       pgEtud.email = case_creer(FALSE);
       pgEtud.cin = case_creer(FALSE);
       pgEtud.cne = case_creer(FALSE);

       //Onglet Diplome
       pgEtud.etab = case_creer(FALSE);
       pgEtud.specialite = case_creer(FALSE);
       pgEtud.nbrAns = case_creer(FALSE);
       pgEtud.anObtention = case_creer(FALSE);
       pgEtud.diplome = list_creer(7, "DUT", "DEUG", "DEUST", "LICENCE", "MAITRISE",
                              "MASTER", "CPGE");

       // Onglet notes
       // pgEtud.notes[NBR_NOTES];
  int i;
  for(i = 0; i < NBR_NOTES; ++i) pgEtud.notes[i] = case_creer(FALSE);

  // conteneurs
  conteneur_ajouter(frame, mainGrid);

  grille_attacher(mainGrid, notbk, 0, 0, 1, 1);
  grille_attacher(mainGrid, okBtn, 0, 1, 1, 1);

  onglets_ajouter(notbk, pageInfo, "Informations personelles");
  onglets_ajouter(notbk, pageDiplome, "Diplome");
  onglets_ajouter(notbk, pageNote, "Notes");

  conteneur_largeur_bordure(pageInfo, 20);
  conteneur_largeur_bordure(pageDiplome, 20);
  conteneur_largeur_bordure(pageNote, 20);

  conteneur_largeur_bordure(mainGrid, 20);
  conteneur_largeur_bordure(frame, 20);

  // Infos
  grille_attacher(pageInfo, etiquette_creer("Nom"),      0, 0, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("Prénom"),   0, 1, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("E-mail"),   0, 2, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("CIN"),      0, 3, 1, 1);
  grille_attacher(pageInfo, etiquette_creer("CNE"),      0, 4, 1, 1);

  grille_attacher(pageInfo, pgEtud.nom,     1, 0, 1, 1);
  grille_attacher(pageInfo, pgEtud.prenom,  1, 1, 1, 1);
  grille_attacher(pageInfo, pgEtud.email,   1, 2, 1, 1);
  grille_attacher(pageInfo, pgEtud.cin,     1, 3, 1, 1);
  grille_attacher(pageInfo, pgEtud.cne,     1, 4, 1, 1);

  // Diplome
  grille_attacher(pageDiplome, etiquette_creer("Diplome"),         0, 0, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("Spécialité"),      0, 1, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("Etablissement"),   0, 2, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("Nombre d'années"), 0, 3, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("An d'obtention"),  0, 4, 1, 1);

  grille_attacher(pageDiplome, pgEtud.diplome,       1, 0, 1, 1);
  grille_attacher(pageDiplome, pgEtud.etab,          1, 1, 1, 1);
  grille_attacher(pageDiplome, pgEtud.specialite,    1, 2, 1, 1);
  grille_attacher(pageDiplome, pgEtud.nbrAns,        1, 3, 1, 1);
  grille_attacher(pageDiplome, pgEtud.anObtention,   1, 4, 1, 1);

  // Notes
  Widget *notesLabels[NBR_NOTES];
  for(i = 0; i < NBR_NOTES; ++i)
    {
      char label[6];
      sprintf(label, "Note %d", i + 1);
      notesLabels[i] = etiquette_creer(label);
      grille_attacher(pageNote, notesLabels[i], 0, i, 1, 1);
      grille_attacher(pageNote, pgEtud.notes[i], 1, i, 1, 1);
    }

  // callbacks
  Widget **widgetsNotes = malloc(sizeof(Widget*) * NBR_NOTES * 2);

  for (i = 0; i < NBR_NOTES; i++) widgetsNotes[i] = pgEtud.notes[i];
  for (i = NBR_NOTES; i < NBR_NOTES * 2; i++)
    widgetsNotes[i] = notesLabels[i - NBR_NOTES];

  g_signal_connect(G_OBJECT(pgEtud.diplome), "changed",
                   G_CALLBACK(cacher_notes), widgetsNotes);
  return frame;
}
