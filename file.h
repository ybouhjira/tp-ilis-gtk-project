#ifndef FILE_H
#define FILE_H

#include <glib.h>

typedef struct Etudiant Etudiant;

// Ouvrir le fichier contenant les étudiants
GKeyFile* fichier_ouvrir(const char *filename);

// Supprimer un étudiant
gboolean fichier_supprimer(GKeyFile *file, const char *cne);

// Ajouter un etudiant
void fichier_ajouter_etudiant(GKeyFile *file, Etudiant etud);

#endif // FILE_H
