#include "labourskillvalidator.h"

LabourSkillValidator::LabourSkillValidator() : TFormValidator()
{
    /* Rule will auto add Tf::isRequired,Disable it as required.*/

    //setRule("labourSkillCd", Tf::Required, false);
    //setRule("labourSkillNameZh", Tf::Required, false);
    //setRule("labourSkillNameEn", Tf::Required, false);

 
    setRule("labourSkillCd", Tf::MaxLength, 16);
    setRule("labourSkillNameZh", Tf::MaxLength, 64);
    setRule("labourSkillNameEn", Tf::MaxLength, 64);

}
