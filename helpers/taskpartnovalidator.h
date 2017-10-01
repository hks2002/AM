#ifndef TASKPARTNOVALIDATOR_H
#define TASKPARTNOVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskPartNoValidator : public TFormValidator
{
public:
    TaskPartNoValidator();
};

Q_DECLARE_METATYPE(TaskPartNoValidator)

#endif // TASKPARTNOVALIDATOR_H
