#ifndef EQPSTOCKVALIDATOR_H
#define EQPSTOCKVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EqpStockValidator : public TFormValidator
{
public:
    EqpStockValidator();
};

Q_DECLARE_METATYPE(EqpStockValidator)

#endif // EQPSTOCKVALIDATOR_H
