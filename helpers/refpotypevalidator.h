#ifndef REFPOTYPEVALIDATOR_H
#define REFPOTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefPoTypeValidator : public TFormValidator
{
public:
    RefPoTypeValidator();
};

Q_DECLARE_METATYPE(RefPoTypeValidator)

#endif // REFPOTYPEVALIDATOR_H
