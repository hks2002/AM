#include "eqppartnotechdatavalidator.h"

EqpPartNoTechDataValidator::EqpPartNoTechDataValidator() : TFormValidator()
{
    setRule("MesurTypeCd", Tf::MaxLength, 16);
}
