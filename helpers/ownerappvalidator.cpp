#include "ownerappvalidator.h"

OwnerAppValidator::OwnerAppValidator() : TFormValidator()
{
    setRule("OwnerTypeCd", Tf::MaxLength, 16);
}
