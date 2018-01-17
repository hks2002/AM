#include "tabvalidator.h"

TabValidator::TabValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("tabCd", Tf::Required, false);
    //setRule("tabNameZh", Tf::Required, false);
    //setRule("tabNameEn", Tf::Required, false);
    setRule("tabTooltip", Tf::Required, false);

    setRule("tabCd", Tf::MaxLength, 64);
    setRule("tabNameZh", Tf::MaxLength, 64);
    setRule("tabNameEn", Tf::MaxLength, 64);
    setRule("tabTooltip", Tf::MaxLength, 256);

}
