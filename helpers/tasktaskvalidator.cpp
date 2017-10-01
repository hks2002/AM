#include "tasktaskvalidator.h"

TaskTaskValidator::TaskTaskValidator() : TFormValidator()
{
    setRule("TaskDefStatusCd", Tf::MaxLength, 16);
    setRule("TaskCd", Tf::MaxLength, 64);
    setRule("TaskRefDesc", Tf::MaxLength, 64);
    setRule("TaskClassCd", Tf::MaxLength, 16);
    setRule("FirstSchedFromCd", Tf::MaxLength, 16);
    setRule("ReschedFromCd", Tf::MaxLength, 16);
    setRule("CreateWhenCd", Tf::MaxLength, 16);
    setRule("CancelWhenCd", Tf::MaxLength, 16);
}
