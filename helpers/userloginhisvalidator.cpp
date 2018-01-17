#include "userloginhisvalidator.h"

UserLoginHisValidator::UserLoginHisValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("userId", Tf::Required, false);
    //setRule("loginDt", Tf::Required, false);
    //setRule("loginIp", Tf::Required, false);
    //setRule("loginMac", Tf::Required, false);
    //setRule("loginComputer", Tf::Required, false);

 
    setRule("loginComputer", Tf::MaxLength, 64);

}
