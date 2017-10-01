#ifndef LOCADDRESSVALIDATOR_H
#define LOCADDRESSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT LocAddressValidator : public TFormValidator
{
public:
    LocAddressValidator();
};

Q_DECLARE_METATYPE(LocAddressValidator)

#endif // LOCADDRESSVALIDATOR_H
