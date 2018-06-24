#ifndef MOTIONCONTROLFACTORY_H
#define MOTIONCONTROLFACTORY_H
#include "motioncontrol.h"

class MotionControlFactory
{
public:
    static MotionControlFactory* GetInstance();
    void DestoryInstance();
    ENUM_MOTIONCONTROL_RESULT CreateMotionControl();
    void DeleteMotionControl();
    ENUM_MOTIONCONTROL_RESULT GetMotionControl(_WORD wCardNo, MotionControl *pMotionControl);

protected:
    MotionControlFactory();
private:
    static MotionControlFactory* pMotionControlFactory;
    MotionControl acMtionControl[MOTION_MAX_CARD_NUM];
};




#endif // MOTIONCONTROLFACTORY_H
