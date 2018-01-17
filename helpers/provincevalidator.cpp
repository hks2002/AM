#include "provincevalidator.h"

ProvinceValidator::ProvinceValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("provinceNameZh", Tf::Required, false);
    //setRule("provinceNameEn", Tf::Required, false);
    //setRule("provinceDesc", Tf::Required, false);

 
    setRule("provinceNameZh", Tf::MaxLength, 64);
    setRule("provinceNameEn", Tf::MaxLength, 64);

}
