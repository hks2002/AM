#include "fnctcodevalidator.h"

FncTcodeValidator::FncTcodeValidator() : TFormValidator()
{
    setRule("TcodeCd", Tf::MaxLength, 16);
    setRule("TcodeName", Tf::MaxLength, 256);
}
