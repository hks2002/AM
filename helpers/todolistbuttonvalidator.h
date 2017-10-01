#ifndef TODOLISTBUTTONVALIDATOR_H
#define TODOLISTBUTTONVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TodoListButtonValidator : public TFormValidator
{
public:
    TodoListButtonValidator();
};

Q_DECLARE_METATYPE(TodoListButtonValidator)

#endif // TODOLISTBUTTONVALIDATOR_H
