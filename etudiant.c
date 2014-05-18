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
  #define map(a) if(!strcmp(a, #a)) return a

  map(DUT);
  map(DEUG);
  map(DEUST);
  map(LICENCE);
  map(MAITRISE);
  map(MASTER);
  map(CPGE);
}
