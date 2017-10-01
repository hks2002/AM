#ifndef ORGCODEVALIDATOR_H
#define ORGCODEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT OrgCodeValidator : public TFormValidator
{
public:
    OrgCodeValidator();
};

Q_DECLARE_METATYPE(OrgCodeValidator)

#endif // ORGCODEVALIDATOR_H
