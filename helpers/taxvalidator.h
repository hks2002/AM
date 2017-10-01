#ifndef TAXVALIDATOR_H
#define TAXVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaxValidator : public TFormValidator
{
public:
    TaxValidator();
};

Q_DECLARE_METATYPE(TaxValidator)

#endif // TAXVALIDATOR_H
