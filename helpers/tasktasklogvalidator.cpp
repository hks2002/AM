#include "tasktasklogvalidator.h"

TaskTaskLogValidator::TaskTaskLogValidator() : TFormValidator()
{
    setRule("LogActionCd", Tf::MaxLength, 16);
}
