#include "refownbyvalidator.h"

RefOwnByValidator::RefOwnByValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("ownByNameEn", Tf::Required, false);
    //setRule("ownByNameZh", Tf::Required, false);
    //setRule("ownByDesc", Tf::Required, false);

 
    setRule("ownByNameEn", Tf::MaxLength, 64);
    setRule("ownByNameZh", Tf::MaxLength, 64);

}
