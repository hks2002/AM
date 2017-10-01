#include "schedwpcostlineitemvalidator.h"

SchedWpCostLineItemValidator::SchedWpCostLineItemValidator() : TFormValidator()
{
    setRule("CostLineItemTypeCd", Tf::MaxLength, 16);
    setRule("ItemNote", Tf::MaxLength, 256);
}
