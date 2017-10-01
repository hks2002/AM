#include "fncxactionlogvalidator.h"

FncXactionLogValidator::FncXactionLogValidator() : TFormValidator()
{
    setRule("XactionTypeCd", Tf::MaxLength, 16);
}
