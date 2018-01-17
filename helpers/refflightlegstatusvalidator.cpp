#include "refflightlegstatusvalidator.h"

RefFlightLegStatusValidator::RefFlightLegStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("flightLegStatusNameEn", Tf::Required, false);
    //setRule("flightLegStatusNameZh", Tf::Required, false);
    //setRule("flightLegStatusDesc", Tf::Required, false);

 
    setRule("flightLegStatusNameEn", Tf::MaxLength, 64);
    setRule("flightLegStatusNameZh", Tf::MaxLength, 64);

}
