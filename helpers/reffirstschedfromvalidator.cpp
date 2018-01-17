#include "reffirstschedfromvalidator.h"

RefFirstSchedFromValidator::RefFirstSchedFromValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("firstSchedFromNameEn", Tf::Required, false);
    //setRule("firstSchedFromNameZh", Tf::Required, false);
    //setRule("firstSchedFromDesc", Tf::Required, false);

 
    setRule("firstSchedFromNameEn", Tf::MaxLength, 64);
    setRule("firstSchedFromNameZh", Tf::MaxLength, 64);

}
