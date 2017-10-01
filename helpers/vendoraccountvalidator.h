#ifndef VENDORACCOUNTVALIDATOR_H
#define VENDORACCOUNTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT VendorAccountValidator : public TFormValidator
{
public:
    VendorAccountValidator();
};

Q_DECLARE_METATYPE(VendorAccountValidator)

#endif // VENDORACCOUNTVALIDATOR_H
