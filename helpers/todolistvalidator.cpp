#include "todolistvalidator.h"

TodoListValidator::TodoListValidator() : TFormValidator()
{
    setRule("TodoListCd", Tf::MaxLength, 64);
    setRule("TodoListName", Tf::MaxLength, 64);
    setRule("TodoListTooltip", Tf::MaxLength, 256);
}
