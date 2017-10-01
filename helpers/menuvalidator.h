#ifndef MENUVALIDATOR_H
#define MENUVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT MenuValidator : public TFormValidator
{
public:
    MenuValidator();
};

Q_DECLARE_METATYPE(MenuValidator)

#endif // MENUVALIDATOR_H
