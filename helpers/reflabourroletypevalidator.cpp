#include "reflabourroletypevalidator.h"

RefLabourRoleTypeValidator::RefLabourRoleTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("labourRoleTypeNameEn", Tf::Required, false);
    //setRule("labourRoleTypeNameZh", Tf::Required, false);
    //setRule("labourRoleTypeDesc", Tf::Required, false);

 
    setRule("labourRoleTypeNameEn", Tf::MaxLength, 64);
    setRule("labourRoleTypeNameZh", Tf::MaxLength, 64);

}
