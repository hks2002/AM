#include "refownertypevalidator.h"

RefOwnerTypeValidator::RefOwnerTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("ownerTypeNameEn", Tf::Required, false);
    //setRule("ownerTypeNameZh", Tf::Required, false);
    //setRule("ownerTypeDesc", Tf::Required, false);

 
    setRule("ownerTypeNameEn", Tf::MaxLength, 64);
    setRule("ownerTypeNameZh", Tf::MaxLength, 64);

}
