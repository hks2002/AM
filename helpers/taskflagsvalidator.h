#ifndef TASKFLAGSVALIDATOR_H
#define TASKFLAGSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskFlagsValidator : public TFormValidator
{
public:
    TaskFlagsValidator();
};

Q_DECLARE_METATYPE(TaskFlagsValidator)

#endif // TASKFLAGSVALIDATOR_H
