#include "countryvalidator.h"

CountryValidator::CountryValidator() : TFormValidator()
{
    setRule("CountryName", Tf::MaxLength, 64);
}
