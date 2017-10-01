#include "regbodyvalidator.h"

RegBodyValidator::RegBodyValidator() : TFormValidator()
{
    setRule("RegBodyCd", Tf::MaxLength, 16);
    setRule("RegBodyName", Tf::MaxLength, 128);
}
