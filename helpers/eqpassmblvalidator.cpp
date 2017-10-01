#include "eqpassmblvalidator.h"

EqpAssmblValidator::EqpAssmblValidator() : TFormValidator()
{
    setRule("AssmblCd", Tf::MaxLength, 16);
    setRule("AssmblClassCd", Tf::MaxLength, 16);
    setRule("AssmblName", Tf::MaxLength, 64);
}
