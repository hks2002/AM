#include "warrantyevalvalidator.h"

WarrantyEvalValidator::WarrantyEvalValidator() : TFormValidator()
{
    setRule("WarrantyEvalStatusCd", Tf::MaxLength, 16);
}
