#ifndef POINVOICELINEVALIDATOR_H
#define POINVOICELINEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoInvoiceLineValidator : public TFormValidator
{
public:
    PoInvoiceLineValidator();
};

Q_DECLARE_METATYPE(PoInvoiceLineValidator)

#endif // POINVOICELINEVALIDATOR_H
