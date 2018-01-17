#include "reftradetermsvalidator.h"

RefTradeTermsValidator::RefTradeTermsValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("tradeTermNameEn", Tf::Required, false);
    //setRule("tradeTermNameZh", Tf::Required, false);
    //setRule("tradeTermDesc", Tf::Required, false);

 
    setRule("tradeTermNameEn", Tf::MaxLength, 64);
    setRule("tradeTermNameZh", Tf::MaxLength, 64);

}
