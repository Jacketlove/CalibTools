#include "camera.h"

/// Pylon 中的 CInstantCamera 类支持四种图像获取策略，分别称为：
/// 1.One by One Grab Strategy
///     这种模式是最简单的，也是 CInstantCamera 默认的图像获取策略。获取到的图像放到一个FIFO 队列中。
///     每次我们从队列中取的（RetrieveResult）都是最早放到队列中的图像。
///
/// 2.Latest Image Only Grab Strategy
///     这个策略下只有最新到的图像保存在输出队列中。如果一份旧图像还没被读取新图像就又来了，那么旧图像就
///     被舍弃。这样可以保证读取到图像永远都是读取时刻最新的。
///
/// 3.Latest Images Strategy
///     这个模式下输出队列可以保存不止一张图像，具体最多能保存几张图象由 CInstantCamera::OutputQueueSize
///     来指定。当新的图像来了，而队列已满时，旧的图像被舍弃。 当 CInstantCamera::OutputQueueSize 为 1
///     时就是 Latest Image Only Grab Strategy。当CInstantCamera::OutputQueueSize = CInstantCamera::MaxNumBuffer，
///     就和 One by One Grab Strategy 一样了。
///
/// 4.Upcoming Image Grab Strategy
///     这个模式很特别，只有当 CInstantCamera::RetrieveResult() 被调用后才会采集图像。USB 相机不支持这种
///     策略。


Camera::Camera()
{

}

int Camera::Open()
{
    CTlFactory& TlFactory = CTlFactory::GetInstance();
    IGigETransportLayer* pTl = static_cast<Pylon::IGigETransportLayer*> (TlFactory.CreateTl("BaslerGigE"));
    IPylonDevice * pDevice = pTl->CreateFirstDevice();
    CBaslerGigEInstantCamera tempCamera(pDevice);
    this->m_camera = &tempCamera;
    try{
        m_camera->Open();
    }catch(GenICam::GenericException e){
        qDebug("Open Camera Fail");
        qDebug(e.GetDescription());
        return CAMERA_FAIL;
    }
    m_camera->PixelFormat.SetValue(PixelFormat_Mono8);    ///<设置相机传输的像素数据的格式。
    m_camera->Width.SetValue(2064);     ///<相机的兴趣区的宽度（以像素为单位）。
    m_camera->Height.SetValue(1544);    ///<相机的兴趣区的高度（以像素为单位）
    m_camera->TriggerSelector.SetValue(TriggerSelector_FrameStart);
    m_camera->TriggerMode.SetValue(TriggerMode_Off);
    m_camera->ExposureMode.SetValue(ExposureMode_Timed);
    m_camera->ExposureTimeAbs.SetValue(5000.0);
    return CAMERA_OK;
}

bool Camera::IsOpen()
{
    return m_camera->IsOpen();
}

int Camera::Close()
{
    if( false == m_camera->IsOpen() )
    {
        return CAMERA_FAIL;
    }
    try {
        if(m_camera->IsOpen()) {
            m_camera->DetachDevice();
            m_camera->Close();
        }
    } catch (GenICam::GenericException e) {
        qDebug("Close Camera Fail");
        qDebug(e.GetDescription());
        return CAMERA_FAIL;
    }
    return CAMERA_OK;
}

void Camera::setGainAuto( GainAutoEnums gainAuto )
{
    m_camera->GainAuto.SetValue( gainAuto );
}

GainAutoEnums Camera::GetGainAuto( )
{
    return m_camera->GainAuto.GetValue();
}

void Camera::setGainSelector( GainSelectorEnums gainAuto )
{
    m_camera->GainSelector.SetValue( gainAuto );
}

GainSelectorEnums Camera::GetGainSelector( )
{
    return m_camera->GainSelector.GetValue();
}

///***************************AOI CONFIG*********************************///
void Camera::setWidth( int64_t width )
{
    m_camera->Width.SetValue( width );
}

int64_t Camera::getWidth()
{
    return m_camera->Width.GetValue();
}

void Camera::setHeight(int64_t height )
{
    m_camera->Height.SetValue( height );
}

int64_t Camera::getHeight()
{
    return m_camera->Height.GetValue();
}

void Camera::setOffsetX(int64_t offsetX )
{
    m_camera->OffsetX.SetValue( offsetX );
}

int64_t Camera::getOffsetX()
{
    return m_camera->OffsetX.GetValue();
}

