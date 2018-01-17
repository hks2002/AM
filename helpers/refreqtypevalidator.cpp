#include "refreqtypevalidator.h"

RefReqTypeValidator::RefReqTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("reqTypeNameEn", Tf::Required, false);
    //setRule("reqTypeNameZh", Tf::Required, false);
    //setRule("reqTypeDesc", Tf::Required, false);

 
    setRule("reqTypeNameEn", Tf::MaxLength, 64);
    setRule("reqTypeNameZh", Tf::MaxLength, 64);

}
