#include "schedstaskvalidator.h"

SchedStaskValidator::SchedStaskValidator() : TFormValidator()
{
    setRule("TaskClassCd", Tf::MaxLength, 16);
    setRule("TaskRefDesc", Tf::MaxLength, 256);
    setRule("BarcodeDesc", Tf::MaxLength, 256);
    setRule("FirstSchedFromCd", Tf::MaxLength, 16);
    setRule("CancelWhenCd", Tf::MaxLength, 16);
    setRule("ReschedFromCd", Tf::MaxLength, 16);
}
