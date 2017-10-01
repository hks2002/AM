#ifndef TASKNRESTVALIDATOR_H
#define TASKNRESTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskNrEstValidator : public TFormValidator
{
public:
    TaskNrEstValidator();
};

Q_DECLARE_METATYPE(TaskNrEstValidator)

#endif // TASKNRESTVALIDATOR_H
