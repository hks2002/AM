#include "buttonvalidator.h"

ButtonValidator::ButtonValidator() : TFormValidator()
{
    setRule("ButtonCd", Tf::MaxLength, 64);
    setRule("ButtonName", Tf::MaxLength, 64);
    setRule("ButtonTooltip", Tf::MaxLength, 256);
    setRule("Url", Tf::MaxLength, 256);
}
