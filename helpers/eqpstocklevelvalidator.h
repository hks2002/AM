#ifndef EQPSTOCKLEVELVALIDATOR_H
#define EQPSTOCKLEVELVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EqpStockLevelValidator : public TFormValidator
{
public:
    EqpStockLevelValidator();
};

Q_DECLARE_METATYPE(EqpStockLevelValidator)

#endif // EQPSTOCKLEVELVALIDATOR_H
