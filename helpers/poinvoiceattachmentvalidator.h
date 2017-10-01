#ifndef POINVOICEATTACHMENTVALIDATOR_H
#define POINVOICEATTACHMENTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoInvoiceAttachmentValidator : public TFormValidator
{
public:
    PoInvoiceAttachmentValidator();
};

Q_DECLARE_METATYPE(PoInvoiceAttachmentValidator)

#endif // POINVOICEATTACHMENTVALIDATOR_H
