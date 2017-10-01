#include "advsryvalidator.h"

AdvsryValidator::AdvsryValidator() : TFormValidator()
{
    setRule("AdvsryTypeCd", Tf::MaxLength, 16);
    setRule("AdvsryName", Tf::MaxLength, 64);
    setRule("ClearNote", Tf::MaxLength, 256);
}
