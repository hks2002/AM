#include "evtvendorpotypevalidator.h"

EvtVendorPoTypeValidator::EvtVendorPoTypeValidator() : TFormValidator()
{
    setRule("PoTypeCd", Tf::MaxLength, 16);
}
