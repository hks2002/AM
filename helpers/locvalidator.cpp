#include "locvalidator.h"

LocValidator::LocValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("locCd", Tf::Required, false);
    //setRule("locTypeCd", Tf::Required, false);
    //setRule("locName", Tf::Required, false);

 
    setRule("locCd", Tf::MaxLength, 64);
    setRule("locTypeCd", Tf::MaxLength, 16);
    setRule("locName", Tf::MaxLength, 256);

}
