#include "evtscheddeadvalidator.h"

EvtSchedDeadValidator::EvtSchedDeadValidator() : TFormValidator()
{
    setRule("SchedFromCd", Tf::MaxLength, 16);
}
