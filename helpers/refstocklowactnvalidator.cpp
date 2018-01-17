#include "refstocklowactnvalidator.h"

RefStockLowActnValidator::RefStockLowActnValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("stockLowActnNameEn", Tf::Required, false);
    //setRule("stockLowActnNameZh", Tf::Required, false);
    //setRule("stockLowActnDesc", Tf::Required, false);

 
    setRule("stockLowActnNameEn", Tf::MaxLength, 64);
    setRule("stockLowActnNameZh", Tf::MaxLength, 64);

}
