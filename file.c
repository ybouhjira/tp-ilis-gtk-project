#include "file.h"
#include "etudiant.h"

GKeyFile* fichier_ouvrir(const char *filename)
{
  GKeyFile *file = g_key_file_new();

  g_key_file_load_from_file(file, filename, G_KEY_FILE_NONE, NULL);

  return file;
}

gboolean fichier_supprimer_etudiant(GKeyFile *file, const char *cne)
{
  GError *err = NULL;
  g_key_file_remove_group(file, cne, &err);

  // une erreur s'est produite
  if(err) return FALSE;
  else return TRUE;
}

void fichier_ajouter_etudiant(GKeyFile *file, Etudiant etud)
{
  g_key_file_set_string(file, etud.cne, "cin", etud.cin);
  g_key_file_set_string(file, etud.cne, "nom", etud.nom);
  g_key_file_set_string(file, etud.cne, "prenom", etud.prenom);
  g_key_file_set_string(file, etud.cne, "motDePasse", etud.motDePasse);
  g_key_file_set_string(file, etud.cne, "cin", str(etud.diplome));
  g_key_file_set_string(file, etud.cne, "specialite", etud.specialite);
  g_key_file_set_string(file, etud.cne, "etab", etud.etab);

  g_key_file_set_integer(file, etud.cne, "anDiplome", etud.anDiplome);
  g_key_file_set_integer(file, etud.cne, "nbrAns", etud.nbrAns);

  g_key_file_set_double_list(file, etud.cne, "notes", etud.notes,
                             nbr_notes(etud.diplome));
}
