#include "orgvalidator.h"

OrgValidator::OrgValidator() : TFormValidator()
{
    setRule("OrgCd", Tf::MaxLength, 16);
}
