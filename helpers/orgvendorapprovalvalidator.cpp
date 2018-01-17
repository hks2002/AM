#include "orgvendorapprovalvalidator.h"

OrgVendorApprovalValidator::OrgVendorApprovalValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("approvalCd", Tf::Required, false);
    //setRule("approvalExpiryDt", Tf::Required, false);
    //setRule("activeBool", Tf::Required, false);

 
    setRule("approvalCd", Tf::MaxLength, 16);

}
