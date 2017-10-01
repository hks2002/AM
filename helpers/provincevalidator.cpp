#include "provincevalidator.h"

ProvinceValidator::ProvinceValidator() : TFormValidator()
{
    setRule("ProvinceName", Tf::MaxLength, 64);
}
