#include "chargevalidator.h"

ChargeValidator::ChargeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("chargeCd", Tf::Required, false);
    //setRule("chargeName", Tf::Required, false);
    //setRule("accountId", Tf::Required, false);
    //setRule("recoverableBool", Tf::Required, false);
    //setRule("archiveBool", Tf::Required, false);

 
    setRule("chargeCd", Tf::MaxLength, 16);
    setRule("chargeName", Tf::MaxLength, 64);

}
