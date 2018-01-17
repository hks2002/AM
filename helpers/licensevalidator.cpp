#include "licensevalidator.h"

LicenseValidator::LicenseValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("licenseCd", Tf::Required, false);
    //setRule("licenseName", Tf::Required, false);
    //setRule("licenseDesc", Tf::Required, false);
    //setRule("licenseStatusCd", Tf::Required, false);

 
    setRule("licenseCd", Tf::MaxLength, 16);
    setRule("licenseName", Tf::MaxLength, 64);
    setRule("licenseStatusCd", Tf::MaxLength, 16);

}
