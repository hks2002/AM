#ifndef BUTTONVALIDATOR_H
#define BUTTONVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ButtonValidator : public TFormValidator
{
public:
    ButtonValidator();
};

Q_DECLARE_METATYPE(ButtonValidator)

#endif // BUTTONVALIDATOR_H
