#include "faildeferrefvalidator.h"

FailDeferRefValidator::FailDeferRefValidator() : TFormValidator()
{
    setRule("FailDeferCd", Tf::MaxLength, 16);
    setRule("DeferRefName", Tf::MaxLength, 256);
    setRule("FailSevCd", Tf::MaxLength, 16);
}
