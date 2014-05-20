#include "pages.h"
#include "etudiant.h"

#include "macros/conteneurs.h"
#include "macros/case.h"
#include "macros/etiquette.h"
#include "macros/bouton.h"
#include "macros/list.h"
#include "callbacks.h"

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

Widget *page_login_creer()
{
  Widget *frame = cadre_creer("")
       , *grid = grille_creer(10, 10)
       , *align = alignement_creer(0.5, 0.5, 0, 0)

       , *emailCase = case_creer(FALSE)
       , *passCase = case_creer(TRUE)
       , *passConfirm = case_creer(TRUE)

       , *emailLbl = etiquette_creer("E-mail")
       , *passLbl = etiquette_creer("Mot de Passe")
       , *passCnfrmLbl = etiquette_creer("Confirmer le mot de passe")

       , *okBtn = bouton_creer("Login");



  // Confirmer le mot de passe
  Widget **cnfrms = malloc(sizeof(Widget*) * 3);

  cnfrms[0] = passCnfrmLbl;
  cnfrms[1] = passConfirm;
  cnfrms[2] = grid;

  // lier le bouton d'inscrire avec le callback ajouter_confirm_pass
  Widget *signupBtn = bouton_creer("S'inscrire", ajouter_confirm_pass, cnfrms);



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
       , *pageNote = grille_creer(10, 10)

       // Onglet informations personelles
       , *nom = case_creer(FALSE)
       , *prenom = case_creer(FALSE)
       , *email = case_creer(FALSE)
       , *cin = case_creer(FALSE)
       , *cne = case_creer(FALSE)

       // Onglet Diplome
       , *etab = case_creer(FALSE)
       , *specialite = case_creer(FALSE)
       , *nbrAns = case_creer(FALSE)
       , *anObtention = case_creer(FALSE)
       , *diplome = list_creer(7, "DUT", "DEUG", "DEUST", "LICENCE", "MAITRISE",
                              "MASTER", "CPGE")

       // Onglet notes
       , *notes[NBR_NOTES];
  int i;
  for(i = 0; i < NBR_NOTES; ++i) notes[i] = case_creer(FALSE);

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

  grille_attacher(pageInfo, nom,     1, 0, 1, 1);
  grille_attacher(pageInfo, prenom,  1, 1, 1, 1);
  grille_attacher(pageInfo, email,   1, 2, 1, 1);
  grille_attacher(pageInfo, cin,     1, 3, 1, 1);
  grille_attacher(pageInfo, cne,     1, 4, 1, 1);

  // Diplome
  grille_attacher(pageDiplome, etiquette_creer("Diplome"),         0, 0, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("Spécialité"),      0, 1, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("Etablissement"),   0, 2, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("Nombre d'années"), 0, 3, 1, 1);
  grille_attacher(pageDiplome, etiquette_creer("An d'obtention"),  0, 4, 1, 1);

  grille_attacher(pageDiplome, diplome,       1, 0, 1, 1);
  grille_attacher(pageDiplome, etab,          1, 1, 1, 1);
  grille_attacher(pageDiplome, specialite,    1, 2, 1, 1);
  grille_attacher(pageDiplome, nbrAns,        1, 3, 1, 1);
  grille_attacher(pageDiplome, anObtention,   1, 4, 1, 1);

  // Notes
  Widget *notesLabels[NBR_NOTES];
  for(i = 0; i < NBR_NOTES; ++i)
    {
      char label[6];
      sprintf(label, "Note %d", i + 1);
      notesLabels[i] = etiquette_creer(label);
      grille_attacher(pageNote, notesLabels[i], 0, i, 1, 1);
      grille_attacher(pageNote, notes[i], 1, i, 1, 1);
    }

  // callbacks
  Widget **widgetsNotes = malloc(sizeof(Widget*) * NBR_NOTES * 2);

  for (i = 0; i < NBR_NOTES; i++) widgetsNotes[i] = notes[i];
  for (i = NBR_NOTES; i < NBR_NOTES * 2; i++)
    widgetsNotes[i] = notesLabels[i - NBR_NOTES];

  g_signal_connect(G_OBJECT(diplome), "changed",
                   G_CALLBACK(cacher_notes), widgetsNotes);
  return frame;
}
