#include "schedlabourvalidator.h"

SchedLabourValidator::SchedLabourValidator() : TFormValidator()
{
    setRule("LabourStageCd", Tf::MaxLength, 16);
}
