#ifndef FLIGHTLEGNOTEVALIDATOR_H
#define FLIGHTLEGNOTEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT FlightLegNoteValidator : public TFormValidator
{
public:
    FlightLegNoteValidator();
};

Q_DECLARE_METATYPE(FlightLegNoteValidator)

#endif // FLIGHTLEGNOTEVALIDATOR_H
