#include "reflabourrolestatusvalidator.h"

RefLabourRoleStatusValidator::RefLabourRoleStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("labourRoleStatusNameEn", Tf::Required, false);
    //setRule("labourRoleStatusNameZh", Tf::Required, false);
    //setRule("labourRoleStatusDesc", Tf::Required, false);

 
    setRule("labourRoleStatusNameEn", Tf::MaxLength, 64);
    setRule("labourRoleStatusNameZh", Tf::MaxLength, 64);

}
