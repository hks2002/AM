#include "transportorvalidator.h"

TransportorValidator::TransportorValidator() : TFormValidator()
{
    setRule("TransportorCd", Tf::MaxLength, 16);
    setRule("TransportorName", Tf::MaxLength, 64);
}
