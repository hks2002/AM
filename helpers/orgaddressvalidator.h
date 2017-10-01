#ifndef ORGADDRESSVALIDATOR_H
#define ORGADDRESSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT OrgAddressValidator : public TFormValidator
{
public:
    OrgAddressValidator();
};

Q_DECLARE_METATYPE(OrgAddressValidator)

#endif // ORGADDRESSVALIDATOR_H
