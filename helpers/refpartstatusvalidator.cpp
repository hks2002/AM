#include "refpartstatusvalidator.h"

RefPartStatusValidator::RefPartStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("partStatusNameEn", Tf::Required, false);
    //setRule("partStatusNameZh", Tf::Required, false);
    //setRule("partStatusDesc", Tf::Required, false);

 
    setRule("partStatusNameEn", Tf::MaxLength, 64);
    setRule("partStatusNameZh", Tf::MaxLength, 64);

}
