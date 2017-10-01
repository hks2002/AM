#include "mesurunitvalidator.h"

MesurUnitValidator::MesurUnitValidator() : TFormValidator()
{
    setRule("MesurUnitCd", Tf::MaxLength, 16);
    setRule("MesurUnitName", Tf::MaxLength, 64);
}
