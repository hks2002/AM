#ifndef CLAIMVALIDATOR_H
#define CLAIMVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ClaimValidator : public TFormValidator
{
public:
    ClaimValidator();
};

Q_DECLARE_METATYPE(ClaimValidator)

#endif // CLAIMVALIDATOR_H
