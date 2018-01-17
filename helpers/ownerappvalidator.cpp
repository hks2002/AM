#include "ownerappvalidator.h"

OwnerAppValidator::OwnerAppValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("ownerTypeCd", Tf::Required, false);
    //setRule("orgId", Tf::Required, false);
    //setRule("vendorId", Tf::Required, false);

 
    setRule("ownerTypeCd", Tf::MaxLength, 16);

}
