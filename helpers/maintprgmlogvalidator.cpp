#include "maintprgmlogvalidator.h"

MaintPrgmLogValidator::MaintPrgmLogValidator() : TFormValidator()
{
    setRule("LogActionCd", Tf::MaxLength, 16);
}
