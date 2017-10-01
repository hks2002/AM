#include "poauthvalidator.h"

PoAuthValidator::PoAuthValidator() : TFormValidator()
{
    setRule("AuthNote", Tf::MaxLength, 256);
}
