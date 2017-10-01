#ifndef RFQHEADERVALIDATOR_H
#define RFQHEADERVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT RfqHeaderValidator : public TFormValidator
{
public:
    RfqHeaderValidator();
};

Q_DECLARE_METATYPE(RfqHeaderValidator)

#endif // RFQHEADERVALIDATOR_H
