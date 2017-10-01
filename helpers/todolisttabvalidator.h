#ifndef TODOLISTTABVALIDATOR_H
#define TODOLISTTABVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TodoListTabValidator : public TFormValidator
{
public:
    TodoListTabValidator();
};

Q_DECLARE_METATYPE(TodoListTabValidator)

#endif // TODOLISTTABVALIDATOR_H
