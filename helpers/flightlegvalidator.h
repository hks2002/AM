#ifndef FLIGHTLEGVALIDATOR_H
#define FLIGHTLEGVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT FlightLegValidator : public TFormValidator
{
public:
    FlightLegValidator();
};

Q_DECLARE_METATYPE(FlightLegValidator)

#endif // FLIGHTLEGVALIDATOR_H
