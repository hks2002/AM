#include "warrantydefnsubtypevalidator.h"

WarrantyDefnSubtypeValidator::WarrantyDefnSubtypeValidator() : TFormValidator()
{
    setRule("WarrantySubtypeCd", Tf::MaxLength, 16);
}
