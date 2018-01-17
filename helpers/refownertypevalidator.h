#ifndef REFOWNERTYPEVALIDATOR_H
#define REFOWNERTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefOwnerTypeValidator : public TFormValidator
{
public:
    RefOwnerTypeValidator();
};

Q_DECLARE_METATYPE(RefOwnerTypeValidator)

#endif // REFOWNERTYPEVALIDATOR_H
