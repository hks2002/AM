#ifndef TASKSTEPVALIDATOR_H
#define TASKSTEPVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskStepValidator : public TFormValidator
{
public:
    TaskStepValidator();
};

Q_DECLARE_METATYPE(TaskStepValidator)

#endif // TASKSTEPVALIDATOR_H
