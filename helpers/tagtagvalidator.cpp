#include "tagtagvalidator.h"

TagTagValidator::TagTagValidator() : TFormValidator()
{
    setRule("TagCd", Tf::MaxLength, 16);
}
