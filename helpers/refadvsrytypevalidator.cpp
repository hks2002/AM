#include "refadvsrytypevalidator.h"

RefAdvsryTypeValidator::RefAdvsryTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("advsryTypeNameEn", Tf::Required, false);
    //setRule("advsryTypeNameZh", Tf::Required, false);
    //setRule("advsryTypeDesc", Tf::Required, false);

 
    setRule("advsryTypeNameEn", Tf::MaxLength, 64);
    setRule("advsryTypeNameZh", Tf::MaxLength, 64);

}
