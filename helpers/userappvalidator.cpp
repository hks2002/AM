#include "userappvalidator.h"

UserAppValidator::UserAppValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("userName", Tf::Required, false);
    //setRule("fullNameZh", Tf::Required, false);
    //setRule("fullNameEn", Tf::Required, false);
    //setRule("hrCd", Tf::Required, false);
    //setRule("password", Tf::Required, false);
    //setRule("emailAddr", Tf::Required, false);
    //setRule("lockedBool", Tf::Required, false);

 
    setRule("userName", Tf::MaxLength, 16);
    setRule("fullNameZh", Tf::MaxLength, 64);
    setRule("fullNameEn", Tf::MaxLength, 64);
    setRule("hrCd", Tf::MaxLength, 16);
    setRule("password", Tf::MaxLength, 256);
    setRule("emailAddr", Tf::MaxLength, 64);

}
