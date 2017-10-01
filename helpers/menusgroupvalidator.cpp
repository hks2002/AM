#include "menusgroupvalidator.h"

MenusGroupValidator::MenusGroupValidator() : TFormValidator()
{
    setRule("MenusGroupCd", Tf::MaxLength, 16);
    setRule("MenusGroupName", Tf::MaxLength, 64);
    setRule("MenusGroupTooltip", Tf::MaxLength, 256);
}
