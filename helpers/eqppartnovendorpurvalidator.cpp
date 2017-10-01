#include "eqppartnovendorpurvalidator.h"

EqpPartNoVendorPurValidator::EqpPartNoVendorPurValidator() : TFormValidator()
{
    setRule("PartNoVendor", Tf::MaxLength, 64);
}
