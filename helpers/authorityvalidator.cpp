#include "authorityvalidator.h"

AuthorityValidator::AuthorityValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("authorityCd", Tf::Required, false);
    //setRule("authorityName", Tf::Required, false);
    //setRule("authorityDesc", Tf::Required, false);

 
    setRule("authorityCd", Tf::MaxLength, 16);
    setRule("authorityName", Tf::MaxLength, 64);

}
