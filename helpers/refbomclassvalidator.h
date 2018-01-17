#ifndef REFBOMCLASSVALIDATOR_H
#define REFBOMCLASSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefBomClassValidator : public TFormValidator
{
public:
    RefBomClassValidator();
};

Q_DECLARE_METATYPE(RefBomClassValidator)

#endif // REFBOMCLASSVALIDATOR_H
