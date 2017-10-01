#include "schedwplinevalidator.h"

SchedWpLineValidator::SchedWpLineValidator() : TFormValidator()
{
    setRule("VendorLineNo", Tf::MaxLength, 64);
}
