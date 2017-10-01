#ifndef VENDORVALIDATOR_H
#define VENDORVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT VendorValidator : public TFormValidator
{
public:
    VendorValidator();
};

Q_DECLARE_METATYPE(VendorValidator)

#endif // VENDORVALIDATOR_H
