#ifndef REFFLIGHTLEGSTATUSVALIDATOR_H
#define REFFLIGHTLEGSTATUSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefFlightLegStatusValidator : public TFormValidator
{
public:
    RefFlightLegStatusValidator();
};

Q_DECLARE_METATYPE(RefFlightLegStatusValidator)

#endif // REFFLIGHTLEGSTATUSVALIDATOR_H
