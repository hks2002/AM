#ifndef POINVOICELINEMAPVALIDATOR_H
#define POINVOICELINEMAPVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoInvoiceLineMapValidator : public TFormValidator
{
public:
    PoInvoiceLineMapValidator();
};

Q_DECLARE_METATYPE(PoInvoiceLineMapValidator)

#endif // POINVOICELINEMAPVALIDATOR_H
