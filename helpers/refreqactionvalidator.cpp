#include "refreqactionvalidator.h"

RefReqActionValidator::RefReqActionValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("reqActionNameEn", Tf::Required, false);
    //setRule("reqActionNameZh", Tf::Required, false);
    //setRule("reqActionDesc", Tf::Required, false);

 
    setRule("reqActionNameEn", Tf::MaxLength, 64);
    setRule("reqActionNameZh", Tf::MaxLength, 64);

}
