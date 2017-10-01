#ifndef USERATTACHMENTVALIDATOR_H
#define USERATTACHMENTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT UserAttachmentValidator : public TFormValidator
{
public:
    UserAttachmentValidator();
};

Q_DECLARE_METATYPE(UserAttachmentValidator)

#endif // USERATTACHMENTVALIDATOR_H
