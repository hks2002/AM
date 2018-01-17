#include "refeventstatusvalidator.h"

RefEventStatusValidator::RefEventStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("eventStatusNameEn", Tf::Required, false);
    //setRule("eventStatusNameZh", Tf::Required, false);
    //setRule("eventStatusDesc", Tf::Required, false);

 
    setRule("eventStatusNameEn", Tf::MaxLength, 64);
    setRule("eventStatusNameZh", Tf::MaxLength, 64);

}
