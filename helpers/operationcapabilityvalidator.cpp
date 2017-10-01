#include "operationcapabilityvalidator.h"

OperationCapabilityValidator::OperationCapabilityValidator() : TFormValidator()
{
    setRule("CapabilityCd", Tf::MaxLength, 16);
    setRule("CapabilityName", Tf::MaxLength, 64);
}
