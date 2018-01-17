#include "refwarrantystatusvalidator.h"

RefWarrantyStatusValidator::RefWarrantyStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("warrantyStatusNameEn", Tf::Required, false);
    //setRule("warrantyStatusNameZh", Tf::Required, false);
    //setRule("warrantyStatusDesc", Tf::Required, false);

 
    setRule("warrantyStatusNameEn", Tf::MaxLength, 64);
    setRule("warrantyStatusNameZh", Tf::MaxLength, 64);

}
