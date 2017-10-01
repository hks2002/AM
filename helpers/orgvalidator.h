#ifndef ORGVALIDATOR_H
#define ORGVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT OrgValidator : public TFormValidator
{
public:
    OrgValidator();
};

Q_DECLARE_METATYPE(OrgValidator)

#endif // ORGVALIDATOR_H
