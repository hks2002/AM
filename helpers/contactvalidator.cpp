#include "contactvalidator.h"

ContactValidator::ContactValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("addressEmail", Tf::Required, false);
    //setRule("contactName", Tf::Required, false);
    //setRule("jobTitle", Tf::Required, false);
    //setRule("faxPh", Tf::Required, false);
    //setRule("phonePh", Tf::Required, false);

 
    setRule("addressEmail", Tf::MaxLength, 64);
    setRule("contactName", Tf::MaxLength, 16);
    setRule("jobTitle", Tf::MaxLength, 16);
    setRule("faxPh", Tf::MaxLength, 16);
    setRule("phonePh", Tf::MaxLength, 16);

}
