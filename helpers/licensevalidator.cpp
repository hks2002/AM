#include "licensevalidator.h"

LicenseValidator::LicenseValidator() : TFormValidator()
{
    setRule("LicenseCd", Tf::MaxLength, 16);
    setRule("LicenseName", Tf::MaxLength, 64);
    setRule("LicenseStatusCd", Tf::MaxLength, 16);
}
