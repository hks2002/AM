#include "taskoriginatorvalidator.h"

TaskOriginatorValidator::TaskOriginatorValidator() : TFormValidator()
{
    setRule("TaskOriginatorCd", Tf::MaxLength, 16);
    setRule("TaskOriginatorName", Tf::MaxLength, 64);
}
