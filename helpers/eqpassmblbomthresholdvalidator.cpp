#include "eqpassmblbomthresholdvalidator.h"

EqpAssmblBomThresholdValidator::EqpAssmblBomThresholdValidator() : TFormValidator()
{
    setRule("ThresholdModeCd", Tf::MaxLength, 16);
}
