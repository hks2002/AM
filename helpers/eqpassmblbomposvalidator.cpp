#include "eqpassmblbomposvalidator.h"

EqpAssmblBomPosValidator::EqpAssmblBomPosValidator() : TFormValidator()
{
    setRule("EqpPosCd", Tf::MaxLength, 16);
}
