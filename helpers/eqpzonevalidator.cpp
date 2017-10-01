#include "eqpzonevalidator.h"

EqpZoneValidator::EqpZoneValidator() : TFormValidator()
{
    setRule("ZoneCd", Tf::MaxLength, 16);
    setRule("DescDesc", Tf::MaxLength, 256);
}
