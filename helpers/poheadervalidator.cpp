#include "poheadervalidator.h"

PoHeaderValidator::PoHeaderValidator() : TFormValidator()
{
    setRule("PoTypeCd", Tf::MaxLength, 16);
    setRule("ReqPriorityCd", Tf::MaxLength, 16);
    setRule("ReqTypeCd", Tf::MaxLength, 16);
    setRule("BorrowRateCd", Tf::MaxLength, 16);
    setRule("PaymentTermsCd", Tf::MaxLength, 16);
    setRule("TradeTermCd", Tf::MaxLength, 16);
    setRule("ShippingPoint", Tf::MaxLength, 256);
    setRule("NoteToVendor", Tf::MaxLength, 256);
    setRule("NoteToReceiver", Tf::MaxLength, 256);
}
