#include "reflabourstagevalidator.h"

RefLabourStageValidator::RefLabourStageValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("labourStageNameEn", Tf::Required, false);
    //setRule("labourStageNameZh", Tf::Required, false);
    //setRule("labourStageDesc", Tf::Required, false);

 
    setRule("labourStageNameEn", Tf::MaxLength, 64);
    setRule("labourStageNameZh", Tf::MaxLength, 64);

}
