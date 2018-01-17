#include "reftaskdefstatusvalidator.h"

RefTaskDefStatusValidator::RefTaskDefStatusValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("taskDefStatusNameEn", Tf::Required, false);
    //setRule("taskDefStatusNameZh", Tf::Required, false);
    //setRule("taskDefStatusDesc", Tf::Required, false);

 
    setRule("taskDefStatusNameEn", Tf::MaxLength, 64);
    setRule("taskDefStatusNameZh", Tf::MaxLength, 64);

}
