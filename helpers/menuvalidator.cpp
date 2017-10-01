#include "menuvalidator.h"

MenuValidator::MenuValidator() : TFormValidator()
{
    setRule("MenuCd", Tf::MaxLength, 64);
    setRule("MenuName", Tf::MaxLength, 64);
    setRule("MenuTooltip", Tf::MaxLength, 256);
    setRule("Url", Tf::MaxLength, 256);
}
