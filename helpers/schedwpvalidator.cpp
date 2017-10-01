#include "schedwpvalidator.h"

SchedWpValidator::SchedWpValidator() : TFormValidator()
{
    setRule("ReleaseNumber", Tf::MaxLength, 256);
    setRule("ReceiveCondCd", Tf::MaxLength, 16);
}
