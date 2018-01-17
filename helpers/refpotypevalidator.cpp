#include "refpotypevalidator.h"

RefPoTypeValidator::RefPoTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("poTypeNameEn", Tf::Required, false);
    //setRule("poTypeNameZh", Tf::Required, false);
    //setRule("poTypeDesc", Tf::Required, false);

 
    setRule("poTypeNameEn", Tf::MaxLength, 64);
    setRule("poTypeNameZh", Tf::MaxLength, 64);

}
