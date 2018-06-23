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
    qsFilePath = QDir::homePath() + "/" + "images/";
    qsFilePrefix = "capture";
}

Camera::~Camera()
{

}

int Camera::Open()
{
    PylonInitialize();
    try{
        // Only look for cameras supported by Camera_t
        CDeviceInfo info;
        info.SetDeviceClass( Camera_t::DeviceClass());
        // Create an instant camera object with the first found camera device matching the specified device class.
        m_camera = new Camera_t( CTlFactory::GetInstance().CreateFirstDevice( info));
        m_camera->Open();
        qDebug("Open Camera Successful");
        m_camera->PixelFormat.SetValue(PixelFormat_Mono8);    ///<设置相机传输的像素数据的格式。
        m_camera->Width.SetValue(2064);     ///<相机的兴趣区的宽度（以像素为单位）。
        m_camera->Height.SetValue(1544);    ///<相机的兴趣区的高度（以像素为单位）
        m_camera->TriggerSelector.SetValue(TriggerSelector_FrameStart);
        m_camera->TriggerMode.SetValue(TriggerMode_Off);
        m_camera->ExposureMode.SetValue(ExposureMode_Timed);
        m_camera->ExposureTimeAbs.SetValue(5000.0);
        m_camera->GevStreamChannelSelector.SetValue(GevStreamChannelSelector_StreamChannel0);
        ///所选数据流通道上的每个数据包的传输之间的延迟。
        ///所选数据流通道上的每个数据包的传输之间的延迟。以 tick 为单位测量延迟。
        m_camera->GevSCPD.SetValue(350);
        m_camera->AcquisitionFrameRateAbs.SetValue(50);
        m_camera->AcquisitionFrameRateEnable.SetValue(true);
        return CAMERA_OK;
    }catch(GenICam::GenericException e){
        qDebug("Open Camera Fail");
        qDebug(e.GetDescription());
        return CAMERA_FAIL;
    }
}

bool Camera::IsOpen()
{
    return m_camera->IsOpen();
}

int Camera::Close()
{
    if( true == m_camera->IsGrabbing() ){
        m_camera->StopGrabbing();
    }
    if( false == m_camera->IsOpen() )
    {
        return CAMERA_FAIL;
    }
    try {
        if( m_camera->IsOpen() )
        {
            m_camera->DetachDevice();
            m_camera->Close();
        }
        PylonTerminate();
        return CAMERA_OK;
    } catch (GenICam::GenericException e) {
        qDebug("Close Camera Fail");
        qDebug(e.GetDescription());
        return CAMERA_FAIL;
    }
}

void Camera::SetGainAuto( GainAutoEnums gainAuto )
{
    m_camera->GainAuto.SetValue( gainAuto );
}

GainAutoEnums Camera::GetGainAuto( )
{
    return m_camera->GainAuto.GetValue();
}

void Camera::SetGainSelector( GainSelectorEnums gainAuto )
{
    m_camera->GainSelector.SetValue( gainAuto );
}

GainSelectorEnums Camera::GetGainSelector( )
{
    return m_camera->GainSelector.GetValue();
}

///***************************AOI CONFIG*********************************///
void Camera::SetWidth( int64_t width )
{
    m_camera->Width.SetValue( width );
}

int64_t Camera::GetWidth()
{
    return m_camera->Width.GetValue();
}

void Camera::SetHeight(int64_t height )
{
    m_camera->Height.SetValue( height );
}

int64_t Camera::GetHeight()
{
    return m_camera->Height.GetValue();
}

void Camera::SetOffsetX(int64_t offsetX )
{
    m_camera->OffsetX.SetValue( offsetX );
}

int64_t Camera::GetOffsetX()
{
    return m_camera->OffsetX.GetValue();
}

void Camera::SetOffsetY(int64_t offsetY )
{
    m_camera->OffsetY.SetValue( offsetY );
}

int64_t Camera::GetOffsetY()
{
    return m_camera->OffsetY.GetValue();
}

///***************************Trigger CONFIG*********************************///
void Camera::SetTriggerSelector( TriggerSelectorEnums triggerSelector )
{
    m_camera->TriggerSelector.SetValue( triggerSelector );
}

TriggerSelectorEnums Camera::GetTriggerSelector()
{
    return m_camera->TriggerSelector.GetValue();
}

void Camera::SetTriggerMode( TriggerModeEnums triggerMode )
{
    m_camera->TriggerMode.SetValue(triggerMode);
}

TriggerModeEnums Camera::GetTriggerMode()
{
    return m_camera->TriggerMode.GetValue();
}

void Camera::SetTriggerSource( TriggerSourceEnums triggerSource )
{
    m_camera->TriggerSource.SetValue( triggerSource );
}

