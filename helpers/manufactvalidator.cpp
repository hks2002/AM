#include "manufactvalidator.h"

ManufactValidator::ManufactValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("manufactCd", Tf::Required, false);
    //setRule("manufactName", Tf::Required, false);

 
    setRule("manufactCd", Tf::MaxLength, 16);
    setRule("manufactName", Tf::MaxLength, 64);

}
