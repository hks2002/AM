#include "invxfervalidator.h"

InvXferValidator::InvXferValidator() : TFormValidator()
{
    setRule("XferTypeCd", Tf::MaxLength, 16);
}
