#include "rfqheadervalidator.h"

RfqHeaderValidator::RfqHeaderValidator() : TFormValidator()
{
    setRule("RfqCd", Tf::MaxLength, 16);
}
