#include "poinvoicevalidator.h"

PoInvoiceValidator::PoInvoiceValidator() : TFormValidator()
{
    setRule("PoInvoiceCd", Tf::MaxLength, 64);
    setRule("PaymentTermsCd", Tf::MaxLength, 16);
    setRule("InvoiceNote", Tf::MaxLength, 256);
}
