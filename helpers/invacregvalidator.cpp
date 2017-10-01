#include "invacregvalidator.h"

InvAcRegValidator::InvAcRegValidator() : TFormValidator()
{
    setRule("AcRegCd", Tf::MaxLength, 16);
    setRule("AirworthCd", Tf::MaxLength, 16);
    setRule("VarNoOem", Tf::MaxLength, 16);
    setRule("LineNoOem", Tf::MaxLength, 16);
    setRule("FinNoCd", Tf::MaxLength, 16);
}
