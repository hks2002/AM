#include "locvalidator.h"

LocValidator::LocValidator() : TFormValidator()
{
    setRule("LocCd", Tf::MaxLength, 64);
    setRule("LocTypeCd", Tf::MaxLength, 16);
    setRule("LocName", Tf::MaxLength, 256);
}
