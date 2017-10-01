#include "schedlabouractualvalidator.h"

SchedLabourActualValidator::SchedLabourActualValidator() : TFormValidator()
{
    setRule("LabourRoleTypeCd", Tf::MaxLength, 16);
    setRule("LabourTimeCd", Tf::MaxLength, 16);
}
