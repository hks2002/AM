#include "refbomclassvalidator.h"

RefBomClassValidator::RefBomClassValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("bomClassNameEn", Tf::Required, false);
    //setRule("bomClassNameZh", Tf::Required, false);
    //setRule("bomClassDesc", Tf::Required, false);

 
    setRule("bomClassNameEn", Tf::MaxLength, 64);
    setRule("bomClassNameZh", Tf::MaxLength, 64);

}
