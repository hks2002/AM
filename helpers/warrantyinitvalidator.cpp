#include "warrantyinitvalidator.h"

WarrantyInitValidator::WarrantyInitValidator() : TFormValidator()
{
    setRule("WarrantyPriorityCd", Tf::MaxLength, 16);
}
