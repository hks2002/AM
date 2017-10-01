#include "manufactvalidator.h"

ManufactValidator::ManufactValidator() : TFormValidator()
{
    setRule("ManufactCd", Tf::MaxLength, 16);
    setRule("ManufactName", Tf::MaxLength, 64);
}
