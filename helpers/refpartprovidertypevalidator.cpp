#include "refpartprovidertypevalidator.h"

RefPartProviderTypeValidator::RefPartProviderTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("partProviderTypeNameEn", Tf::Required, false);
    //setRule("partProviderTypeNameZh", Tf::Required, false);
    //setRule("partProviderTypeDesc", Tf::Required, false);

 
    setRule("partProviderTypeNameEn", Tf::MaxLength, 64);
    setRule("partProviderTypeNameZh", Tf::MaxLength, 64);

}
