#include "schedpartvalidator.h"

SchedPartValidator::SchedPartValidator() : TFormValidator()
{
    setRule("PartNote", Tf::MaxLength, 256);
    setRule("ReqActionCd", Tf::MaxLength, 16);
    setRule("SchedPartStatusCd", Tf::MaxLength, 16);
}
