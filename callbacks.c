#include "callbacks.h"
#include "etudiant.h"
#include "macros/etiquette.h"
#include "macros/list.h"
#include "macros/conteneurs.h"
#include "macros/case.h"
#include "macros/warn.h"

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

void inscrire_etudiant(Widget *btn, void* widgets)
{
  // email & password
  Widget **entries = widgets;

  GRegex *regex = g_regex_new("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*"
              "@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$", 0, 0, NULL);

  Widget *win = gtk_widget_get_toplevel(btn);
  if(g_regex_match(regex, case_text(entries[0]), 0, 0))
    {
    msg(win, "email valid");
    }
  else
    {
    msg(win, "email invalide");
    }

}
