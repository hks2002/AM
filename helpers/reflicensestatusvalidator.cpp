#include "reflicensestatusvalidator.h"

RefLicenseStatusValidator::RefLicenseStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("licenseStatusNameEn", Tf::Required, false);
    //setRule("licenseStatusNameZh", Tf::Required, false);
    //setRule("licenseStatusDesc", Tf::Required, false);

 
    setRule("licenseStatusNameEn", Tf::MaxLength, 64);
    setRule("licenseStatusNameZh", Tf::MaxLength, 64);

}
