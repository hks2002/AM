#include "rfqlinevendorvalidator.h"

RfqLineVendorValidator::RfqLineVendorValidator() : TFormValidator()
{
    setRule("ReceiveCondCd", Tf::MaxLength, 16);
    setRule("NoteToVendor", Tf::MaxLength, 256);
    setRule("DocRefDesc", Tf::MaxLength, 64);
}
