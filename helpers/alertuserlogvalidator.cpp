#include "alertuserlogvalidator.h"

AlertUserLogValidator::AlertUserLogValidator() : TFormValidator()
{
    setRule("AlertStatusCd", Tf::MaxLength, 16);
}
