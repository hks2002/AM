#ifndef REFCANCELWHENVALIDATOR_H
#define REFCANCELWHENVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefCancelWhenValidator : public TFormValidator
{
public:
    RefCancelWhenValidator();
};

Q_DECLARE_METATYPE(RefCancelWhenValidator)

#endif // REFCANCELWHENVALIDATOR_H
