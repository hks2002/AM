#include "locairportsettingvalidator.h"

LocAirportSettingValidator::LocAirportSettingValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("timezoneCd", Tf::Required, false);
    //setRule("supplyBool", Tf::Required, false);
    //setRule("inboundFlightQt", Tf::Required, false);

 
    setRule("timezoneCd", Tf::MaxLength, 16);

}
