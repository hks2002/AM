#include "refloctypevalidator.h"

RefLocTypeValidator::RefLocTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("locTypeNameEn", Tf::Required, false);
    //setRule("locTypeNameZh", Tf::Required, false);
    //setRule("locTypeDesc", Tf::Required, false);

 
    setRule("locTypeNameEn", Tf::MaxLength, 64);
    setRule("locTypeNameZh", Tf::MaxLength, 64);

}
