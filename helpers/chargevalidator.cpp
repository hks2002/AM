#include "chargevalidator.h"

ChargeValidator::ChargeValidator() : TFormValidator()
{
    setRule("ChargeCd", Tf::MaxLength, 16);
    setRule("ChargeName", Tf::MaxLength, 64);
}
