#include "rfqvendorvalidator.h"

RfqVendorValidator::RfqVendorValidator() : TFormValidator()
{
    setRule("PaymentTermsCd", Tf::MaxLength, 16);
    setRule("TradeTermCd", Tf::MaxLength, 16);
    setRule("VendorNote", Tf::MaxLength, 256);
}
