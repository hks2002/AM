#include "rfqlinevalidator.h"

RfqLineValidator::RfqLineValidator() : TFormValidator()
{
    setRule("LineDesc", Tf::MaxLength, 256);
    setRule("ReqPriorityCd", Tf::MaxLength, 16);
}
