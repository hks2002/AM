#ifndef TASKPANELVALIDATOR_H
#define TASKPANELVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskPanelValidator : public TFormValidator
{
public:
    TaskPanelValidator();
};

Q_DECLARE_METATYPE(TaskPanelValidator)

#endif // TASKPANELVALIDATOR_H
