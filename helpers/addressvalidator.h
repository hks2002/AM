#ifndef ADDRESSVALIDATOR_H
#define ADDRESSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT AddressValidator : public TFormValidator
{
public:
    AddressValidator();
};

Q_DECLARE_METATYPE(AddressValidator)

#endif // ADDRESSVALIDATOR_H
