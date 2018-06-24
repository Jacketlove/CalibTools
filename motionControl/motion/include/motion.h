/*-------------------------------------------------------------------------------------
Copyright (C) 2010-2020 ShenZhen EasyMotion Technology Company

Author: amie
-------------------------------------------------------------------------------------*/
#ifndef __MOTION_H
#define __MOTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "base.h"

#define CTBYTES1(num)    (((num)+7)/8)
#define CTBYTES2(num)   (((num*2)+7)/8)

#define MOTION_MAX_CARD_NUM                 (16)

//以下宏定义在所有板类型中取最大值
#define MAX_AXIS_NUM                        (6)//----此处增大需要修改界面
#define MAX_GLOBAL_AXIS_NUM                 (MOTION_MAX_CARD_NUM * MAX_AXIS_NUM)
#define MAX_IN_GPIO_NUM                     (32)  //通用输入端口数
#define MAX_OUT_GPIO_NUM                    (32)  //通用输出端口数
#define MAX_IN_EXPAND_NUM                   (32)  //扩展输入端口数
#define MAX_OUT_EXPAND_NUM                  (32)  //扩展输出端口数

#define MAX_AXIS_NUM_S8250                  (2)   //S8250
#define MAX_IN_GPIO_NUM_S8250               (26)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_S8250              (28)  //通用输出端口数******MAX

#define MAX_AXIS_NUM_S8440A                 (4)   //S8440旧板(103ZET6)
#define MAX_IN_GPIO_NUM_S8440A              (20)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_S8440A             (18)  //通用输出端口数

#define MAX_AXIS_NUM_B6612                  (6)   //B6612
#define MAX_IN_GPIO_NUM_B6612               (16)  //通用输入端口数,0+16
#define MAX_OUT_GPIO_NUM_B6612              (28)  //通用输出端口数,12+16

#define MAX_AXIS_NUM_B6308                  (3)   //B6308
#define MAX_IN_GPIO_NUM_B6308               (16)  //通用输入端口数,0+16
#define MAX_OUT_GPIO_NUM_B6308              (24)  //通用输出端口数,8+16

#define MAX_AXIS_NUM_S8440B                 (4)   //S8440B
#define MAX_IN_GPIO_NUM_S8440B              (20)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_S8440B             (20)  //通用输出端口数
#define MAX_IN_EXPAND_NUM_S8440B            (8)   //扩展慢速IN
#define MAX_OUT_EXPAND_NUM_S8440B           (8)   //扩展慢速OUT
#define MAX_IO_EXPAND_BYTESIZE_S8440B       (CTBYTES1(MAX_IN_EXPAND_NUM_S8440B))   //取MAX_IN_EXPAND_NUM_S8440B和MAX_OUT_EXPAND_NUM_S8440B的最大值

#define MAX_AXIS_NUM_B6428                  (4)   //B6428
#define MAX_IN_GPIO_NUM_B6428               (32)  //通用输入端口数,16+16******MAX
#define MAX_OUT_GPIO_NUM_B6428              (27)  //通用输出端口数,12+15

#define MAX_AXIS_NUM_M9550                  (5)   //M9550
#define MAX_AXIS_NUM_M9550_ENCODER          (3)   //S轴
#define MAX_IN_GPIO_NUM_M9550               (24)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_M9550              (24)  //通用输出端口数
#define MAX_IN_EXPAND_NUM_M9550             (12)  //扩展慢速IN
#define MAX_OUT_EXPAND_NUM_M9550            (12)  //扩展慢速OUT
#define MAX_IO_EXPAND_BYTESIZE_M9550        (CTBYTES1(MAX_IN_EXPAND_NUM_M9550))   //取MAX_IN_EXPAND_NUM_M9550和MAX_OUT_EXPAND_NUM_M9550的最大值

#define MAX_AXIS_NUM_P2250                  (2)   //P2250
#define MAX_IN_GPIO_NUM_P2250               (24)  //通用输入端口数,24
#define MAX_OUT_GPIO_NUM_P2250              (21)  //通用输出端口数,21

#define MAX_AXIS_NUM_C3850                  (8)   //C3850******MAX
#define MAX_IN_GPIO_NUM_C3850               (21)  //通用输入端口数,21
#define MAX_OUT_GPIO_NUM_C3850              (24)  //通用输出端口数,24

