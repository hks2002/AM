#include "refengunitvalidator.h"

RefEngUnitValidator::RefEngUnitValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("engUnitNameEn", Tf::Required, false);
    //setRule("engUnitNameZh", Tf::Required, false);
    //setRule("engUnitDesc", Tf::Required, false);

 
    setRule("engUnitNameEn", Tf::MaxLength, 64);
    setRule("engUnitNameZh", Tf::MaxLength, 64);

}
