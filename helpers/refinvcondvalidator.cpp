#include "refinvcondvalidator.h"

RefInvCondValidator::RefInvCondValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("invCondNameEn", Tf::Required, false);
    //setRule("invCondNameZh", Tf::Required, false);
    //setRule("invCondDesc", Tf::Required, false);

 
    setRule("invCondNameEn", Tf::MaxLength, 64);
    setRule("invCondNameZh", Tf::MaxLength, 64);

}
