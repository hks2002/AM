#include "refremovereasonvalidator.h"

RefRemoveReasonValidator::RefRemoveReasonValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("removeReasonNameEn", Tf::Required, false);
    //setRule("removeReasonNameZh", Tf::Required, false);
    //setRule("removeReasonDesc", Tf::Required, false);

 
    setRule("removeReasonNameEn", Tf::MaxLength, 64);
    setRule("removeReasonNameZh", Tf::MaxLength, 64);

}
