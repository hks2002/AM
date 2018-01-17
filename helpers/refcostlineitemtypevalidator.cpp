#include "refcostlineitemtypevalidator.h"

RefCostLineItemTypeValidator::RefCostLineItemTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("costLineItemTypeNameEn", Tf::Required, false);
    //setRule("costLineItemTypeNameZh", Tf::Required, false);
    //setRule("costLineItemTypeDesc", Tf::Required, false);

 
    setRule("costLineItemTypeNameEn", Tf::MaxLength, 64);
    setRule("costLineItemTypeNameZh", Tf::MaxLength, 64);

}
