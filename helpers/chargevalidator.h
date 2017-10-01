#ifndef CHARGEVALIDATOR_H
#define CHARGEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ChargeValidator : public TFormValidator
{
public:
    ChargeValidator();
};

Q_DECLARE_METATYPE(ChargeValidator)

#endif // CHARGEVALIDATOR_H
