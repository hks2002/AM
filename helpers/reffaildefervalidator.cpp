#include "reffaildefervalidator.h"

RefFailDeferValidator::RefFailDeferValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("failDeferNameEn", Tf::Required, false);
    //setRule("failDeferNameZh", Tf::Required, false);
    //setRule("failDeferDesc", Tf::Required, false);

 
    setRule("failDeferNameEn", Tf::MaxLength, 64);
    setRule("failDeferNameZh", Tf::MaxLength, 64);

}
