#include "worktypevalidator.h"

WorkTypeValidator::WorkTypeValidator() : TFormValidator()
{
    setRule("WorkTypeCd", Tf::MaxLength, 16);
    setRule("WorkTypeName", Tf::MaxLength, 64);
}
