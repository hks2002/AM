#include "refwarrantypriorityvalidator.h"

RefWarrantyPriorityValidator::RefWarrantyPriorityValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("warrantyPriorityNameEn", Tf::Required, false);
    //setRule("warrantyPriorityNameZh", Tf::Required, false);
    //setRule("warrantyPriorityDesc", Tf::Required, false);

 
    setRule("warrantyPriorityNameEn", Tf::MaxLength, 64);
    setRule("warrantyPriorityNameZh", Tf::MaxLength, 64);

}
