#include "countryvalidator.h"

CountryValidator::CountryValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("countryNameZh", Tf::Required, false);
    //setRule("countryNameEn", Tf::Required, false);
    //setRule("countryDesc", Tf::Required, false);

 
    setRule("countryNameZh", Tf::MaxLength, 64);
    setRule("countryNameEn", Tf::MaxLength, 64);

}
