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
#include <QDir>
#include <QPixmap>
#define CAMERA_OK   0
#define CAMERA_FAIL 1

using namespace cv;
using namespace Pylon;

typedef Pylon::CBaslerGigEInstantCamera Camera_t;
using namespace Basler_GigECameraParams;

class Camera
{
public:
    Camera();
    ~Camera();
    int  Open();
    bool IsOpen();
    int  Close();

    void SetGainAuto(GainAutoEnums gainAuto);
    GainAutoEnums GetGainAuto();
    void SetGainSelector(GainSelectorEnums gainAuto);
    GainSelectorEnums GetGainSelector();

    void SetWidth(int64_t width);
    int64_t GetWidth();
    void SetHeight(int64_t height);
    int64_t GetHeight();
    void SetOffsetX(int64_t offsetX);
    int64_t GetOffsetX();
    void SetOffsetY(int64_t offsetY);
    int64_t GetOffsetY();

    void SetTriggerSelector(TriggerSelectorEnums triggerSelector);
    TriggerSelectorEnums GetTriggerSelector();
    void SetTriggerMode(TriggerModeEnums triggerSelector);
    TriggerModeEnums GetTriggerMode();
    void SetTriggerSource(TriggerSourceEnums triggerSource);
    TriggerSourceEnums GetTriggerSource();
    void SetTriggerActivation(TriggerActivationEnums triggerActivation);
    TriggerActivationEnums GetTriggerActivation();
    void SetTrigger(TriggerSelectorEnums triggerSelector,
                    TriggerModeEnums triggerMode,
                    TriggerSourceEnums triggerSource,
                    TriggerActivationEnums triggerActivation);
    void GetTrigger(TriggerSelectorEnums *triggerSelector,
                    TriggerModeEnums *triggerMode,
                    TriggerSourceEnums *triggerSource,
                    TriggerActivationEnums *triggerActivation);

    void SetExposureMode(ExposureModeEnums triggerActivation);
    ExposureModeEnums GetExposureMode();
    void SetExposureAuto(ExposureAutoEnums triggerActivation);
    ExposureAutoEnums GetExposureAuto();
    void SetExposureTime(double time);
    double GetExposureTime();

    QPixmap ShotImageOne();
    bool ShotImageOne(cv::Mat *pMat);
    void ShotImageContinue();
    void SaveImageOne( QString qsImagePath );
    void SaveImageContinue();


    void SetFilePath(QString qsFilePath);
    QString GetFilePath();
    void SetFilePrefix(QString qsFilePrefix);
    QString GetFilePrefix();


private:
    Camera_t *m_camera;
    QSize m_size;

    ///保存图片路径
    QString qsFilePath;
    ///保存图片前缀
    QString qsFilePrefix;

};

#endif // CAMERA_H
