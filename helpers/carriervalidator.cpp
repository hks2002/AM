#include "carriervalidator.h"

CarrierValidator::CarrierValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("carrierCd", Tf::Required, false);
    //setRule("carrierName", Tf::Required, false);

 
    setRule("carrierCd", Tf::MaxLength, 16);
    setRule("carrierName", Tf::MaxLength, 64);

}
