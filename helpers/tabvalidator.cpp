#include "tabvalidator.h"

TabValidator::TabValidator() : TFormValidator()
{
    setRule("TabCd", Tf::MaxLength, 64);
    setRule("TabName", Tf::MaxLength, 64);
    //setRule("TabTooltip", Tf::MaxLength, 256);
    //setRule("Url", Tf::MaxLength, 256);
}
