#include "schedrmvdpartvalidator.h"

SchedRmvdPartValidator::SchedRmvdPartValidator() : TFormValidator()
{
    setRule("SerialNoOem", Tf::MaxLength, 64);
    setRule("RemoveReasonCd", Tf::MaxLength, 16);
}
