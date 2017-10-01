#include "authorityvalidator.h"

AuthorityValidator::AuthorityValidator() : TFormValidator()
{
    setRule("AuthorityCd", Tf::MaxLength, 16);
    setRule("AuthorityName", Tf::MaxLength, 64);
}
