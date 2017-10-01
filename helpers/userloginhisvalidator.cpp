#include "userloginhisvalidator.h"

UserLoginHisValidator::UserLoginHisValidator() : TFormValidator()
{
    setRule("LoginComputer", Tf::MaxLength, 64);
}
