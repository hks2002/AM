#include "locinvrecountvalidator.h"

LocInvRecountValidator::LocInvRecountValidator() : TFormValidator()
{
    setRule("SerialNoOem", Tf::MaxLength, 64);
}
