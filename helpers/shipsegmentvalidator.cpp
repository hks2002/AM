#include "shipsegmentvalidator.h"

ShipSegmentValidator::ShipSegmentValidator() : TFormValidator()
{
    setRule("SegmentStatusCd", Tf::MaxLength, 16);
    setRule("WaybillNo", Tf::MaxLength, 256);
}
