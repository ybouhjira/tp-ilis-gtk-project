#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "macros/macors.h"

// afficher/cacher les notes selon le diplome
void cacher_notes(Widget *dipl, void* widgets);

// afficher/cacher la case confirmer mot de passe
//void ajouter_confirm_pass(Widget* btnInscrir, void* widgets);

// inscrire un étudiant
void inscrire_etudiant(Widget *btn, void* widgets);

#endif // CALLBACKS_H
