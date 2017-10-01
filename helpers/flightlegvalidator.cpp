#include "flightlegvalidator.h"

FlightLegValidator::FlightLegValidator() : TFormValidator()
{
    setRule("LegNo", Tf::MaxLength, 16);
    setRule("FlightLegStatusCd", Tf::MaxLength, 16);
    setRule("MasterFlightNo", Tf::MaxLength, 16);
    setRule("ExtKey", Tf::MaxLength, 64);
    setRule("LogbookRef", Tf::MaxLength, 64);
    setRule("DepartureGateCd", Tf::MaxLength, 16);
    setRule("ArrivalGateCd", Tf::MaxLength, 16);
}
