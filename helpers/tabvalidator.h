#ifndef TABVALIDATOR_H
#define TABVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TabValidator : public TFormValidator
{
public:
    TabValidator();
};

Q_DECLARE_METATYPE(TabValidator)

#endif // TABVALIDATOR_H