void Camera::setOffsetY(int64_t offsetY )
{
    m_camera->OffsetY.SetValue( offsetY );
}

int64_t Camera::getOffsetY()
{
    return m_camera->OffsetY.GetValue();
}

///***************************Trigger CONFIG*********************************///
void Camera::setTriggerSelector( TriggerSelectorEnums triggerSelector )
{
    m_camera->TriggerSelector.SetValue( triggerSelector );
}

TriggerSelectorEnums Camera::getTriggerSelector()
{
    return m_camera->TriggerSelector.GetValue();
}

void Camera::setTriggerMode( TriggerModeEnums triggerMode )
{
    m_camera->TriggerMode.SetValue(triggerMode);
}

TriggerModeEnums Camera::getTriggerMode()
{
    return m_camera->TriggerMode.GetValue();
}

void Camera::setTriggerSource( TriggerSourceEnums triggerSource )
{
    m_camera->TriggerSource.SetValue( triggerSource );
}

TriggerSourceEnums Camera::getTriggerSource()
{
    return m_camera->TriggerSource.GetValue();
}

void Camera::setTriggerActivation( TriggerActivationEnums triggerActivation )
{
    m_camera->TriggerActivation.SetValue( triggerActivation );
}

TriggerActivationEnums Camera::getTriggerActivation()
{
    return m_camera->TriggerActivation.GetValue();
}

void Camera::setTrigger(TriggerSelectorEnums triggerSelector, \
                        TriggerModeEnums triggerMode, \
                        TriggerSourceEnums triggerSource, \
                        TriggerActivationEnums triggerActivation)
{
    setTriggerSelector(triggerSelector);
    setTriggerMode(triggerMode);
    setTriggerSource(triggerSource);
    setTriggerActivation(triggerActivation);
}

void Camera::getTrigger(TriggerSelectorEnums *triggerSelector, \
                        TriggerModeEnums *triggerMode, \
                        TriggerSourceEnums *triggerSource, \
                        TriggerActivationEnums *triggerActivation)
{
    *triggerSelector = getTriggerSelector();
    *triggerMode = getTriggerMode();
    *triggerSource = getTriggerSource();
    *triggerActivation = getTriggerActivation();
}

///***************************Trigger CONFIG End *****************************///

///***************************Exposure CONFIG Start***************************///
void Camera::setExposureMode(ExposureModeEnums triggerActivation )
{
    m_camera->ExposureMode.SetValue( triggerActivation );
}

ExposureModeEnums Camera::getExposureMode()
{
    return m_camera->ExposureMode.GetValue();
}

void Camera::setExposureAuto(ExposureAutoEnums triggerActivation )
{
    m_camera->ExposureAuto.SetValue( triggerActivation );
}

ExposureAutoEnums Camera::getExposureAuto()
{
    return m_camera->ExposureAuto.GetValue();
}

void Camera::setExposureTime( double time )
{
    m_camera->ExposureTimeAbs.SetValue( time );
}

double Camera::getExposureTime()
{
    return m_camera->ExposureTimeAbs.GetValue();
}

QImage Camera::ShotImageOne( )
{
    if( true == m_camera->IsGrabbing() ){
        m_camera->StopGrabbing();
    }
    CGrabResultPtr cGrabResultPtr;
    CImageFormatConverter cImageFormatConverter;
    cImageFormatConverter.OutputPixelFormat = PixelType_BGR8packed;
    CPylonImage cPylonImage;
    m_camera->StartGrabbing(1,GrabStrategy_LatestImageOnly);
    m_camera->RetrieveResult( 5000, cGrabResultPtr, TimeoutHandling_Return);
    if (cGrabResultPtr->GrabSucceeded())
    {
        cImageFormatConverter.Convert(cPylonImage, cGrabResultPtr);
        cv::Mat openCvImage= cv::Mat(cGrabResultPtr->GetHeight(), cGrabResultPtr->GetWidth(), CV_8UC3, (uint8_t *) cPylonImage.GetBuffer());
        cvtColor(openCvImage, openCvImage, CV_BGR2RGB);
        return QImage( openCvImage.data, openCvImage.cols, \
                             openCvImage.rows, openCvImage.step, \
                             QImage::Format_RGB888);
    }else{
        qDebug("ShotImageOne Fail");
        qDebug(cGrabResultPtr->GetErrorDescription());
        return QImage();
    }
}

void Camera::ShotImageContinue( )
{

}

void Camera::SaveImageOne( )
{

}

void Camera::SaveImageContinue( )
{

}

