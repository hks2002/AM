#ifndef RFQVENDORVALIDATOR_H
#define RFQVENDORVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RfqVendorValidator : public TFormValidator
{
public:
    RfqVendorValidator();
};

Q_DECLARE_METATYPE(RfqVendorValidator)

#endif // RFQVENDORVALIDATOR_H
