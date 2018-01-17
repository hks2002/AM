#include "cityvalidator.h"

CityValidator::CityValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("cityNameZh", Tf::Required, false);
    //setRule("cityNameEn", Tf::Required, false);
    //setRule("cityDesc", Tf::Required, false);

 
    setRule("cityNameZh", Tf::MaxLength, 64);
    setRule("cityNameEn", Tf::MaxLength, 64);

}
