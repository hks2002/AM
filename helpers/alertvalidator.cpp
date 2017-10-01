#include "alertvalidator.h"

AlertValidator::AlertValidator() : TFormValidator()
{
    setRule("AlertStatusCd", Tf::MaxLength, 16);
    setRule("MsgTitle", Tf::MaxLength, 256);
}
