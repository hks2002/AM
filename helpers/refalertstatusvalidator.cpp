#include "refalertstatusvalidator.h"

RefAlertStatusValidator::RefAlertStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("alertStatusNameEn", Tf::Required, false);
    //setRule("alertStatusNameZh", Tf::Required, false);
    //setRule("alertStatusDesc", Tf::Required, false);

 
    setRule("alertStatusNameEn", Tf::MaxLength, 64);
    setRule("alertStatusNameZh", Tf::MaxLength, 64);

}
