#include "refpricetypevalidator.h"

RefPriceTypeValidator::RefPriceTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("priceTypeNameEn", Tf::Required, false);
    //setRule("priceTypeNameZh", Tf::Required, false);
    //setRule("priceTypeDesc", Tf::Required, false);

 
    setRule("priceTypeNameEn", Tf::MaxLength, 64);
    setRule("priceTypeNameZh", Tf::MaxLength, 64);

}
