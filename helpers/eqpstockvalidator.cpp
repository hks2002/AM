#include "eqpstockvalidator.h"

EqpStockValidator::EqpStockValidator() : TFormValidator()
{
    setRule("StockNoCd", Tf::MaxLength, 16);
    setRule("StockNoName", Tf::MaxLength, 64);
}
