#include "evteventvalidator.h"

EvtEventValidator::EvtEventValidator() : TFormValidator()
{
    setRule("EventTypeCd", Tf::MaxLength, 16);
    setRule("EventReasonCd", Tf::MaxLength, 16);
    setRule("EventStatusCd", Tf::MaxLength, 16);
    setRule("EventName", Tf::MaxLength, 256);
}
