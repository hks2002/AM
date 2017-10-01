#ifndef POHEADERVALIDATOR_H
#define POHEADERVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT PoHeaderValidator : public TFormValidator
{
public:
    PoHeaderValidator();
};

Q_DECLARE_METATYPE(PoHeaderValidator)

#endif // POHEADERVALIDATOR_H
