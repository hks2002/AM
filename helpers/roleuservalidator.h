#ifndef ROLEUSERVALIDATOR_H
#define ROLEUSERVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RoleUserValidator : public TFormValidator
{
public:
    RoleUserValidator();
};

Q_DECLARE_METATYPE(RoleUserValidator)

#endif // ROLEUSERVALIDATOR_H
