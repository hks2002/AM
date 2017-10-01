#ifndef ORGCONTACTVALIDATOR_H
#define ORGCONTACTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT OrgContactValidator : public TFormValidator
{
public:
    OrgContactValidator();
};

Q_DECLARE_METATYPE(OrgContactValidator)

#endif // ORGCONTACTVALIDATOR_H
