#include "actionappvalidator.h"

ActionAppValidator::ActionAppValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("actionDesc", Tf::Required, false);
    //setRule("actionTypeZh", Tf::Required, false);
    //setRule("actionTypeEn", Tf::Required, false);
    //setRule("controller", Tf::Required, false);
    //setRule("action", Tf::Required, false);
    //setRule("activeBool", Tf::Required, false);

    setRule("actionTypeZh", Tf::MaxLength, 256);
    setRule("actionTypeEn", Tf::MaxLength, 256);
    setRule("controller", Tf::MaxLength, 128);
    setRule("action", Tf::MaxLength, 128);

}
