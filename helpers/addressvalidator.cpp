#include "addressvalidator.h"

AddressValidator::AddressValidator() : TFormValidator()
{
    setRule("AddressLine1", Tf::MaxLength, 256);
    setRule("AddressLine2", Tf::MaxLength, 256);
    setRule("ZipCd", Tf::MaxLength, 16);
}
