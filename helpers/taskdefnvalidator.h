#ifndef TASKDEFNVALIDATOR_H
#define TASKDEFNVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskDefnValidator : public TFormValidator
{
public:
    TaskDefnValidator();
};

Q_DECLARE_METATYPE(TaskDefnValidator)

#endif // TASKDEFNVALIDATOR_H
