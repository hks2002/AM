#include "refclaimtovalidator.h"

RefClaimToValidator::RefClaimToValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("claimToNameEn", Tf::Required, false);
    //setRule("claimToNameZh", Tf::Required, false);
    //setRule("claimToDesc", Tf::Required, false);

 
    setRule("claimToNameEn", Tf::MaxLength, 64);
    setRule("claimToNameZh", Tf::MaxLength, 64);

}
