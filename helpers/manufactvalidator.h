#ifndef MANUFACTVALIDATOR_H
#define MANUFACTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ManufactValidator : public TFormValidator
{
public:
    ManufactValidator();
};

Q_DECLARE_METATYPE(ManufactValidator)

#endif // MANUFACTVALIDATOR_H
