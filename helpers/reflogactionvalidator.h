#ifndef REFLOGACTIONVALIDATOR_H
#define REFLOGACTIONVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefLogActionValidator : public TFormValidator
{
public:
    RefLogActionValidator();
};

Q_DECLARE_METATYPE(RefLogActionValidator)

#endif // REFLOGACTIONVALIDATOR_H
