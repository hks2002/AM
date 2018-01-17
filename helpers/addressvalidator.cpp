#include "addressvalidator.h"

AddressValidator::AddressValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("addressLine1", Tf::Required, false);
    //setRule("addressLine2", Tf::Required, false);
    //setRule("cityId", Tf::Required, false);
    //setRule("countryId", Tf::Required, false);
    //setRule("provinceId", Tf::Required, false);
    //setRule("zipCd", Tf::Required, false);

 
    setRule("addressLine1", Tf::MaxLength, 256);
    setRule("addressLine2", Tf::MaxLength, 256);
    setRule("zipCd", Tf::MaxLength, 16);

}
