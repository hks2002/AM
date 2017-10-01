#include "warrantydefntypevalidator.h"

WarrantyDefnTypeValidator::WarrantyDefnTypeValidator() : TFormValidator()
{
    setRule("WarrantyTypeCd", Tf::MaxLength, 16);
}
