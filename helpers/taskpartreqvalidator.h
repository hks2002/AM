#ifndef TASKPARTREQVALIDATOR_H
#define TASKPARTREQVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskPartReqValidator : public TFormValidator
{
public:
    TaskPartReqValidator();
};

Q_DECLARE_METATYPE(TaskPartReqValidator)

#endif // TASKPARTREQVALIDATOR_H
