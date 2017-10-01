#include "schedinstpartvalidator.h"

SchedInstPartValidator::SchedInstPartValidator() : TFormValidator()
{
    setRule("SerialNoOem", Tf::MaxLength, 64);
}
