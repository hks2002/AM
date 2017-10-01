#ifndef SHIPSEGMENTVALIDATOR_H
#define SHIPSEGMENTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ShipSegmentValidator : public TFormValidator
{
public:
    ShipSegmentValidator();
};

Q_DECLARE_METATYPE(ShipSegmentValidator)

#endif // SHIPSEGMENTVALIDATOR_H
