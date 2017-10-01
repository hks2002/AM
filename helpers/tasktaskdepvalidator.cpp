#include "tasktaskdepvalidator.h"

TaskTaskDepValidator::TaskTaskDepValidator() : TFormValidator()
{
    setRule("TaskDepActionCd", Tf::MaxLength, 16);
}
