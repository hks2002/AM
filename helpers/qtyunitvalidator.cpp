#include "qtyunitvalidator.h"

QtyUnitValidator::QtyUnitValidator() : TFormValidator()
{
    setRule("QtyUnitCd", Tf::MaxLength, 16);
    setRule("QtyUnitName", Tf::MaxLength, 64);
}
