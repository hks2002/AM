#include "refxfertypevalidator.h"

RefXferTypeValidator::RefXferTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("xferTypeNameEn", Tf::Required, false);
    //setRule("xferTypeNameZh", Tf::Required, false);
    //setRule("xferTypeDesc", Tf::Required, false);

 
    setRule("xferTypeNameEn", Tf::MaxLength, 64);
    setRule("xferTypeNameZh", Tf::MaxLength, 64);

}
