#include "refpartusevalidator.h"

RefPartUseValidator::RefPartUseValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("partUseNameEn", Tf::Required, false);
    //setRule("partUseNameZh", Tf::Required, false);
    //setRule("partUseDesc", Tf::Required, false);

 
    setRule("partUseNameEn", Tf::MaxLength, 64);
    setRule("partUseNameZh", Tf::MaxLength, 64);

}
