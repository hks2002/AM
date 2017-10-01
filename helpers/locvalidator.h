#ifndef LOCVALIDATOR_H
#define LOCVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT LocValidator : public TFormValidator
{
public:
    LocValidator();
};

Q_DECLARE_METATYPE(LocValidator)

#endif // LOCVALIDATOR_H
