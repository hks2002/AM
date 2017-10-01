#ifndef TODOLISTUSERVALIDATOR_H
#define TODOLISTUSERVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TodoListUserValidator : public TFormValidator
{
public:
    TodoListUserValidator();
};

Q_DECLARE_METATYPE(TodoListUserValidator)

#endif // TODOLISTUSERVALIDATOR_H
