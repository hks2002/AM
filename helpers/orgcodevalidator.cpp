#include "orgcodevalidator.h"

OrgCodeValidator::OrgCodeValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("icaoCd", Tf::Required, false);
    //setRule("iataCd", Tf::Required, false);
    //setRule("callsignCd", Tf::Required, false);

 
    setRule("icaoCd", Tf::MaxLength, 16);
    setRule("iataCd", Tf::MaxLength, 16);
    setRule("callsignCd", Tf::MaxLength, 16);

}
