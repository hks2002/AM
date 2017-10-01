#include "orgvendorapprovalvalidator.h"

OrgVendorApprovalValidator::OrgVendorApprovalValidator() : TFormValidator()
{
    setRule("VendorTypeCd", Tf::MaxLength, 16);
    setRule("ApprovalCd", Tf::MaxLength, 16);
}
