#include "poinvoicelinevalidator.h"

PoInvoiceLineValidator::PoInvoiceLineValidator() : TFormValidator()
{
    setRule("LineDesc", Tf::MaxLength, 256);
    setRule("InvoiceLineNote", Tf::MaxLength, 256);
}
