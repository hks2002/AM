#include "refschedpartstatusvalidator.h"

RefSchedPartStatusValidator::RefSchedPartStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("schedPartStatusNameEn", Tf::Required, false);
    //setRule("schedPartStatusNameZh", Tf::Required, false);
    //setRule("schedPartStatusDesc", Tf::Required, false);

 
    setRule("schedPartStatusNameEn", Tf::MaxLength, 64);
    setRule("schedPartStatusNameZh", Tf::MaxLength, 64);

}
