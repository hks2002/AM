#include "refreceivecondvalidator.h"

RefReceiveCondValidator::RefReceiveCondValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("receiveCondNameEn", Tf::Required, false);
    //setRule("receiveCondNameZh", Tf::Required, false);
    //setRule("receiveCondDesc", Tf::Required, false);

 
    setRule("receiveCondNameEn", Tf::MaxLength, 64);
    setRule("receiveCondNameZh", Tf::MaxLength, 64);

}
