#ifndef FLIGHTLEGSTATUSLOGVALIDATOR_H
#define FLIGHTLEGSTATUSLOGVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT FlightLegStatusLogValidator : public TFormValidator
{
public:
    FlightLegStatusLogValidator();
};

Q_DECLARE_METATYPE(FlightLegStatusLogValidator)

#endif // FLIGHTLEGSTATUSLOGVALIDATOR_H
