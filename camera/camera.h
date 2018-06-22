#ifndef CAMERA_H
#define CAMERA_H

#include <pylon/PylonIncludes.h>
#include <pylon/PylonDeviceProxy.h>
#include <pylon/gige/GigETransportLayer.h>
#include <pylon/gige/BaslerGigECamera.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>
#include <QImage>

#define CAMERA_OK   1
#define CAMERA_FAIL 0

using namespace cv;
using namespace Pylon;
using namespace Basler_GigECamera;

class Camera
{
public:
    Camera();
    int  Open();
    bool IsOpen();
    int  Close();

    void setGainAuto(GainAutoEnums gainAuto);
    GainAutoEnums GetGainAuto( );
    void setGainSelector(GainSelectorEnums gainAuto);
    GainSelectorEnums GetGainSelector();

    void setWidth(int64_t width);
    int64_t getWidth();
    void setHeight(int64_t height);
    int64_t getHeight();
    void setOffsetX(int64_t offsetX);
    int64_t getOffsetX();
    void setOffsetY(int64_t offsetY);
    int64_t getOffsetY();

    void setTriggerSelector(TriggerSelectorEnums triggerSelector);
    TriggerSelectorEnums getTriggerSelector();
    void setTriggerMode(TriggerModeEnums triggerSelector);
    TriggerModeEnums getTriggerMode();
    void setTriggerSource(TriggerSourceEnums triggerSource);
    TriggerSourceEnums getTriggerSource();
    void setTriggerActivation(TriggerActivationEnums triggerActivation);
    TriggerActivationEnums getTriggerActivation();
    void setTrigger(TriggerSelectorEnums triggerSelector,
                    TriggerModeEnums triggerMode,
                    TriggerSourceEnums triggerSource,
                    TriggerActivationEnums triggerActivation);
    void getTrigger(TriggerSelectorEnums *triggerSelector,
                    TriggerModeEnums *triggerMode,
                    TriggerSourceEnums *triggerSource,
                    TriggerActivationEnums *triggerActivation);

    void setExposureMode(ExposureModeEnums triggerActivation);
    ExposureModeEnums getExposureMode();
    void setExposureAuto(ExposureAutoEnums triggerActivation);
    ExposureAutoEnums getExposureAuto();
    void setExposureTime(double time);
    double getExposureTime();

    QImage ShotImageOne( );
    void ShotImageContinue();
    void SaveImageOne();
    void SaveImageContinue();


private:
    CBaslerGigEInstantCamera *m_camera;
    bool m_isOpenAcquire;   ///< 是否开始采集
    bool m_isOpen;          ///< 是否打开摄像头
    QSize m_size;
};

#endif // CAMERA_H
