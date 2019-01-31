#ifndef _TTX_STREAM_WORK_H_
#define _TTX_STREAM_WORK_H_

#include "ttxdvrnetapi.h"
#include <stdio.h>
#define TTX_MEDIA_AV			1		//实时视频
#define TTX_MEDIA_TALKBACK		2		//对讲
#define TTX_MEDIA_LISTEN		3		//监听

class CTTXStreamWork : public CTTXNetWork
{
private:
	static CTTXStreamWork* g_pTTXNet;
	friend CTTXStreamWork* TTXStreamIns();
	friend void DelTTXStream();

private:
	CTTXStreamWork();
	virtual ~CTTXStreamWork();

public:
	void SetDevIDNO(const char* szDevIDNO) {	strncpy(m_szDevIDNO, szDevIDNO, sizeof(m_szDevIDNO) - 1);	}
	void SetUpdatePath(const char* szUpdateFilePath) {	strncpy(mUpdateFilePath, szUpdateFilePath, sizeof(mUpdateFilePath) - 1);	}
	const char* GetDevIDNO() const {	return m_szDevIDNO;	}
	void SetSvrInfo(const char* szSvrIP, unsigned short usPort) 
	{
		strncpy(m_szSvrIP, szSvrIP, sizeof(m_szSvrIP) - 1);
		m_usSvrPort = usPort;
	}
	const char* GetSvrIP() 		const {	return m_szSvrIP;	}
	unsigned short GetSvrPort() 	const {	return m_usSvrPort;	}
	void SetFactoryType(int FactoryType)
	{
		m_FactoryType = FactoryType;
	}


public:
//    /*****************************************************************************
//    * @ 控制指令业务
//    ******************************************************************************/
//    //鉴权处理
//    //@szSvrAuthKey服务器下发的鉴权码，可以判断此鉴权码是否满足一定的规则
//    //        如果是则表示服务器版本是对的，如果不对，则设备主动中断链接
//    //        然后再对szSvrAuthKey进行加密返回串数据给服务器
//    //        服务器对szDevAuthKey数据进行解密匹配，如果不满足规则，则会中断连接
//    //@szDevAuthKey设备对szSvrAuthKey进行加密后，返回给服务器的数据
//    //@nDevAuthKeyLen，表示szDevAuthKey的长度(这个长度不超过260个字节)
//    //如果返回失败，则会中断链接
//    virtual bool DoAuthentication(const char* szSvrAuthKey, char* szDevAuthKey, int nDevAuthKeyLen);
//    
//    //获取网络参数，搜索设备时使用
//    //@netParam: 网络参数
//    virtual bool DoGetNetParam(TTXNetParam_S& netParam);
//
//    //指令处理
//    //TTS语音处理
    virtual bool DoTtsVoice(const char* szText);
//
//    //接收到透明串口数据
//    virtual void DoRecvTransparentSerial(int nType, const unsigned char* pBuffer, int nLength);
//
//    //文件上传完成
//    //@szFile: 文件名绝对路径
    virtual void DoFileUploadFinish(const char* szFile);
//
//    //发送控制指令
//    //@nCtrlType: 控制类型
//    virtual bool DoControl(int nCtrlType);
//    
//    //参数处理透传
//    //@nType: 参数类型
//    //@pInConfig: PC传入的参数信息
//    //@pOutConfig: 设备返回的参数信息
//    virtual bool DoTransparentConfig(int nType, const LPTTXConfigData_S pInConfig, LPTTXConfigData_S pOutConfig);
//
//
public:
//    /*****************************************************************************
//    * @ 媒体业务
//    ******************************************************************************/
//    
//    /*****************************************************************************
//    //取得视频通道的分辨率
//    //@nChannel: 通道号从0开始
//    //@nStreamType: 码流类型，媒体类型为视频时有效TTX_STREAM_TYPE_MAIN
//    //@nResolution: 默认分辨率TTX_RESOLUTION_CIF
//    //@nFrameBufLen: 帧长度返回0时，则由SDK决定缓存大小
//    //     QCIF和CIF为300K缓存
//    //    HD1和D1为1200K 缓存
//    //    720P为4800K缓存
//    //    1080P为19200K 缓存
//    ******************************************************************************/
    virtual bool GetVideoResolution(int nChannel, int nStreamType, int& nResolution, int& nFrameBufLen);
//
//    /*****************************************************************************
//    //启动音视频编码，服务器请求实时视频和声音监听时将调用此接口
//    //也需要知道音频的格式参数
//    //@nMediaType: 媒体类型，TTX_MEDIA_TYPE_AV 或者TTX_MEDIA_TYPE_AUDIO
//    //@nChannel: 通道号从0开始，如果为音频时，nChannel还可以为麦克通道
//    //@nStreamType: 码流类型，媒体类型为视频时有效
//    //@pfnEncoderCB: 数据回调函数
//    //@pEncUsr: 编码回调函数用户自定义数据
//    //@ppAVUsr: 编码对象用户自定义数据，返回给网络库，在StopAVEnc，将此参数传回
//    //上层保存pfnEncoderCB和pUsr，在编码产生数据时，通过此接口告诉网络层
//    //上层将音视频数据按顺序传送给网络库
//    //网络库模块不发送音频数据，但客户端请求音频后，才发送音频
//    ******************************************************************************/
    virtual bool StartAVEnc(int nMediaType, int nChannel, int nStreamType, TTXPfnAVEncoderCB pfnEncoderCB, void* pEncUsr, void** ppAVUsr);
//
//    /*****************************************************************************
//    //停止音视频编码，服务器停止实时视频和声音监听时将调用此接口
//    //@nMediaType: 媒体类型，TTX_MEDIA_TYPE_AV 或者TTX_MEDIA_TYPE_AUDIO
//    //@nChannel: 通道号从0开始
//    //@nStreamType: 码流类型
//    //@pAVUsr: 在StartAVEnc里面输入的pAVUsr参数
//    //调用此接口后，上层必须停止调用数据回调函数
//    ******************************************************************************/
    virtual bool StopAVEnc(int nMediaType, int nChannel, int nStreamType, void* pAVUsr);
//
//    /*****************************************************************************
//    //请求I帧
//    //@nChannel: 通道号从0开始
//    //@nStreamType: 码流类型
//    //当一个新的客户端连接到媒体服务器时，服务器要求设备立刻产生一个I帧数据
//    //由于3G网络传送I帧间隔一般都比较长，及时产生I帧，可以让客户端及时看到视频
//    ******************************************************************************/
    virtual bool AVEncIFrame(int nChannel, int nStreamType);
//
//    /*****************************************************************************
//    //启动双向对讲
//    //@nChannel: 通道号从0开始，表示麦克通道，从0开始
//    //@pfnEncoderCB: 编码回调
//    //@pEncUsr: 编码回调用户自定义数据
//    //@ppDecUsr: 用户解码回调自字义函数，在
//    //双向对讲时，将编码数据不停通过pfnEncoderCB，通知给网络层
//    //设备启动音频解码器
//    ******************************************************************************/
//    virtual bool StartTalkback(int nChannel, TTXPfnAVEncoderCB pfnEncoderCB, void* pEncUsr, void** ppTalkUsr);
//
//    /*****************************************************************************
//    //停止双向对讲
//    //@nChannel: 通道号从0开始，表示麦克通道，从0开始
//    //@pTalkUsr: 在StartTalkback里面输入的ppTalkUsr参数
//    //设备可以关闭音频解码器
//    ******************************************************************************/
//    virtual bool StopTalkback(int nChannel, void* pTalkUsr);
//    
//    /*****************************************************************************
//    //设置解码的音频参数
//    //@nChannel: 麦克通道
//    //@nAudioType: 音频类型TTX_AUDIO_TYPE_G726_40KBPS 等
//    //@nFrmLength: 每个音频帧的数据长度
//    //@pTalkUsr: 在StartTalkback里面输入的ppTalkUsr参数
//    //调用此接口后，上层必须停止调用数据回调函数
//    ******************************************************************************/
//    virtual void TalkSetAudioParam(int nChannel, int nAudioType, int nFrmLength, void* pTalkUsr);
//
//    /*****************************************************************************
//    //解码对讲数据
//    //@nLength: 音频长度
//    //@u64Stamp: 时间戳
//    //@pData: 音频数据
//    //@pTalkUsr: 在StartTalkback里面输入的ppTalkUsr参数
//    //调用此接口后，上层必须停止调用数据回调函数
//    ******************************************************************************/
//    virtual void TalkDecoder(int nChannel, int nLength, unsigned long long u64Stamp, const char* pData, void* pTalkUsr);
//
//
//    /*****************************************************************************
//    //启动文件查找
//    //@nYear: 年
//    //@nMonth: 月
//    //@nDay: 日
//    //@nBeginTime: 开始时间，以秒为单位
//    //@nEndTime: 结束时间，以秒为单位
//    //@nRecType: 录像类型
//    //@nChannel: 录像对应的通道
//    //@pfnRecFindCB: 文件回调函数
//    //@pFindUsr: 文件查找用户自定义数据
//    //@pfnGetExitCB: 判断是否需要退出
//    //@pExitUsr: 判断退出函数
//    //网络库启动一个文件查找线程，进行录像文件查找
//    //文件查找过程中，需要不停调用pfnGetExitCB，来判断是否需要退出
//    //查找到文件，及时调用pfnRecFindCB，调用上层
//    //查找过程中，每 个循环应当调用usleep(0)，避免CPU占用率高
//    ******************************************************************************/
//    virtual void FindRecFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nRecType, int nChannel
//                    , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr) ;
//                    
//    /*****************************************************************************
//    //启动图片文件查找
//    //@nYear: 年
//    //@nMonth: 月
//    //@nDay: 日
//    //@nBeginTime: 开始时间，以秒为单位
//    //@nEndTime: 结束时间，以秒为单位
//    //@nType: 文件类型
//    //@nChannel: 录像对应的通道
//    //@pfnRecFindCB: 文件回调函数
//    //@pFindUsr: 文件查找用户自定义数据
//    //@pfnGetExitCB: 判断是否需要退出
//    //@pExitUsr: 判断退出函数
//    //文件查找过程中，需要不停调用pfnGetExitCB，来判断是否需要退出
//    //查找到文件，及时调用pfnRecFindCB，调用上层
//    ******************************************************************************/
//    virtual void FindJpegFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nType, int nChannel
//                    , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr) ;
//    /*****************************************************************************
//    //启动日志文件
//    //@nYear: 年
//    //@nMonth: 月
//    //@nDay: 日
//    //@nBeginTime: 开始时间，以秒为单位
//    //@nEndTime: 结束时间，以秒为单位
//    //@nType: 文件类型
//    //@nChannel: 录像对应的通道
//    //@pfnRecFindCB: 文件回调函数
//    //@pFindUsr: 文件查找用户自定义数据
//    //@pfnGetExitCB: 判断是否需要退出
//    //@pExitUsr: 判断退出函数
//    //文件查找过程中，需要不停调用pfnGetExitCB，来判断是否需要退出
//    //查找到文件，及时调用pfnRecFindCB，调用上层
//    ******************************************************************************/
//    virtual void FindLogFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nType, int nChannel
//                    , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr);                    
//    /*****************************************************************************
//    //设备进行图片抓拍操作，并将图片保存到文件中
//    //并将文件路径返回给网络库
//    //网络库将保存好的图片传送到服务器上
//    //@nChannel: 通道信息
//    //@szFileName: 图片文件名称，全路径
//    //@bDelete: 表示文件上传完成后，是否执行删除文件操作
//    //设备可以将图片存储到硬盘上，也可以存储到内存中
//    //如果设备没有硬盘，则建议存储到内存文件中
//    ******************************************************************************/
//    virtual bool Snapshot(int nChannel, char* szFileName, bool& bDelete) ;
//
//    /*****************************************************************************
//    //通知进行录像回放操作
//    //@szFile: 录像文件名称
//    //@ppRecFile:上层 需要创建录像解析对象子类返回给SDK，SDK调用此对象将文件解析成帧信息
//    //如果返回false，则表示文件不存在
//    //调用流程
//    //    1、先InitRecFile，取得文件解析对象
//    //     2、pRecFile->OpenFile，调用文件解析对象打开文件接口
//    //    3、pRecFile->GetFileInfo，取得文件信息
//    //    4、pRecFile->ReadFrame，读取帧数据
//    ******************************************************************************/
//    virtual bool InitRecFile(CTTXRecFile** ppRecFile) ;
//    
//    /*****************************************************************************
//    //释放文件解析对象
//    //@pRecFile: 录像解析对象，此对象由InitRecFile 接口创建
//    ******************************************************************************/
//    virtual void FreeRecFile(CTTXRecFile* pRecFile) ;
//
//
//    //设备升级
//    //校验升级版本
//    virtual bool CheckUpgradeVer(const char* szVer);
//    //获取升级文件存储路径
//    virtual bool GetUpgradeFile(char* szFileName);
//    //校验升级文件
//    virtual bool CheckUpgradeFile(const char* szFileName);
//    //进行设备升级
//    virtual void UpgradeDevice(const char* szFileName);
//
//    //获取软件版本信息
//    //@szVersion: 版本信息
//    //@nVerLen: szVersion缓存的长度, 上层拷贝长度不得超过此长度
//    virtual void GetSoftwareVersion(char* szVersion, int nVerLen) ;
//    //获取视频状态(视频丢失和录像状态)
//    //@nVideoLost: 第0位表示通道1,  值为1表示视频丢失
//    //@nVideoRecord: 第0位表示通道1,  值为1表示正在录像
//    virtual void GetVideoStatus(int& nVideoLost, int& nVideoRecord) ;
//    //获取磁盘信息
//    //@nDiskCount: 磁盘数目
//    //@szDiskValue: 16000_8000_32000_8000 格式, 单位MB, 16000表示所有空间为16000MB, 8000表示剩余空间为8000MB
//    //          如果0_0  则表示硬盘出错
//    //        中间使用_   分隔
//    //@nDiskValLen: szDiskValue缓存的长度, 上层拷贝长度不得超过此长度
//    virtual void GetDiskInfo(int& nDiskCount, char* szDiskValue, int nDiskValLen) ;
//    
//    //获取3G状态
//    //@n3GStatus: 0表示无效，1表示有效
//    //@n3GType: 网络类型0表示2G,  1表示EVDO,  2表示WCDMA, 3表示TD-WCDMA, 4 TD_LED , 5 FDD
//    //@sz3GAddress: 3G拔号后的地址
//    
//    virtual void Get3GStatus(int &n3GStatus, int& n3GType, char* sz3GAddress, int n3GAddrLen) ;
//    //获取WIFI状态
//    //@nWifiStatus: 0表示无效，1表示有效
//    //@szWifiAddress: WIFI  的网络地址
//    //@nWifiAddrLen: WIFI  的网络地址
//    virtual void GetWifiStatus(int &nWifiStatus, char* szWifiAddress, int nWifiAddrLen) ;
	

protected:
	bool 	GetJpgFileTime(const char* szJpgFile, TTXRecFile_S& RFile);
	const char*  CheckJpgFileName(const char* szJpgFile);