#define MAX_AXIS_NUM_M9222                  (4)   //M9222
#define MAX_AXIS_NUM_M9222_ENCODER          (2)   //S轴
#define MAX_IN_GPIO_NUM_M9222               (18)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_M9222              (22)  //通用输出端口数
#define MAX_DAC_NUM_M9222                   (2)   //DAC通道数
#define MAX_DAC1_VOLTAGE_NUM_M9222          (10.0) //DAC通道1最大输出电平
#define MAX_DAC2_VOLTAGE_NUM_M9222          (10.0) //DAC通道2最大输出电平
#define MAX_DAC1_RESOLUTION_NUM_M9222       ((double)(pow((double)2,(int)12)-1))  //DAC通道1分辨率12位
#define MAX_DAC2_RESOLUTION_NUM_M9222       ((double)(pow((double)2,(int)12)-1))  //DAC通道2分辨率12位

#define MAX_AXIS_NUM_M9220                  (4)   //M9220
#define MAX_AXIS_NUM_M9220_ENCODER          (2)   //S轴
#define MAX_IN_GPIO_NUM_M9220               (18)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_M9220              (20)  //通用输出端口数
#define MAX_DAC_NUM_M9220                   (0)   //DAC通道数

#define MAX_AXIS_NUM_S8432                 	(4)   //S8432
#define MAX_IN_GPIO_NUM_S8432              	(16)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_S8432             	(16)  //通用输出端口数

#define MAX_AXIS_NUM_M9420                 	(6)   //M9420
#define MAX_AXIS_NUM_M9420_ENCODER          (4)   //S轴
#define MAX_IN_GPIO_NUM_M9420              	(16)  //通用输入端口数
#define MAX_OUT_GPIO_NUM_M9420             	(16)  //通用输出端口数

#define CH421A_ADDRESS_START                (0x00)
#define CH421A_ADDRESS_END                  (0x41)
#define CH421A_ADDRESS_X_U8                 (0x42)
#define CH421A_ADDRESS_Y_U9                 (0x43)

typedef enum
{
    EN_MOTION_CARD_S8440A       = 0,
    EN_MOTION_CARD_B6612        = 1,
    EN_MOTION_CARD_S8250        = 2,
    EN_MOTION_CARD_B6308        = 3,
    EN_MOTION_CARD_S8440B       = 4,
    EN_MOTION_CARD_B6428        = 5,
    EN_MOTION_CARD_M9550        = 6,

    EN_MOTION_CARD_P2250        = 7,
    EN_MOTION_CARD_C3850        = 8,

    EN_MOTION_CARD_M9222        = 9,
    EN_MOTION_CARD_M9220        = 10,

    EN_MOTION_CARD_S8432        = 11,
    EN_MOTION_CARD_M9420        = 12,

    MAX_MOTION_CARD_TYPE_NUM
} ENUM_MOTION_CARD_TYPE;

//当前板卡的规格参数
typedef struct
{
    _UCHAR ucCardType;                      //ENUM_MOTION_CARD_TYPE
    _UCHAR ucMaxAxisNum;
    _UCHAR ucMaxGINNum;
    _UCHAR ucMaxGOUTNum;
    _UCHAR ucMaxDACNum;

    _UCHAR *pucSINPin;
    _UCHAR *pucSOUTPin;
    _UCHAR ucSINPerAxis;
    _UCHAR ucSOUTPerAxis;
    _UCHAR ucSINBitBegin;
    _UCHAR ucSOUTBitBegin;
    _UCHAR ucGINByteSize;
    _UCHAR ucGOUTByteSize;
    _UCHAR ucSndGINByteSize;
    _UCHAR ucSndGOUTByteSize;
    _UCHAR ucSndGOUTShareByteNo;
    _UCHAR ucMaxEINNum;                 //扩展IN个数
    _UCHAR ucMaxEOUTNum;                //扩展OUT个数
    _UCHAR ucEIOAckByteSize;            //操作扩展IO的ACK返回的字节数

    _UCHAR ucDualRamBuffLen;
    _UCHAR ucDualRamINAddr;
    _UCHAR ucDualRamOUTSetAddr;
    _UCHAR ucDualRamOUTStateAddr;

    _UCHAR ucDualRamCMPStateAddr;
    _UCHAR ucCMPByteSize;               //EMG信号分享CMP的最高BIT位

    _UCHAR ucDualRamAxisCmdAddr;
    _UCHAR ucAxisCmdByteSize;
    _UCHAR ucDualRamAxisAckAddr;
    _UCHAR ucAxisAckByteSize;
    _UCHAR ucDualRamAxisChangeAddr;
    _UCHAR ucAxisChangeByteSize;

    _UCHAR ucDualRamMotionAddr;
    _UCHAR ucMotionByteSize;
} ST_MOTION_CARD_INFO;

