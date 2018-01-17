#include "refcreatewhenvalidator.h"

RefCreateWhenValidator::RefCreateWhenValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("createWhenNameEn", Tf::Required, false);
    //setRule("createWhenNameZh", Tf::Required, false);
    //setRule("createWhenDesc", Tf::Required, false);

 
    setRule("createWhenNameEn", Tf::MaxLength, 64);
    setRule("createWhenNameZh", Tf::MaxLength, 64);

}
