#ifndef TASKFIGUREVALIDATOR_H
#define TASKFIGUREVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskFigureValidator : public TFormValidator
{
public:
    TaskFigureValidator();
};

Q_DECLARE_METATYPE(TaskFigureValidator)

#endif // TASKFIGUREVALIDATOR_H
