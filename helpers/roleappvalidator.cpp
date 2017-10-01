#include "roleappvalidator.h"

RoleAppValidator::RoleAppValidator() : TFormValidator()
{
    setRule("RoleCd", Tf::MaxLength, 16);
    setRule("RoleName", Tf::MaxLength, 64);
}
