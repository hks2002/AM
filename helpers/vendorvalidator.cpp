#include "vendorvalidator.h"

VendorValidator::VendorValidator() : TFormValidator()
{
    setRule("VendorCd", Tf::MaxLength, 16);
    setRule("VendorName", Tf::MaxLength, 64);
    setRule("CertCd", Tf::MaxLength, 16);
    setRule("ReceiveNote", Tf::MaxLength, 256);
    setRule("VendorNote", Tf::MaxLength, 256);
    setRule("VendorStatusCd", Tf::MaxLength, 16);
}
