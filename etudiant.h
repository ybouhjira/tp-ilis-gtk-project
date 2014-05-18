#ifndef ETUDIANT_H
#define ETUDIANT_H

#endif // ETUDIANT_H

#define str(enum) #enum

/**
  * Diplome
  */
typedef enum {DUT, DEUG, DEUST, LICENCE, MAITRISE, MASTER, CPGE} Diplome;

#define NBR_NOTES 10

/**
  * Structure Etudiant
  */
typedef struct Etudiant
{
    char nom[20];
    char prenom[20];

    char motDePasse[25];
    char cin[20];
    char cne[20];
    double notes[NBR_NOTES];

    Diplome diplome;
    char specialite[100];
    char etab[30];
    int nbrAns;
    int anDiplome;
} Etudiant;

/**
 * Retourne le nombre de notes pour le diplome dip
 */
int nbr_notes(Diplome dip);
