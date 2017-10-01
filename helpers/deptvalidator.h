#ifndef DEPTVALIDATOR_H
#define DEPTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT DeptValidator : public TFormValidator
{
public:
    DeptValidator();
};

Q_DECLARE_METATYPE(DeptValidator)

#endif // DEPTVALIDATOR_H
