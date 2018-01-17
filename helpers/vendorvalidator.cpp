#include "vendorvalidator.h"

VendorValidator::VendorValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("vendorCd", Tf::Required, false);
    //setRule("vendorName", Tf::Required, false);
    //setRule("certCd", Tf::Required, false);
    //setRule("certExpiryDt", Tf::Required, false);
    //setRule("currencyId", Tf::Required, false);
    //setRule("receiveNote", Tf::Required, false);
    //setRule("vendorNote", Tf::Required, false);
    //setRule("vendorStatusCd", Tf::Required, false);
    //setRule("warningDesc", Tf::Required, false);

 
    setRule("vendorCd", Tf::MaxLength, 16);
    setRule("vendorName", Tf::MaxLength, 64);
    setRule("certCd", Tf::MaxLength, 16);
    setRule("receiveNote", Tf::MaxLength, 256);
    setRule("vendorNote", Tf::MaxLength, 256);
    setRule("vendorStatusCd", Tf::MaxLength, 16);

}
