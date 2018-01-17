#include "actionappvalidator.h"

ActionAppValidator::ActionAppValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("actionCd", Tf::Required, false);
    //setRule("actionNameZh", Tf::Required, false);
    //setRule("actionNameEn", Tf::Required, false);
    //setRule("actionTooltip", Tf::Required, false);
    //setRule("actionDesc", Tf::Required, false);
    //setRule("actionTypeZh", Tf::Required, false);
    //setRule("actionTypeEn", Tf::Required, false);
    //setRule("controller", Tf::Required, false);
    //setRule("action", Tf::Required, false);
    //setRule("activeBool", Tf::Required, false);

 
    setRule("actionCd", Tf::MaxLength, 128);
    setRule("actionNameZh", Tf::MaxLength, 256);
    setRule("actionNameEn", Tf::MaxLength, 256);
    setRule("actionTooltip", Tf::MaxLength, 256);
    setRule("actionTypeZh", Tf::MaxLength, 256);
    setRule("actionTypeEn", Tf::MaxLength, 256);
    setRule("controller", Tf::MaxLength, 128);
    setRule("action", Tf::MaxLength, 128);

}
