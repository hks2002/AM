#include "carriervalidator.h"

CarrierValidator::CarrierValidator() : TFormValidator()
{
    setRule("CarrierCd", Tf::MaxLength, 16);
    setRule("CarrierName", Tf::MaxLength, 64);
}
