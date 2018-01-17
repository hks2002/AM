#include "roleappvalidator.h"

RoleAppValidator::RoleAppValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("roleCd", Tf::Required, false);
    //setRule("roleNameZh", Tf::Required, false);
    //setRule("roleNameEn", Tf::Required, false);

 
    setRule("roleCd", Tf::MaxLength, 16);
    setRule("roleNameZh", Tf::MaxLength, 64);
    setRule("roleNameEn", Tf::MaxLength, 64);

}
