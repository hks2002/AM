#include "refeventreasonvalidator.h"

RefEventReasonValidator::RefEventReasonValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("eventReasonNameEn", Tf::Required, false);
    //setRule("eventReasonNameZh", Tf::Required, false);
    //setRule("eventReasonDesc", Tf::Required, false);

 
    setRule("eventReasonNameEn", Tf::MaxLength, 64);
    setRule("eventReasonNameZh", Tf::MaxLength, 64);

}
