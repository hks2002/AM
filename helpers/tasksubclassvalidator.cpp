#include "tasksubclassvalidator.h"

TaskSubclassValidator::TaskSubclassValidator() : TFormValidator()
{
    setRule("TaskSubclassCd", Tf::MaxLength, 16);
    setRule("TaskSubclassName", Tf::MaxLength, 64);
}
