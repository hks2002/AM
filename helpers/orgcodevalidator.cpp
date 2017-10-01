#include "orgcodevalidator.h"

OrgCodeValidator::OrgCodeValidator() : TFormValidator()
{
    setRule("IcaoCd", Tf::MaxLength, 16);
    setRule("IataCd", Tf::MaxLength, 16);
    setRule("CallsignCd", Tf::MaxLength, 16);
}
