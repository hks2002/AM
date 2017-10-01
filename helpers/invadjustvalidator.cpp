#include "invadjustvalidator.h"

InvAdjustValidator::InvAdjustValidator() : TFormValidator()
{
    setRule("XactionTypeCd", Tf::MaxLength, 16);
    setRule("UserNote", Tf::MaxLength, 256);
}
