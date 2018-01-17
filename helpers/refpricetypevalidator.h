#ifndef REFPRICETYPEVALIDATOR_H
#define REFPRICETYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefPriceTypeValidator : public TFormValidator
{
public:
    RefPriceTypeValidator();
};

Q_DECLARE_METATYPE(RefPriceTypeValidator)

#endif // REFPRICETYPEVALIDATOR_H
