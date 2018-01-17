#include "refmaintprgmstatusvalidator.h"

RefMaintPrgmStatusValidator::RefMaintPrgmStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("maintPrgmStatusNameEn", Tf::Required, false);
    //setRule("maintPrgmStatusNameZh", Tf::Required, false);
    //setRule("maintPrgmStatusDesc", Tf::Required, false);

 
    setRule("maintPrgmStatusNameEn", Tf::MaxLength, 64);
    setRule("maintPrgmStatusNameZh", Tf::MaxLength, 64);

}
