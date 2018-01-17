#ifndef REFOWNBYVALIDATOR_H
#define REFOWNBYVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefOwnByValidator : public TFormValidator
{
public:
    RefOwnByValidator();
};

Q_DECLARE_METATYPE(RefOwnByValidator)

#endif // REFOWNBYVALIDATOR_H
