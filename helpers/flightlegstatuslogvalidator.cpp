#include "flightlegstatuslogvalidator.h"

FlightLegStatusLogValidator::FlightLegStatusLogValidator() : TFormValidator()
{
    setRule("FlightLegStatusCd", Tf::MaxLength, 16);
}
