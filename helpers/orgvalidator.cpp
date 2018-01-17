#include "orgvalidator.h"

OrgValidator::OrgValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("orgCd", Tf::Required, false);
    //setRule("orgNameZh", Tf::Required, false);
    //setRule("orgNameEn", Tf::Required, false);
    //setRule("logo", Tf::Required, false);

 
    setRule("orgCd", Tf::MaxLength, 16);

}
