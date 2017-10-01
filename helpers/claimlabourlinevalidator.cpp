#include "claimlabourlinevalidator.h"

ClaimLabourLineValidator::ClaimLabourLineValidator() : TFormValidator()
{
    setRule("Note", Tf::MaxLength, 256);
}
