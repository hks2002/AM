#include "taskpartreqvalidator.h"

TaskPartReqValidator::TaskPartReqValidator() : TFormValidator()
{
    setRule("ReqActionCd", Tf::MaxLength, 16);
    setRule("RemoveReasonCd", Tf::MaxLength, 16);
    setRule("ReqPriorityCd", Tf::MaxLength, 16);
}
