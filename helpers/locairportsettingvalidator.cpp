#include "locairportsettingvalidator.h"

LocAirportSettingValidator::LocAirportSettingValidator() : TFormValidator()
{
    setRule("TimezoneCd", Tf::MaxLength, 16);
}
