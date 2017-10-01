#include "eqpassmblbomlogvalidator.h"

EqpAssmblBomLogValidator::EqpAssmblBomLogValidator() : TFormValidator()
{
    setRule("LogActionCd", Tf::MaxLength, 16);
}
