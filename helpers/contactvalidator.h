#ifndef CONTACTVALIDATOR_H
#define CONTACTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ContactValidator : public TFormValidator
{
public:
    ContactValidator();
};

Q_DECLARE_METATYPE(ContactValidator)

#endif // CONTACTVALIDATOR_H
