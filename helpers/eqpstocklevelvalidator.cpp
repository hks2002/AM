#include "eqpstocklevelvalidator.h"

EqpStockLevelValidator::EqpStockLevelValidator() : TFormValidator()
{
    setRule("StockLowActnCd", Tf::MaxLength, 16);
}
