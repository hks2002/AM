#include "eqppartnovendorpricevalidator.h"

EqpPartNoVendorPriceValidator::EqpPartNoVendorPriceValidator() : TFormValidator()
{
    setRule("PriceTypeCd", Tf::MaxLength, 16);
    setRule("DocRefDesc", Tf::MaxLength, 64);
}
