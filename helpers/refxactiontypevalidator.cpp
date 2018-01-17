#include "refxactiontypevalidator.h"

RefXactionTypeValidator::RefXactionTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("xactionTypeNameEn", Tf::Required, false);
    //setRule("xactionTypeNameZh", Tf::Required, false);
    //setRule("xactionTypeDesc", Tf::Required, false);

 
    setRule("xactionTypeNameEn", Tf::MaxLength, 64);
    setRule("xactionTypeNameZh", Tf::MaxLength, 64);

}
