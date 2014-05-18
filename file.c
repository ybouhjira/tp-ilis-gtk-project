#include "file.h"
#include "etudiant.h"

#include <string.h>

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

void fichier_modifier_etudiant(GKeyFile *file, Etudiant etud)
{
  g_key_file_set_string(file, etud.cne, "cin", etud.cin);
  g_key_file_set_string(file, etud.cne, "nom", etud.nom);
  g_key_file_set_string(file, etud.cne, "prenom", etud.prenom);
  g_key_file_set_string(file, etud.cne, "motDePasse", etud.motDePasse);
  g_key_file_set_string(file, etud.cne, "diplome", str(etud.diplome));
  g_key_file_set_string(file, etud.cne, "specialite", etud.specialite);
  g_key_file_set_string(file, etud.cne, "etab", etud.etab);

  g_key_file_set_integer(file, etud.cne, "anDiplome", etud.anDiplome);
  g_key_file_set_integer(file, etud.cne, "nbrAns", etud.nbrAns);

  g_key_file_set_double_list(file, etud.cne, "notes", etud.notes,
                             nbr_notes(etud.diplome));
}

Etudiant fichier_lire_etudiant(GKeyFile *file, char *cne, GError **err)
{
  Etudiant etud;

  char *nom = g_key_file_get_string(file, cne, "nom", err)
     , *pnom = g_key_file_get_string(file, cne, "prenom", err)
     , *cin = g_key_file_get_string(file, cne, "cin", err)
     , *pass = g_key_file_get_string(file, cne, "motDePasse", err)
     , *dipl = g_key_file_get_string(file, cne, "diplome", err)
     , *spec =  g_key_file_get_string(file, cne, "specialite", err)
     , *etab = g_key_file_get_string(file, cne, "etab", err);

  int nbrAns = g_key_file_get_integer(file, cne, "nbrAns", err)
    , anDipl = g_key_file_get_integer(file, cne, "anDiplome", err);

  gsize size;
  double* notes = g_key_file_get_double_list(file, cne, "notes", &size, err);

  strcpy(etud.nom, nom);
  strcpy(etud.prenom, pnom);
  strcpy(etud.cin, cin);
  strcpy(etud.motDePasse, pass);
  strcpy(etud.specialite, spec);
  strcpy(etud.etab, etab);

  etud.diplome = str_to_dipl(dipl);

  etud.nbrAns = nbrAns;
  etud.anDiplome = anDipl;

  memcpy(etud.notes, notes, sizeof(double) * size);

  return etud;
}
