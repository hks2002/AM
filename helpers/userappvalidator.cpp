#include "userappvalidator.h"

UserAppValidator::UserAppValidator() : TFormValidator()
{
    setRule("UserName", Tf::MaxLength, 16);
    setRule("FullName", Tf::MaxLength, 64);
    setRule("HrCd", Tf::MaxLength, 16);
    setRule("Password", Tf::MaxLength, 256);
    setRule("EmailAddr", Tf::MaxLength, 64);
}
