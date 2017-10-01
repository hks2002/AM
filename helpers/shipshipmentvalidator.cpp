#include "shipshipmentvalidator.h"

ShipShipmentValidator::ShipShipmentValidator() : TFormValidator()
{
    setRule("ShipmentTypeCd", Tf::MaxLength, 16);
    setRule("WaybillNo", Tf::MaxLength, 64);
    setRule("FlightNo", Tf::MaxLength, 16);
    setRule("ReturnAuthNo", Tf::MaxLength, 64);
    setRule("WeightUnit", Tf::MaxLength, 16);
    setRule("HeightUnit", Tf::MaxLength, 16);
    setRule("LengthUnit", Tf::MaxLength, 16);
    setRule("WidthUnit", Tf::MaxLength, 16);
}
