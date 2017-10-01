#ifndef POINVOICELINETAXVALIDATOR_H
#define POINVOICELINETAXVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoInvoiceLineTaxValidator : public TFormValidator
{
public:
    PoInvoiceLineTaxValidator();
};

Q_DECLARE_METATYPE(PoInvoiceLineTaxValidator)

#endif // POINVOICELINETAXVALIDATOR_H
