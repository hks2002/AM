#include "locinvrecountvalidator.h"

LocInvRecountValidator::LocInvRecountValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("locId", Tf::Required, false);
    //setRule("partNoId", Tf::Required, false);
    //setRule("locPartCountId", Tf::Required, false);
    //setRule("userId", Tf::Required, false);
    //setRule("invNoId", Tf::Required, false);
    //setRule("serialNoOem", Tf::Required, false);
    //setRule("countActualQt", Tf::Required, false);
    //setRule("countExpectQt", Tf::Required, false);
    //setRule("recountDt", Tf::Required, false);

 
    setRule("serialNoOem", Tf::MaxLength, 64);

}
