#ifndef QTYUNITVALIDATOR_H
#define QTYUNITVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT QtyUnitValidator : public TFormValidator
{
public:
    QtyUnitValidator();
};

Q_DECLARE_METATYPE(QtyUnitValidator)

#endif // QTYUNITVALIDATOR_H
