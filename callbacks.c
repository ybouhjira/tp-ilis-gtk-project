#include "callbacks.h"
#include "etudiant.h"
#include "macros/etiquette.h"
#include "macros/list.h"
#include "macros/conteneurs.h"

void cacher_notes(Widget *dipl, void *widgets)
{
  // TODO
  Widget **notes = widgets;

  Diplome actvDipl = str_to_dipl(list_actif(dipl));
  int nbrNotes = nbr_notes(actvDipl), i;

  for(i = 0; i < nbrNotes; ++i) widget_afficher(notes[i], TRUE);
  for(i = NBR_NOTES; i < NBR_NOTES * 2; ++i) widget_afficher(notes[i], TRUE);

  for(i = nbrNotes; i < NBR_NOTES; ++i) widget_afficher(notes[i], FALSE);
  for(i = NBR_NOTES + nbrNotes; i < NBR_NOTES * 2; ++i)
    widget_afficher(notes[i], FALSE);

  if(actvDipl == CPGE) etiquette_text(notes[NBR_NOTES], "Classement");
  else
      etiquette_text(notes[NBR_NOTES], "Note 1");
}


void ajouter_confirm_pass(Widget* btnInscrir, void* widgets)
{
  // label confirmer, entry, & grid
  Widget **confrms = widgets;

  printf("%p, %p, %p\n", confrms[0], confrms[1], confrms[2]);

  grille_attacher(confrms[2], confrms[0], 0, 2, 1, 1);
  grille_attacher(confrms[2], confrms[1],  1, 2, 1, 1);

  widget_afficher(confrms[0], TRUE);
  widget_afficher(confrms[1], TRUE);
}
