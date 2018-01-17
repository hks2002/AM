#ifndef REFPARTTYPEVALIDATOR_H
#define REFPARTTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefPartTypeValidator : public TFormValidator
{
public:
    RefPartTypeValidator();
};

Q_DECLARE_METATYPE(RefPartTypeValidator)

#endif // REFPARTTYPEVALIDATOR_H
