#ifndef REFTASKCLASSVALIDATOR_H
#define REFTASKCLASSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RefTaskClassValidator : public TFormValidator
{
public:
    RefTaskClassValidator();
};

Q_DECLARE_METATYPE(RefTaskClassValidator)

#endif // REFTASKCLASSVALIDATOR_H
