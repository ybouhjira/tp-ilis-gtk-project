#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include "macros/macors.h"
#include "etudiant.h"

// Page etudiant
typedef struct
{
  Widget *nom
       , *prenom
       , *email
       , *cin
       , *cne

       // Onglet Diplome
       , *etab
       , *specialite
       , *nbrAns
       , *anObtention
       , *diplome

       // Onglet notes
       , *notes[NBR_NOTES];
} PageEtudiant;

extern PageEtudiant pgEtud;


// Crée la page de login
Widget *page_login_creer();

// Crée la page dans laquelle l'étudiant s'inscrie ou modifie ses infos
Widget *page_etudiant_creer();

#endif // LOGIN_PAGE_H
