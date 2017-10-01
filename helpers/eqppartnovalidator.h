#ifndef EQPPARTNOVALIDATOR_H
#define EQPPARTNOVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EqpPartNoValidator : public TFormValidator
{
public:
    EqpPartNoValidator();
};

Q_DECLARE_METATYPE(EqpPartNoValidator)

#endif // EQPPARTNOVALIDATOR_H
