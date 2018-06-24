#ifndef MOTIONCONTROL_H
#define MOTIONCONTROL_H


#include "Axis.h"

#define MOTIONCONTROL_OK   0
#define MOTIONCONTROL_FAIL 1

#define CARDNO_NULL (-1)

typedef enum
{
    EN_MOTIONCONTROL_OK     = 0,        ///<执行成功
    EN_MOTIONCONTROL_FAIL   = 1,        ///<执行失败
    EN_MOTIONCONTROL_NODEVICES = 2,     ///<未检测到板卡
    EN_MOTIONCONTROL_AIXSNOERROR = 3,   ///<轴号错误

}ENUM_MOTIONCONTROL_RESULT;


class MotionControl
{
public:
    MotionControl();
    MotionControl( _SHORT wCardNo );
    void Close();
    void Init();
    _UCHAR GetCardType();
    void AxisInit();
    bool IsNull();

    void SetGpioOut(_WORD wGpioOutNo, _WORD wValue);
    _WORD GetGpioOut(_WORD wGpioOutNo);
    _WORD GetGpioIn(_WORD wGpioInNo);
    void SetDAC(_WORD wChanneltNo, _WORD wValue);
    ENUM_MOTIONCONTROL_RESULT GetAxisByAxisNo(_WORD wAxisNo, Axis *pAxis);
private:
    _SHORT wCardNo;
    _WORD wGpioInNum;
    _WORD wGpioOutNum;
    _WORD wExpandOutNum;
    _WORD wExpandInNum;
    _WORD wAxisNum;
    _UCHAR ucCardType;
    Axis aAxis[MAX_AXIS_NUM];
};

#endif // MOTIONCONTROL_H
