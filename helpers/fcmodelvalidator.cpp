#include "fcmodelvalidator.h"

FcModelValidator::FcModelValidator() : TFormValidator()
{
    setRule("FcCd", Tf::MaxLength, 16);
    setRule("DescDesc", Tf::MaxLength, 256);
}
