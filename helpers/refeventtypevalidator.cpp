#include "refeventtypevalidator.h"

RefEventTypeValidator::RefEventTypeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("eventTypeNameEn", Tf::Required, false);
    //setRule("eventTypeNameZh", Tf::Required, false);
    //setRule("eventTypeDesc", Tf::Required, false);

 
    setRule("eventTypeNameEn", Tf::MaxLength, 64);
    setRule("eventTypeNameZh", Tf::MaxLength, 64);

}
