#include "regbodydocvalidator.h"

RegBodyDocValidator::RegBodyDocValidator() : TFormValidator()
{
    setRule("RegBodyDocCd", Tf::MaxLength, 16);
    setRule("RegBodyDocName", Tf::MaxLength, 128);
}
