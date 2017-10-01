#include "schedtoolvalidator.h"

SchedToolValidator::SchedToolValidator() : TFormValidator()
{
    setRule("PartNote", Tf::MaxLength, 256);
}
