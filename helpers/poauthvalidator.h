#ifndef POAUTHVALIDATOR_H
#define POAUTHVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoAuthValidator : public TFormValidator
{
public:
    PoAuthValidator();
};

Q_DECLARE_METATYPE(PoAuthValidator)

#endif // POAUTHVALIDATOR_H
