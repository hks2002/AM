#include "eqpassmblbomvalidator.h"

EqpAssmblBomValidator::EqpAssmblBomValidator() : TFormValidator()
{
    setRule("AssmblBomCd", Tf::MaxLength, 16);
    setRule("AssmblBomName", Tf::MaxLength, 256);
    setRule("BomClassCd", Tf::MaxLength, 16);
}
