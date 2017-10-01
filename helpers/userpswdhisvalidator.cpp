#include "userpswdhisvalidator.h"

UserPswdHisValidator::UserPswdHisValidator() : TFormValidator()
{
    setRule("Password", Tf::MaxLength, 256);
}
