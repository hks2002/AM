#include "taxvalidator.h"

TaxValidator::TaxValidator() : TFormValidator()
{
    setRule("TaxCd", Tf::MaxLength, 16);
    setRule("TaxName", Tf::MaxLength, 64);
}
