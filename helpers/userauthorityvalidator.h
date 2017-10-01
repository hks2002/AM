#ifndef USERAUTHORITYVALIDATOR_H
#define USERAUTHORITYVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT UserAuthorityValidator : public TFormValidator
{
public:
    UserAuthorityValidator();
};

Q_DECLARE_METATYPE(UserAuthorityValidator)

#endif // USERAUTHORITYVALIDATOR_H
