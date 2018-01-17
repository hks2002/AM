#include "refcancelwhenvalidator.h"

RefCancelWhenValidator::RefCancelWhenValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("cancelWhenNameEn", Tf::Required, false);
    //setRule("cancelWhenNameZh", Tf::Required, false);
    //setRule("cancelWhenDesc", Tf::Required, false);

 
    setRule("cancelWhenNameEn", Tf::MaxLength, 64);
    setRule("cancelWhenNameZh", Tf::MaxLength, 64);

}
