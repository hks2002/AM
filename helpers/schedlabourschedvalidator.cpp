#include "schedlabourschedvalidator.h"

SchedLabourSchedValidator::SchedLabourSchedValidator() : TFormValidator()
{
    setRule("LabourRoleTypeCd", Tf::MaxLength, 16);
    setRule("LabourRoleStatusCd", Tf::MaxLength, 16);
}
