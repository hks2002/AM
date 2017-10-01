#include "labourskillvalidator.h"

LabourSkillValidator::LabourSkillValidator() : TFormValidator()
{
    setRule("LabourSkillCd", Tf::MaxLength, 16);
    setRule("LabourSkillName", Tf::MaxLength, 64);
}
