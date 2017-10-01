#include "claimpartlinevalidator.h"

ClaimPartLineValidator::ClaimPartLineValidator() : TFormValidator()
{
    setRule("Note", Tf::MaxLength, 256);
}
