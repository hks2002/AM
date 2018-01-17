#include "refpaymenttermsvalidator.h"

RefPaymentTermsValidator::RefPaymentTermsValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("paymentTermsNameEn", Tf::Required, false);
    //setRule("paymentTermsNameZh", Tf::Required, false);
    //setRule("paymentTermsDesc", Tf::Required, false);

 
    setRule("paymentTermsNameEn", Tf::MaxLength, 64);
    setRule("paymentTermsNameZh", Tf::MaxLength, 64);

}
