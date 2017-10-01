#include "claimvalidator.h"

ClaimValidator::ClaimValidator() : TFormValidator()
{
    setRule("ClaimToCd", Tf::MaxLength, 16);
    setRule("CreditRefDesc", Tf::MaxLength, 256);
}
