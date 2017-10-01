#include "schedimpactvalidator.h"

SchedImpactValidator::SchedImpactValidator() : TFormValidator()
{
    setRule("MesurTypeCd", Tf::MaxLength, 16);
}
