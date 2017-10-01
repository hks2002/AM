#include "quaractionvalidator.h"

QuarActionValidator::QuarActionValidator() : TFormValidator()
{
    setRule("ActionNote", Tf::MaxLength, 256);
}
