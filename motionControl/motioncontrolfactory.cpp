#include "motioncontrolfactory.h"

MotionControlFactory* MotionControlFactory::pMotionControlFactory = NULL;

MotionControlFactory::MotionControlFactory()
{

}

///单例非线程安全
MotionControlFactory* MotionControlFactory::GetInstance()
{
    if (pMotionControlFactory == NULL)
    {
        pMotionControlFactory = new MotionControlFactory();
    }
    return pMotionControlFactory;
}

void MotionControlFactory::DestoryInstance()
{
    if (pMotionControlFactory != NULL)
    {
        delete pMotionControlFactory;
        pMotionControlFactory = NULL;
    }
}

ENUM_MOTIONCONTROL_RESULT MotionControlFactory::CreateMotionControl()
{
    _WORD wCardNum;
    _WORD wLoop;
    wCardNum = motion_board_init();
    if( 0 == wCardNum )
    {
        return EN_MOTIONCONTROL_NODEVICES;
    }

    for( wLoop=0; wLoop<wCardNum; wLoop++ )
    {
        acMtionControl[wLoop] = MotionControl(wLoop);
    }
    return EN_MOTIONCONTROL_OK;
}

///删除所有板卡
void MotionControlFactory::DeleteMotionControl()
{
    _WORD wLoop;
    motion_board_close();
    for( wLoop=0; wLoop<MOTION_MAX_CARD_NUM; wLoop++)
    {
        if ( !acMtionControl[wLoop].IsNull() )
        {
            acMtionControl[wLoop].Close();
        }
    }
}

///wCardNo 从0开始
ENUM_MOTIONCONTROL_RESULT MotionControlFactory::GetMotionControl(_WORD wCardNo, MotionControl* pMotionControl)
{
    if( acMtionControl[wCardNo].IsNull() )
    {
        return EN_MOTIONCONTROL_NODEVICES;
    }
    pMotionControl = &acMtionControl[wCardNo];
    return EN_MOTIONCONTROL_OK;
}

