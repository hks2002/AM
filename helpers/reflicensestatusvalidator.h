#ifndef REFLICENSESTATUSVALIDATOR_H
#define REFLICENSESTATUSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefLicenseStatusValidator : public TFormValidator
{
public:
    RefLicenseStatusValidator();
};

Q_DECLARE_METATYPE(RefLicenseStatusValidator)

#endif // REFLICENSESTATUSVALIDATOR_H
