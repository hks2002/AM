#include "refwarrantysubtypevalidator.h"

RefWarrantySubtypeValidator::RefWarrantySubtypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("warrantySubtypeNameEn", Tf::Required, false);
    //setRule("warrantySubtypeNameZh", Tf::Required, false);
    //setRule("warrantySubtypeDesc", Tf::Required, false);

 
    setRule("warrantySubtypeNameEn", Tf::MaxLength, 64);
    setRule("warrantySubtypeNameZh", Tf::MaxLength, 64);

}
