#ifndef POINVOICELINECHARGEVALIDATOR_H
#define POINVOICELINECHARGEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoInvoiceLineChargeValidator : public TFormValidator
{
public:
    PoInvoiceLineChargeValidator();
};

Q_DECLARE_METATYPE(PoInvoiceLineChargeValidator)

#endif // POINVOICELINECHARGEVALIDATOR_H
