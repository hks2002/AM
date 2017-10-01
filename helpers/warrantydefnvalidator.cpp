#include "warrantydefnvalidator.h"

WarrantyDefnValidator::WarrantyDefnValidator() : TFormValidator()
{
    setRule("WarrantyCd", Tf::MaxLength, 16);
    setRule("WarrantyStatusCd", Tf::MaxLength, 16);
    setRule("PriorityCd", Tf::MaxLength, 16);
    setRule("SummaryDesc", Tf::MaxLength, 256);
}
