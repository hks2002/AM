#ifndef REFLOCTYPEVALIDATOR_H
#define REFLOCTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefLocTypeValidator : public TFormValidator
{
public:
    RefLocTypeValidator();
};

Q_DECLARE_METATYPE(RefLocTypeValidator)

#endif // REFLOCTYPEVALIDATOR_H
