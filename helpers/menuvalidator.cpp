#include "menuvalidator.h"

MenuValidator::MenuValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("menuCd", Tf::Required, false);
    //setRule("menuNameZh", Tf::Required, false);
    //setRule("menuNameEn", Tf::Required, false);
    setRule("menuTooltip", Tf::Required, false);


    setRule("menuCd", Tf::MaxLength, 64);
    setRule("menuNameZh", Tf::MaxLength, 64);
    setRule("menuNameEn", Tf::MaxLength, 64);
    setRule("menuTooltip", Tf::MaxLength, 256);

}
