#include "refborrowratevalidator.h"

RefBorrowRateValidator::RefBorrowRateValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("borrowRateNameEn", Tf::Required, false);
    //setRule("borrowRateNameZh", Tf::Required, false);
    //setRule("borrowRateDesc", Tf::Required, false);

 
    setRule("borrowRateNameEn", Tf::MaxLength, 64);
    setRule("borrowRateNameZh", Tf::MaxLength, 64);

}