	bool GetFactoryRecTime(const char* szFactoryRecFile, TTXRecFile_S& RFile);
	const char* CheckFactoryRecordName(const char* szFactoryRecFile);
	
	
private:
	char	m_szDevIDNO[64];
	char 	mUpdateFilePath[256];
	char    mszVer[64];
	char	m_szSvrIP[64];
	unsigned short m_usSvrPort;
	int m_FactoryType;
	char	m_szWifiIP[64];//WifiIP地址
	char	m_sz3gIP[64];//3gIP地址
	char	m_szVersion[64];//版本信息
	char	m_szDiskValue[64];//磁盘容量
};

//void CallBackTtsVoice(const char* szText);
//void CallBackTransparent(int nType, const char* pBuffer, int nLength);
//bool CallBackConfig(int nType, const char* szInt, char* szOut, int& nOutLen);
////bool CallBackMedia(int nType, int nChannel, int nStream, int bStart);
void CallBackFileUploadFinished(const char* szFile);
//bool CallBackSnapshot(int channel, char* szFileName);
//void CallBackUpgradeDev(const char* szUpgradeFileName);
//void CallBackDoControl(int nCtrlType);
//bool CallBackDevInfo(int nType, const char* szInt, char* szOut, int& nOutLen);
CTTXStreamWork* TTXStreamIns();
void DelTTXStream();

//new
//bool CallBackMediaStartAVEnc(int nMediaType, int nChannel, int nStreamType, TTXPfnAVEncoderCB pfnEncoderCB, void* pEncUsr, void** ppAVUsr);







#endif

