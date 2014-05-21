#include "callbacks.h"
#include "macros/etiquette.h"
#include "macros/list.h"
#include "macros/conteneurs.h"
#include "macros/case.h"
#include "macros/warn.h"
#include "pages.h"
#include "mainstack.h"

#include <string.h>
#include <stdlib.h>


void cacher_notes(Widget *dipl, void *widgets)
{
  // TODO
  Widget **notes = widgets;

  Diplome actvDipl = str_to_dipl(list_actif(dipl));
  int nbrNotes = nbr_notes(actvDipl), i;

  for(i = 0; i < nbrNotes; ++i) widget_visible(notes[i], TRUE);
  for(i = NBR_NOTES; i < NBR_NOTES * 2; ++i) widget_visible(notes[i], TRUE);

  for(i = nbrNotes; i < NBR_NOTES; ++i) widget_visible(notes[i], FALSE);
  for(i = NBR_NOTES + nbrNotes; i < NBR_NOTES * 2; ++i)
    widget_visible(notes[i], FALSE);

  if(actvDipl == CPGE) etiquette_text(notes[NBR_NOTES], "Classement");
  else
      etiquette_text(notes[NBR_NOTES], "Note 1");
}

void inscrire_etudiant(Widget *btn, void* widgets)
{
  // email & password
  Widget **entries = widgets
       , *win = gtk_widget_get_toplevel(btn);

  GRegex *regexEmail = g_regex_new("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*"
              "@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$", 0, 0, NULL);


  const char *email = case_text(entries[0])
           , *pass = case_text(entries[1]);

  if(!g_regex_match(regexEmail, email, 0, 0))
    {
      msg(win, "Adresse e-mail invalide");
      return;
    }

  if(strlen(pass) < 8)
    {
      msg(win, "Le mot de passe doit contenit au mois 8 caratères");
      return;
    }

  case_set_text(pgEtud.email, email);
  widget_actif(pgEtud.email, FALSE);

  conteneur_pile_afficher(mainStack, "etudiant");

}

void ajouter_etudiant(Widget *btn, void* data)
{
  // Validation
  Widget* win = gtk_widget_get_toplevel(btn);

  GRegex *nomrgx = g_regex_new("^[a-zA-Z ]{3, 25}$", 0, 0, NULL)
       , *cinrgx = g_regex_new("^[a-zA-Z0-9]{6, 10}$", 0, 0, NULL)
       , *cnergx = g_regex_new("^[0-9]{8-10}$", 0, 0, NULL)
       , *emailrgx = g_regex_new("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*"
                                 "@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$",
                                 0, 0, NULL)
       , *etabrgx = g_regex_new("^[a-zA-Z ]{3, 25}$", 0, 0, NULL)
       , *specrg = g_regex_new("^[a-zA-Z ]{3, 100}$", 0, 0, NULL);

  const char *nom = case_text(pgEtud.nom)
           , *pnom = case_text(pgEtud.prenom)
           , *cin = case_text(pgEtud.cin)
           , *cne = case_text(pgEtud.cne)
           , *email = case_text(pgEtud.email)
           , *etab = case_text(pgEtud.etab)
           , *spec = case_text(pgEtud.specialite);

  int nbrAns = atoi(case_text(pgEtud.nbrAns))
    , anDipl = atoi(case_text(pgEtud.anObtention));

  Diplome dipl = atoi(case_text(pgEtud.diplome));

  if(!g_regex_match(nomrgx, nom, 0, 0)) msg(win, "Nom invalide");
  if(!g_regex_match(nomrgx, pnom, 0, 0)) msg(win, "Prénom invalide");
  if(!g_regex_match(cinrgx, cin, 0, 0)) msg(win, "CIN invalide");
  if(!g_regex_match(cnergx, cne, 0, 0)) msg(win, "CNE invalide");
  if(!g_regex_match(emailrgx, email, 0, 0)) msg(win, "Email invalide");
  if(!g_regex_match(etabrgx, etab, 0, 0)) msg(win, "Nom invalide");
  if(!g_regex_match(specrg, spec, 0, 0)) msg(win, "Spécialité invalide");

  if(nbrAns < 0) msg(win, "Nombre d'année invalide");
  if(anDipl < 0) msg(win, "Annnée d'obtention invalide");

  Etudiant etud;

  strcpy(etud.nom,        nom);
  strcpy(etud.prenom,     pnom);
  strcpy(etud.cin,        cin);
  strcpy(etud.cne,        cne);
  strcpy(etud.email,      email);
  strcpy(etud.etab,       etab);
  strcpy(etud.specialite, spec);

  etud.nbrAns = nbrAns;
  etud.anDiplome = anDipl;
  etud.diplome = dipl;

  int nbrNotesDipl = nbr_notes(etud.diplome);

  int i;
  for(i = 0; i < nbrNotesDipl; ++i)
      etud.notes[i] = atoi(case_text(pgEtud.notes[i]));


}
