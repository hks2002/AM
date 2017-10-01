#ifndef OWNERAPPVALIDATOR_H
#define OWNERAPPVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT OwnerAppValidator : public TFormValidator
{
public:
    OwnerAppValidator();
};

Q_DECLARE_METATYPE(OwnerAppValidator)

#endif // OWNERAPPVALIDATOR_H
