#include "refreqpriorityvalidator.h"

RefReqPriorityValidator::RefReqPriorityValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("reqPriorityNameEn", Tf::Required, false);
    //setRule("reqPriorityNameZh", Tf::Required, false);
    //setRule("reqPriorityDesc", Tf::Required, false);

 
    setRule("reqPriorityNameEn", Tf::MaxLength, 64);
    setRule("reqPriorityNameZh", Tf::MaxLength, 64);

}
