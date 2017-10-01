#ifndef INVKITVALIDATOR_H
#define INVKITVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT InvKitValidator : public TFormValidator
{
public:
    InvKitValidator();
};

Q_DECLARE_METATYPE(InvKitValidator)

#endif // INVKITVALIDATOR_H