/* 专用IO */
typedef enum
{
    AXIS_I_PIN_EL,                      //是否撞上机械限位，触发限位信号
    AXIS_I_PIN_EL_,						//
    AXIS_I_PIN_SD,                      //减速信号,暂时不支持
    AXIS_I_PIN_ORG,                     //原点信号

    //以下为伺服电机专有
    AXIS_I_PIN_INP,                     //电机停
    AXIS_I_PIN_RDY,                     //电机准备好
    AXIS_I_PIN_ALM,                     //电机告警
    AXIS_I_PIN_EA,                      //编码器A相
    AXIS_I_PIN_EB,                      //编码器B相
    AXIS_I_PIN_EZ,                      //原点EZ
    AXIS_I_PIN_LTC,                     //锁存信号

    //以下为步进电机专有
    AXIS_I_PIN_SD_,                     //负向减速信号
    
	AXIS_I_PIN_MAX,						//轴相关输入信号总数，在这个上面定义的信号为输入信号		
	
    AXIS_O_PIN_CMP1,                    //第1路比较信号
    AXIS_O_PIN_CMP2,                    //第2路比较信号
    AXIS_O_PIN_SEVON,                   //伺服使能
    AXIS_O_PIN_ERC,                     //误差清除
	
    MAX_IO_PIN_NUM,  					//轴相关IO口总数
}ENUM_AXIS_IO_PIN;

//注意:要与板卡侧的结构保持一致, 与ST_AXIS_PIN保持一致
typedef enum
{
    AXIS_PIN_START,

    AXIS_PIN_PUL = AXIS_PIN_START,      //脉冲信号(O)
    AXIS_PIN_DIR,                       //方向方向(O)

    AXIS_PIN_ORG,                       //原点信号(I)
    AXIS_PIN_SDnPCS,                    //减速点信号(I)
    AXIS_PIN_EL,                        //限位信号+(I)
    AXIS_PIN_EL_,                       //限位信号-(I)
    AXIS_PIN_CMP,                       //比较输出信号(O)

//以下为伺服电机专有
    AXIS_PIN_ALM,                       //报警信号(I)
    AXIS_PIN_SD_ = AXIS_PIN_ALM,        //S轴的ALM与B轴的SD-共用
    AXIS_PIN_INP,                       //位置到信号(I)
    AXIS_PIN_RDY,                       //准备好信号(I)
    AXIS_PIN_SEVON,                     //伺服使能信号(O)
    AXIS_PIN_ERC,                       //误差清除信号(O)

    AXIS_PIN_EZ,                        //原点信号(I)

    MAX_AXIS_PIN_NUM,  
}ENUM_AXIS_PIN;

/* 运动参数类型 */
typedef enum
{
    EN_AXIS_PROFILE_NULL,   //无效值

    EN_AXIS_PROFILE_T,      //T形运动参数
    EN_AXIS_PROFILE_S_T,    //S形运动按S段时间设置参数
    EN_AXIS_PROFILE_S,      //S形运动按S段距离设置参数,暂时不支持
    EN_AXIS_PROFILE_MAX
} ENUM_AXIS_PROFILE_TYPE;

/* 运动轴位移模式 */
typedef enum
{
    EN_AXIS_POSI_RELATIVE,  //相对位移
    EN_AXIS_POSI_ABSOLUTE,  //绝对位移

    EN_AXIS_POSI_MAX,
} ENUM_AXIS_POSI_MODE;

typedef enum
{
    EN_DIR_MINUS,                       //负方向
    EN_DIR_PLUS                         //正方向
}ENUM_AXIS_MOTION_DIR;

/* 运动轴停止运行模式 */
typedef enum
{
    EN_STOP_MODE_NULL,      //无停止模式
    EN_STOP_MODE_DECEL,     //减速停止
    EN_STOP_MODE_IMD,       //立刻停止

    EN_STOP_MODE_MAX,
} ENUM_AXIS_STOP_MODE;

typedef enum
{
    EN_MOTION_LOGIC_LOW  = 0,           //低电平
    EN_MOTION_LOGIC_HIGH = 1,           //高电平
    MAX_MOTION_LOGIC_TYPE
}ENUM_MOTION_LOGIC;

