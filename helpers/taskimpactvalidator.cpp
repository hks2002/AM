#include "taskimpactvalidator.h"

TaskImpactValidator::TaskImpactValidator() : TFormValidator()
{
    setRule("MesurTypeCd", Tf::MaxLength, 16);
}
