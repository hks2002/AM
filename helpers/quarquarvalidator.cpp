#include "quarquarvalidator.h"

QuarQuarValidator::QuarQuarValidator() : TFormValidator()
{
    setRule("QuarNote", Tf::MaxLength, 256);
}
