#include "refparttypevalidator.h"

RefPartTypeValidator::RefPartTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("partTypeNameEn", Tf::Required, false);
    //setRule("partTypeNameZh", Tf::Required, false);
    //setRule("partTypeDesc", Tf::Required, false);

 
    setRule("partTypeNameEn", Tf::MaxLength, 64);
    setRule("partTypeNameZh", Tf::MaxLength, 64);

}
