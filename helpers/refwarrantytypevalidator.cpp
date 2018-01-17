#include "refwarrantytypevalidator.h"

RefWarrantyTypeValidator::RefWarrantyTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("warrantyTypeNameEn", Tf::Required, false);
    //setRule("warrantyTypeNameZh", Tf::Required, false);
    //setRule("warrantyTypeDesc", Tf::Required, false);

 
    setRule("warrantyTypeNameEn", Tf::MaxLength, 64);
    setRule("warrantyTypeNameZh", Tf::MaxLength, 64);

}