TriggerSourceEnums Camera::GetTriggerSource()
{
    return m_camera->TriggerSource.GetValue();
}

void Camera::SetTriggerActivation( TriggerActivationEnums triggerActivation )
{
    m_camera->TriggerActivation.SetValue( triggerActivation );
}

TriggerActivationEnums Camera::GetTriggerActivation()
{
    return m_camera->TriggerActivation.GetValue();
}

void Camera::SetTrigger(TriggerSelectorEnums triggerSelector, \
                        TriggerModeEnums triggerMode, \
                        TriggerSourceEnums triggerSource, \
                        TriggerActivationEnums triggerActivation)
{
    SetTriggerSelector(triggerSelector);
    SetTriggerMode(triggerMode);
    SetTriggerSource(triggerSource);
    SetTriggerActivation(triggerActivation);
}

void Camera::GetTrigger(TriggerSelectorEnums *triggerSelector, \
                        TriggerModeEnums *triggerMode, \
                        TriggerSourceEnums *triggerSource, \
                        TriggerActivationEnums *triggerActivation)
{
    *triggerSelector = GetTriggerSelector();
    *triggerMode = GetTriggerMode();
    *triggerSource = GetTriggerSource();
    *triggerActivation = GetTriggerActivation();
}

///***************************Trigger CONFIG End *****************************///

///***************************Exposure CONFIG Start***************************///
void Camera::SetExposureMode(ExposureModeEnums triggerActivation )
{
    m_camera->ExposureMode.SetValue( triggerActivation );
}

ExposureModeEnums Camera::GetExposureMode()
{
    return m_camera->ExposureMode.GetValue();
}

void Camera::SetExposureAuto(ExposureAutoEnums triggerActivation )
{
    m_camera->ExposureAuto.SetValue( triggerActivation );
}

ExposureAutoEnums Camera::GetExposureAuto()
{
    return m_camera->ExposureAuto.GetValue();
}

void Camera::SetExposureTime( double time )
{
    m_camera->ExposureTimeAbs.SetValue( time );
}

double Camera::GetExposureTime()
{
    return m_camera->ExposureTimeAbs.GetValue();
}

QPixmap Camera::ShotImageOne( )
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
        cv::Mat openCvImage= cv::Mat(cGrabResultPtr->GetHeight(),
                                     cGrabResultPtr->GetWidth(),
                                     CV_8UC1,
                                     (uint8_t *) cPylonImage.GetBuffer());
        ///lwj  ???直接返回qImage错误
        /// 直接返回qImage对象在外部调用后的图像不正常，先以QPixmap类型返回
        QImage qImage( openCvImage.data, \
                       openCvImage.cols, \
                       openCvImage.rows, \
                       openCvImage.step, \
                       QImage::Format_Mono);
        QPixmap pix = QPixmap::fromImage(qImage);
        qDebug("ShotImageOne Successful");
        return pix;
    }else{
        qDebug("ShotImageOne Fail");
        qDebug(cGrabResultPtr->GetErrorDescription());
        return QPixmap();
    }
}

bool Camera::ShotImageOne( cv::Mat *pMat )
{
    if( NULL == pMat)
    {
        return CAMERA_FAIL;
    }
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
        qDebug("ShotImageOne Successful");
        *pMat = cv::Mat(cGrabResultPtr->GetHeight(),
                       cGrabResultPtr->GetWidth(),
                       CV_8UC1,
                       (uint8_t *) cPylonImage.GetBuffer());
        return CAMERA_OK;
    }else{
        qDebug("ShotImageOne Fail");
        qDebug(cGrabResultPtr->GetErrorDescription());
        return CAMERA_FAIL;
    }
}

void Camera::ShotImageContinue( )
{

}

void Camera::SaveImageOne( QString qsImagePath )
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
        cv::Mat openCvImage= cv::Mat(cGrabResultPtr->GetHeight(),
                                     cGrabResultPtr->GetWidth(),
                                     CV_8UC1,
                                     (uint8_t *) cPylonImage.GetBuffer());
        cv::imwrite(qsImagePath.toStdString(), openCvImage);
        qDebug("SaveImageOne Successful");
    }else{
        qDebug("SaveImageOne Fail");
        qDebug(cGrabResultPtr->GetErrorDescription());
    }
}

void Camera::SaveImageContinue( )
{

}

void Camera::SetFilePath(QString qsFilePath)
{
    this->qsFilePath = qsFilePath;
}

QString Camera::GetFilePath()
{
    return this->qsFilePath;
}

void Camera::SetFilePrefix(QString qsFilePrefix)
{
    this->qsFilePrefix = qsFilePrefix;
}

QString Camera::GetFilePrefix()
{
    return this->qsFilePrefix;
}
