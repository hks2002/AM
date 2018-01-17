#include "reffailsevvalidator.h"

RefFailSevValidator::RefFailSevValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("failSevNameEn", Tf::Required, false);
    //setRule("failSevNameZh", Tf::Required, false);
    //setRule("failSevDesc", Tf::Required, false);

 
    setRule("failSevNameEn", Tf::MaxLength, 64);
    setRule("failSevNameZh", Tf::MaxLength, 64);

}
