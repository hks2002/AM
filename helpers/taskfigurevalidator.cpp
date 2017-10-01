#include "taskfigurevalidator.h"

TaskFigureValidator::TaskFigureValidator() : TFormValidator()
{
    setRule("FigureNote", Tf::MaxLength, 256);
}
