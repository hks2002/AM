#ifndef REFCLAIMTOVALIDATOR_H
#define REFCLAIMTOVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefClaimToValidator : public TFormValidator
{
public:
    RefClaimToValidator();
};

Q_DECLARE_METATYPE(RefClaimToValidator)

#endif // REFCLAIMTOVALIDATOR_H
