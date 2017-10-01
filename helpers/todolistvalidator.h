#ifndef TODOLISTVALIDATOR_H
#define TODOLISTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TodoListValidator : public TFormValidator
{
public:
    TodoListValidator();
};

Q_DECLARE_METATYPE(TodoListValidator)

#endif // TODOLISTVALIDATOR_H
