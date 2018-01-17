#include "userpswdhisvalidator.h"

UserPswdHisValidator::UserPswdHisValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("userId", Tf::Required, false);
    //setRule("password", Tf::Required, false);

 
    setRule("password", Tf::MaxLength, 256);

}
