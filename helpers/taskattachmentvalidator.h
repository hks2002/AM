#ifndef TASKATTACHMENTVALIDATOR_H
#define TASKATTACHMENTVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT TaskAttachmentValidator : public TFormValidator
{
public:
    TaskAttachmentValidator();
};

Q_DECLARE_METATYPE(TaskAttachmentValidator)

#endif // TASKATTACHMENTVALIDATOR_H
