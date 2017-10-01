#ifndef EQPASSMBLDATATYPEVALIDATOR_H
#define EQPASSMBLDATATYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EqpAssmblDataTypeValidator : public TFormValidator
{
public:
    EqpAssmblDataTypeValidator();
};

Q_DECLARE_METATYPE(EqpAssmblDataTypeValidator)

#endif // EQPASSMBLDATATYPEVALIDATOR_H
