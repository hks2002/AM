#include "refinvclassvalidator.h"

RefInvClassValidator::RefInvClassValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("invClassNameEn", Tf::Required, false);
    //setRule("invClassNameZh", Tf::Required, false);
    //setRule("invClassDesc", Tf::Required, false);

 
    setRule("invClassNameEn", Tf::MaxLength, 64);
    setRule("invClassNameZh", Tf::MaxLength, 64);

}
