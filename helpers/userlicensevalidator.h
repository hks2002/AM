#ifndef USERLICENSEVALIDATOR_H
#define USERLICENSEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT UserLicenseValidator : public TFormValidator
{
public:
    UserLicenseValidator();
};

Q_DECLARE_METATYPE(UserLicenseValidator)

#endif // USERLICENSEVALIDATOR_H
