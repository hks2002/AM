#include "taskrefdocvalidator.h"

TaskRefDocValidator::TaskRefDocValidator() : TFormValidator()
{
    setRule("AmendRefDesc", Tf::MaxLength, 16);
    setRule("DocIssueByCd", Tf::MaxLength, 16);
    setRule("DocDispositionCd", Tf::MaxLength, 16);
}
