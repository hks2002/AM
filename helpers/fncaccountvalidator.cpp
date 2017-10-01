#include "fncaccountvalidator.h"

FncAccountValidator::FncAccountValidator() : TFormValidator()
{
    setRule("AccountCd", Tf::MaxLength, 16);
    setRule("AccountTypeCd", Tf::MaxLength, 16);
    setRule("AccountName", Tf::MaxLength, 256);
    setRule("ExtKey", Tf::MaxLength, 256);
}
