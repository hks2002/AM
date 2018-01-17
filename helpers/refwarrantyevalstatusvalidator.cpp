#include "refwarrantyevalstatusvalidator.h"

RefWarrantyEvalStatusValidator::RefWarrantyEvalStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("warrantyEvalStatusNameEn", Tf::Required, false);
    //setRule("warrantyEvalStatusNameZh", Tf::Required, false);
    //setRule("warrantyEvalStatusDesc", Tf::Required, false);

 
    setRule("warrantyEvalStatusNameEn", Tf::MaxLength, 64);
    setRule("warrantyEvalStatusNameZh", Tf::MaxLength, 64);

}
