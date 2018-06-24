#include "motioncontrol.h"


MotionControl::MotionControl()
{
    this->wCardNo = CARDNO_NULL;
}

MotionControl::MotionControl(_SHORT wCardNo)
{
    this->wCardNo = wCardNo;
    this->ucCardType = motion_get_card_type( wCardNo );
    switch (ucCardType) {
    case EN_MOTION_CARD_S8440A:
        this->wAxisNum = MAX_AXIS_NUM_S8440A;
        this->wGpioInNum = MAX_IN_GPIO_NUM_S8440A;
        this->wGpioOutNum = MAX_OUT_GPIO_NUM_S8440A;
    break;

    case EN_MOTION_CARD_B6612:
        this->wAxisNum = MAX_AXIS_NUM_B6612;
        this->wGpioInNum = MAX_IN_GPIO_NUM_B6612;
        this->wGpioOutNum = MAX_OUT_GPIO_NUM_B6612;
    break;

    case EN_MOTION_CARD_S8250:
        this->wAxisNum = MAX_AXIS_NUM_S8250;
        this->wGpioInNum = MAX_IN_GPIO_NUM_S8250;
        this->wGpioOutNum = MAX_OUT_GPIO_NUM_S8250;
    break;

    case EN_MOTION_CARD_B6308:
        this->wAxisNum = MAX_AXIS_NUM_B6308;
        this->wGpioInNum = MAX_IN_GPIO_NUM_B6308;
        this->wGpioOutNum = MAX_OUT_GPIO_NUM_B6308;
    break;

    case EN_MOTION_CARD_S8440B:
        this->wAxisNum = MAX_AXIS_NUM_S8440B;
        this->wGpioInNum = MAX_IN_GPIO_NUM_S8440B;
        this->wGpioOutNum = MAX_OUT_GPIO_NUM_S8440B;
    break;

    case EN_MOTION_CARD_B6428:
    break;

    case EN_MOTION_CARD_M9550:
    break;

    case EN_MOTION_CARD_P2250:
    break;

    case EN_MOTION_CARD_C3850:
    break;

    case EN_MOTION_CARD_M9222:
        this->wAxisNum = MAX_AXIS_NUM_M9222;
        this->wGpioInNum = MAX_IN_GPIO_NUM_M9222;
        this->wGpioOutNum = MAX_OUT_GPIO_NUM_M9222;
    break;

    case EN_MOTION_CARD_M9220:
        this->wAxisNum = MAX_AXIS_NUM_M9220;
        this->wGpioInNum = MAX_IN_GPIO_NUM_M9220;
        this->wGpioOutNum = MAX_OUT_GPIO_NUM_M9220;
    break;

    case EN_MOTION_CARD_S8432:
    break;

    case EN_MOTION_CARD_M9420:
    break;

    default:
        break;
    }
}

bool MotionControl::IsNull()
{
    if( CARDNO_NULL == this->wCardNo)
    {
        return true;
    }
    return false;
}

void MotionControl::Close()
{
    this->wCardNo = CARDNO_NULL;
}

_UCHAR MotionControl::GetCardType()
{
    return this->ucCardType;
}

void MotionControl::AxisInit()
{
    _WORD wLoop;
    for( wLoop=0; wLoop<wAxisNum; wLoop++)
    {
        aAxis[wLoop].Enable();
    }
}

ENUM_MOTIONCONTROL_RESULT MotionControl::GetAxisByAxisNo(_WORD wAxisNo, Axis *pAxis)
{
    if( MAX_AXIS_NUM < wAxisNo)
    {
        return EN_MOTIONCONTROL_AIXSNOERROR;
    }
    pAxis = &aAxis[wAxisNo];
    return EN_MOTIONCONTROL_OK;
}

void MotionControl::SetGpioOut( _WORD wGpioOutNo, _WORD wValue )
{
    motion_write_outbit(this->wCardNo, wGpioOutNo, wValue);
}

_WORD MotionControl::GetGpioOut( _WORD wGpioOutNo )
{
    return motion_read_outbit(this->wCardNo, wGpioOutNo);
}

_WORD MotionControl::GetGpioIn( _WORD wGpioInNo )
{
    return motion_read_inbit(this->wCardNo, wGpioInNo);
}

void MotionControl::SetDAC( _WORD wChannelNo, _WORD wValue )
{
    motion_DAC(this->wCardNo, wChannelNo, wValue);
}


