#include "refvendortypevalidator.h"

RefVendorTypeValidator::RefVendorTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("vendorTypeNameEn", Tf::Required, false);
    //setRule("vendorTypeNameZh", Tf::Required, false);
    //setRule("vendorTypeDesc", Tf::Required, false);

 
    setRule("vendorTypeNameEn", Tf::MaxLength, 64);
    setRule("vendorTypeNameZh", Tf::MaxLength, 64);

}