/* 脉冲输出模式 */
//注意:以下均值PUL-,DIR-信号,而非PUL+,DIR+信号
typedef enum
{
    EN_POM_PULSE_DIR_0, //脉冲+方向:0-下降沿触发,高电平正方向,低电平负方向
    EN_POM_PULSE_DIR_1, //脉冲+方向:1-上升沿触发,高电平正方向,低电平负方向
    EN_POM_PULSE_DIR_2, //脉冲+方向:2-下降沿触发,低电平正方向,高电平负方向
    EN_POM_PULSE_DIR_3, //脉冲+方向:3-上升沿触发,低电平正方向,高电平负方向
    EN_POM_CW_CCW_4,    //双脉冲:4-下降沿触发
    EN_POM_CW_CCW_5,    //双脉冲:5-上升沿触发

    MAX_POM_NUM
}ENUM_POM;

typedef enum
{
    EN_MOTION_DISABLE   = 0,            //去使能
    EN_MOTION_ENABLE    = 1,            //使能
    MAX_MOTION_WORK_TYPE
}ENUM_MOTION_WORK;

typedef enum
{
    EN_HOME_ORG = 0,                    //仅原点
    EN_HOME_ORG_EZ = 1,                 //原点+EZ信号
    MAX_HOME_MODE
}ENUM_HOME_MODE;

//编码器工作模式
typedef enum
{
    EN_COUNTER_PUL_DIR,                 //脉冲/方向
    EN_COUNTER_AB_1,                    //1倍AB相
    EN_COUNTER_AB_2,                    //2倍AB相
    EN_COUNTER_AB_4,                    //4倍AB相
    MAX_COUNTER_MODE
}ENUM_AXIS_COUNTER_MODE;

typedef enum
{
    EN_SPEED_LEVEL_LOW,                 //低速
    EN_SPEED_LEVEL_HIGH                 //高速
}ENUM_AXIS_SPEED_LEVEL;

typedef enum
{
    EN_SD_WATCH_INIT,                   //0-减速到起始速度,如果SD信号丢失,又开始加速
    EN_SD_WATCH_STOP,                   //1-减速到起始速度,并停止,如果在减速过程中,SD信号丢失,又开始加速
    EN_SD_LOCK_INIT,                    //2-锁存SD信号,并减速到起始速度
    EN_SD_LOCK_STOP,                    //3-锁存SD信号,并减速到起始速度后停止
    MAX_SD_MODE
}ENUM_SD_MODE;

typedef enum
{
    EN_EZ_DISABLE = 0,                  //EZ信号无效
    EN_EZ_CLEAR_COUNTER = 1,            //计数器复位信号
    EN_EZ_ORG_NO_CLEAR_COUNTER = 2,     //原点信号,且不复位计数器
    EN_EZ_ORG_CLEAR_COUNTER = 3,        //原点信号,且复位计数器
    MAX_EZ_MODE
}ENUM_EZ_MODE;

//axis运动阶段
typedef enum
{
    EN_AMS_STATIC,                      //静止阶段
    EN_AMS_ACCELERATE,                  //加速阶段
    EN_AMS_STABLE_VEL,                  //匀速阶段
    EN_AMS_DECELERATE,                  //减速阶段
}ENUM_AXIS_MOVE_STAGE;

typedef enum
{
    EN_RADIAN_CW = 0,                   //顺时针方向
    EN_RADIAN_CCW,                      //逆时针方向
    MAX_RADIAN_TYPE
}ENUM_RADIAN_DIRECTION;

//比较条件类型
typedef enum
{
    EN_CMP_STOP    = 0,                 //关闭比较器1功能
    EN_CMP_EQUAL   = 1,                 //计数器的值等于比较器
    EN_CMP_LESS    = 2,                 //计数器的值小于比较器 
    EN_CMP_MORE    = 3,                 //计数器的值大于比较器
    MAX_CMP_CONDITION
}ENUM_CMP_CONDITION;

//计数器类型
typedef enum
{
    EN_POS_COMMAND,                     //指令脉冲
    EN_POS_COUNTER,                     //编码器脉冲
    MAX_POS_TYPE
}ENUM_POS_TYPE;

typedef struct
{
    ENUM_AXIS_PROFILE_TYPE  enType;         //运动类型
    _DOUBLE                 dMin_Vel;
    _DOUBLE                 dMax_Vel;
    _DOUBLE                 dTacc;
    _DOUBLE                 dTdec;
    _DOUBLE                 dTsacc;
    _DOUBLE                 dTsdec;
}ST_AXIS_MOTION_PROFILE;

