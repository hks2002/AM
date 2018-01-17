#include "refworkpackagetypevalidator.h"

RefWorkpackageTypeValidator::RefWorkpackageTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("workpackageTypeNameEn", Tf::Required, false);
    //setRule("workpackageTypeNameZh", Tf::Required, false);
    //setRule("workpackageTypeDesc", Tf::Required, false);

 
    setRule("workpackageTypeNameEn", Tf::MaxLength, 64);
    setRule("workpackageTypeNameZh", Tf::MaxLength, 64);

}
