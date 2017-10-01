#include "reqpartvalidator.h"

ReqPartValidator::ReqPartValidator() : TFormValidator()
{
    setRule("ReqTypeCd", Tf::MaxLength, 16);
    setRule("ReqPriorityCd", Tf::MaxLength, 16);
    setRule("PartProviderTypeCd", Tf::MaxLength, 16);
    setRule("ReqMasterId", Tf::MaxLength, 16);
    setRule("ReqNote", Tf::MaxLength, 256);
}
