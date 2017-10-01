#include "eqppartnologvalidator.h"

EqpPartNoLogValidator::EqpPartNoLogValidator() : TFormValidator()
{
    setRule("LogActionCd", Tf::MaxLength, 16);
}
