#include "maintprgmtaskvalidator.h"

MaintPrgmTaskValidator::MaintPrgmTaskValidator() : TFormValidator()
{
    setRule("BlockNote", Tf::MaxLength, 256);
    setRule("GroupCd", Tf::MaxLength, 256);
}
