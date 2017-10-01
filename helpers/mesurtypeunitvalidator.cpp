#include "mesurtypeunitvalidator.h"

MesurTypeUnitValidator::MesurTypeUnitValidator() : TFormValidator()
{
    setRule("MesurTypeCd", Tf::MaxLength, 16);
}
