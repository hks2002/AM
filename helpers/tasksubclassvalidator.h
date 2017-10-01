#ifndef TASKSUBCLASSVALIDATOR_H
#define TASKSUBCLASSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskSubclassValidator : public TFormValidator
{
public:
    TaskSubclassValidator();
};

Q_DECLARE_METATYPE(TaskSubclassValidator)

#endif // TASKSUBCLASSVALIDATOR_H
