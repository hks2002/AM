#include "eqppartnoreliabvalidator.h"

EqpPartNoReliabValidator::EqpPartNoReliabValidator() : TFormValidator()
{
    setRule("EngUnitCd", Tf::MaxLength, 16);
}
