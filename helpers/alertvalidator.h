#ifndef ALERTVALIDATOR_H
#define ALERTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT AlertValidator : public TFormValidator
{
public:
    AlertValidator();
};

Q_DECLARE_METATYPE(AlertValidator)

#endif // ALERTVALIDATOR_H
