#include "etudiant.h"
#include <string.h>

int nbr_notes(Diplome dip)
{
  switch(dip)
    {
      case DUT:
      case DEUG:
      case DEUST:               return 4;
      case LICENCE:             return 6;
      case MAITRISE:            return 8;
      case MASTER:              return 10;
      default /* CPGE*/ :       return 1;
    }
}

Diplome str_to_dipl(char *str)
{
  if(!strcmp(str, "DUT"))      return DUT;
  if(!strcmp(str, "DEUG"))     return DEUG;
  if(!strcmp(str, "DEUST"))    return DEUST;
  if(!strcmp(str, "LICENCE"))  return LICENCE;
  if(!strcmp(str, "MAITRISE")) return MAITRISE;
  if(!strcmp(str, "MASTER"))   return MASTER;
  return CPGE;
}
