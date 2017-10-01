#include "shipshipmentlinevalidator.h"

ShipShipmentLineValidator::ShipShipmentLineValidator() : TFormValidator()
{
    setRule("InvCondCd", Tf::MaxLength, 16);
    setRule("SerialNoOem", Tf::MaxLength, 64);
    setRule("RcvPriorityCd", Tf::MaxLength, 16);
}
