#include "refaccounttypevalidator.h"

RefAccountTypeValidator::RefAccountTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("accountTypeNameEn", Tf::Required, false);
    //setRule("accountTypeNameZh", Tf::Required, false);
    //setRule("accountTypeDesc", Tf::Required, false);

 
    setRule("accountTypeNameEn", Tf::MaxLength, 64);
    setRule("accountTypeNameZh", Tf::MaxLength, 64);

}
