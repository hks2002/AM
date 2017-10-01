#include "cityvalidator.h"

CityValidator::CityValidator() : TFormValidator()
{
    setRule("CityName", Tf::MaxLength, 64);
}
