#ifndef FAILDEFERREFVALIDATOR_H
#define FAILDEFERREFVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT FailDeferRefValidator : public TFormValidator
{
public:
    FailDeferRefValidator();
};

Q_DECLARE_METATYPE(FailDeferRefValidator)

#endif // FAILDEFERREFVALIDATOR_H
