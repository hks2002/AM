#include "schedsteplabourvalidator.h"

SchedStepLabourValidator::SchedStepLabourValidator() : TFormValidator()
{
    setRule("LabourRoleTypeCd", Tf::MaxLength, 16);
}
