#include "refreschedfromvalidator.h"

RefReschedFromValidator::RefReschedFromValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("reschedFromNameEn", Tf::Required, false);
    //setRule("reschedFromNameZh", Tf::Required, false);
    //setRule("reschedFromDesc", Tf::Required, false);

 
    setRule("reschedFromNameEn", Tf::MaxLength, 64);
    setRule("reschedFromNameZh", Tf::MaxLength, 64);

}
