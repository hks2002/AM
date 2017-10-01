#ifndef DATATYPEVALIDATOR_H
#define DATATYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT DataTypeValidator : public TFormValidator
{
public:
    DataTypeValidator();
};

Q_DECLARE_METATYPE(DataTypeValidator)

#endif // DATATYPEVALIDATOR_H
