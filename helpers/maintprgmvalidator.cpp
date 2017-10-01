#include "maintprgmvalidator.h"

MaintPrgmValidator::MaintPrgmValidator() : TFormValidator()
{
    setRule("MaintPrgmCd", Tf::MaxLength, 16);
    setRule("MaintPrgmStatusCd", Tf::MaxLength, 16);
}
