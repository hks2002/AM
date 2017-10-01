#ifndef LICENSEVALIDATOR_H
#define LICENSEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT LicenseValidator : public TFormValidator
{
public:
    LicenseValidator();
};

Q_DECLARE_METATYPE(LicenseValidator)

#endif // LICENSEVALIDATOR_H
