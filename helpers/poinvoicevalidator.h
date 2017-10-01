#ifndef POINVOICEVALIDATOR_H
#define POINVOICEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoInvoiceValidator : public TFormValidator
{
public:
    PoInvoiceValidator();
};

Q_DECLARE_METATYPE(PoInvoiceValidator)

#endif // POINVOICEVALIDATOR_H
