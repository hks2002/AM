#ifndef USERAPPVALIDATOR_H
#define USERAPPVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT UserAppValidator : public TFormValidator
{
public:
    UserAppValidator();
};

Q_DECLARE_METATYPE(UserAppValidator)

#endif // USERAPPVALIDATOR_H
