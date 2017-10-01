#ifndef CURRENCYVALIDATOR_H
#define CURRENCYVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT CurrencyValidator : public TFormValidator
{
public:
    CurrencyValidator();
};

Q_DECLARE_METATYPE(CurrencyValidator)

#endif // CURRENCYVALIDATOR_H
