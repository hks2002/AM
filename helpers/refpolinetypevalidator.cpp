#include "refpolinetypevalidator.h"

RefPoLineTypeValidator::RefPoLineTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("poLineTypeNameEn", Tf::Required, false);
    //setRule("poLineTypeNameZh", Tf::Required, false);
    //setRule("poLineTypeDesc", Tf::Required, false);

 
    setRule("poLineTypeNameEn", Tf::MaxLength, 64);
    setRule("poLineTypeNameZh", Tf::MaxLength, 64);

}
