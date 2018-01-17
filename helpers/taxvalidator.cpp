#include "taxvalidator.h"

TaxValidator::TaxValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("taxCd", Tf::Required, false);
    //setRule("taxName", Tf::Required, false);
    //setRule("accountId", Tf::Required, false);
    //setRule("recoverableBool", Tf::Required, false);
    //setRule("archiveBool", Tf::Required, false);

 
    setRule("taxCd", Tf::MaxLength, 16);
    setRule("taxName", Tf::MaxLength, 64);

}
