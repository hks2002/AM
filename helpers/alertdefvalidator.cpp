#include "alertdefvalidator.h"

AlertDefValidator::AlertDefValidator() : TFormValidator()
{
    setRule("AlertName", Tf::MaxLength, 256);
    setRule("Category", Tf::MaxLength, 16);
    setRule("NotifyCd", Tf::MaxLength, 16);
    setRule("MsgTitle", Tf::MaxLength, 256);
}
