#ifndef EQPSTOCKPARTNOVALIDATOR_H
#define EQPSTOCKPARTNOVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT EqpStockPartNoValidator : public TFormValidator
{
public:
    EqpStockPartNoValidator();
};

Q_DECLARE_METATYPE(EqpStockPartNoValidator)

#endif // EQPSTOCKPARTNOVALIDATOR_H
