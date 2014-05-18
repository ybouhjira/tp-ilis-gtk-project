#include "etudiant.h"

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
