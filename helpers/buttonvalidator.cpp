#include "buttonvalidator.h"

ButtonValidator::ButtonValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("buttonCd", Tf::Required, false);
    //setRule("buttonNameZh", Tf::Required, false);
    //setRule("buttonNameEn", Tf::Required, false);
    setRule("buttonTooltip", Tf::Required, false);


    setRule("buttonCd", Tf::MaxLength, 64);
    setRule("buttonNameZh", Tf::MaxLength, 64);
    setRule("buttonNameEn", Tf::MaxLength, 64);
    setRule("buttonTooltip", Tf::MaxLength, 256);

}
