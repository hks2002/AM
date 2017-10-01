#include "actionappvalidator.h"

ActionAppValidator::ActionAppValidator() : TFormValidator()
{
    setRule("ActionCd", Tf::MaxLength, 128);
    setRule("ActionName", Tf::MaxLength, 256);
    setRule("ActionTooltip", Tf::MaxLength, 256);
    setRule("ActionType", Tf::MaxLength, 256);
    setRule("Url", Tf::MaxLength, 256);
}
