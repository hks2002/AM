#ifndef FNCACCOUNTVALIDATOR_H
#define FNCACCOUNTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT FncAccountValidator : public TFormValidator
{
public:
    FncAccountValidator();
};

Q_DECLARE_METATYPE(FncAccountValidator)

#endif // FNCACCOUNTVALIDATOR_H