//S系列专用
typedef struct
{
    _DWORD  bORG      :1,   //原点信号(I)
            bSDnPCS   :1,   //减速点信号(I)
            bPEL      :1,   //限位信号+(I)
            bMEL      :1,   //限位信号-(I)
            bALM      :1,   //报警信号(I)   S轴ALM与B轴SD-共用
            bINP      :1,   //位置到信号(I)
            bRDY      :1,   //准备好信号(I)
            bEMG      :1,   //紧急停止信号(I)板卡级,为省略一个接口,这里归到轴里
            bEZ       :1,   //原点信号(I)
            bCMP      :1,   //比较输出信号(O)
            bSEVON    :1,   //伺服使能信号(O)
            bERC      :1,   //误差清除信号(O)
            bReserved :20;  /* 保留字段 */
}ST_S_AXIS_SIG;

//B系列专用
typedef struct
{
    _DWORD  bMEL      :1,   //EL-
            bPEL      :1,   //EL+
            bORG      :1,   //org
            bSTP      :1,   //STP
            bSTA      :1,   //STA
            bMSD      :1,   //SD-
            bPSD      :1,   //SD+
            bReserved :25;
}ST_AXIS_STATUS;

#define CardAxisSupportServoMotor(cArdType, aXis) \
    ( EN_MOTION_CARD_S8250 == cArdType || EN_MOTION_CARD_S8440A == cArdType || EN_MOTION_CARD_S8440B == cArdType || EN_MOTION_CARD_S8432 == cArdType || \
        ( EN_MOTION_CARD_M9550 == cArdType && MAX_AXIS_NUM_M9550_ENCODER > aXis ) || \
        ( EN_MOTION_CARD_M9222 == cArdType && MAX_AXIS_NUM_M9222_ENCODER > aXis ) || \
        ( EN_MOTION_CARD_M9220 == cArdType && MAX_AXIS_NUM_M9220_ENCODER > aXis ) || \
        ( EN_MOTION_CARD_M9420 == cArdType && MAX_AXIS_NUM_M9420_ENCODER > aXis ) )

#define MAX_GratingPhaseShift_NUM       5

typedef struct
{
    _INT    iMaxX;      //极限点X坐标
    _INT    iMaxY;      //极限点Y坐标

    _INT    iStandbyX;  //停靠点X坐标
    _INT    iStandbyY;  //停靠点Y坐标

    _WORD   wXTadcc;    //X轴梯形加减速时间(ms)
    _WORD   wYTadcc;    //Y轴梯形加减速时间(ms)

    _WORD   wPlaneExposureUss;      //平面图相机曝光时间(us)
    _WORD   wGratingExposureUss;    //光栅图相机曝光时间(us)

    _WORD   awLeftDacValue[MAX_GratingPhaseShift_NUM];  //左光栅相移对应的电压输出值(0~4095)
    _WORD   awRightDacValue[MAX_GratingPhaseShift_NUM]; //右光栅相移对应的电压输出值(0~4095)
    _UCHAR  bGratingPhaseShiftNum;      //光栅相移次数
    _UCHAR  bFrameRate;                 //相机帧率

    _UCHAR  bStartKeyIoNo;              //开始按键IO
    _UCHAR  bStopKeyIoNo;               //停止按键IO
    _UCHAR  bPauseKeyIoNo;              //暂停按键IO

    _UCHAR  bRedLedIoNo;                //红光源IO
    _UCHAR  bGreenLedIoNo;              //绿光源IO
    _UCHAR  bBlueLedIoNo;               //蓝光源IO

    _UCHAR  bCameraIoNo;                //相机IO(0~1)
    _UCHAR  bDacChannelNo;              //DAC通道(0~1)

    _UCHAR  bLeftGratingLedIoNo;        //左光栅光源IO
    _UCHAR  bRightGratingLedIoNo;       //右光栅光源IO

    _UCHAR  bRedLedStableMss;           //红光源稳定时间(ms)
    _UCHAR  bGreenLedStableMss;         //绿光源稳定时间(ms)
    _UCHAR  bBlueLedStableMss;          //蓝光源稳定时间(ms)
    _UCHAR  bLeftGratingLedStableMss;   //左光栅光源稳定时间(ms)
    _UCHAR  bRightGratingLedStableMss;  //右光栅光源稳定时间(ms)

    _UCHAR  bAxisX;                     //X轴号
    _UCHAR  bAxisY;                     //Y轴号
} ST_DETECT_CONFIG;

#define MAX_DTC_PHO_NUM         4
#define MAX_DTC_FOV_NUM         4

typedef struct
{
    _INT    iX;
    _INT    iY;
} ST_POSITION;


#ifdef __cplusplus
}
#endif

#endif

