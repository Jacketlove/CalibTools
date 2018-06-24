#ifndef AXIS_H
#define AXIS_H

#include "motion_api-tools.h"

class Axis
{
public:
    Axis();

    void Enable();
    void Disable();
private:
    bool bIsEnable;
    _WORD wAxisNo;

};

#endif // AXIS_H
