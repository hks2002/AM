#include "invcurrusagevalidator.h"

InvCurrUsageValidator::InvCurrUsageValidator() : TFormValidator()
{
    setRule("EngUnitCd", Tf::MaxLength, 16);
}
