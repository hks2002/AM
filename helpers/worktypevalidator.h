#ifndef WORKTYPEVALIDATOR_H
#define WORKTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT WorkTypeValidator : public TFormValidator
{
public:
    WorkTypeValidator();
};

Q_DECLARE_METATYPE(WorkTypeValidator)

#endif // WORKTYPEVALIDATOR_H
