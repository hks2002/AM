#ifndef AUTHORITYVALIDATOR_H
#define AUTHORITYVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT AuthorityValidator : public TFormValidator
{
public:
    AuthorityValidator();
};

Q_DECLARE_METATYPE(AuthorityValidator)

#endif // AUTHORITYVALIDATOR_H
