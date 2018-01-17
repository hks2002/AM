#include "refreceivepriorityvalidator.h"

RefReceivePriorityValidator::RefReceivePriorityValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("rcvPriorityNameEn", Tf::Required, false);
    //setRule("rcvPriorityNameZh", Tf::Required, false);
    //setRule("rcvPriorityDesc", Tf::Required, false);

 
    setRule("rcvPriorityNameEn", Tf::MaxLength, 64);
    setRule("rcvPriorityNameZh", Tf::MaxLength, 64);

}
