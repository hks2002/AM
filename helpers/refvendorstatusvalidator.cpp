#include "refvendorstatusvalidator.h"

RefVendorStatusValidator::RefVendorStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("vendorStatusNameEn", Tf::Required, false);
    //setRule("vendorStatusNameZh", Tf::Required, false);
    //setRule("vendorStatusDesc", Tf::Required, false);

 
    setRule("vendorStatusNameEn", Tf::MaxLength, 64);
    setRule("vendorStatusNameZh", Tf::MaxLength, 64);

}
