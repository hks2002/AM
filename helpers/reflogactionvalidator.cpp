#include "reflogactionvalidator.h"

RefLogActionValidator::RefLogActionValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("logActionNameEn", Tf::Required, false);
    //setRule("logActionNameZh", Tf::Required, false);
    //setRule("logActionDesc", Tf::Required, false);

 
    setRule("logActionNameEn", Tf::MaxLength, 64);
    setRule("logActionNameZh", Tf::MaxLength, 64);

}
