#ifndef _TTX_STREAM_WORK_H_
#define _TTX_STREAM_WORK_H_

#include "ttxdvrnetapi.h"
#include <stdio.h>
#define TTX_MEDIA_AV			1		//ʵʱ��Ƶ
#define TTX_MEDIA_TALKBACK		2		//�Խ�
#define TTX_MEDIA_LISTEN		3		//����

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
//    * @ ����ָ��ҵ��
//    ******************************************************************************/
//    //��Ȩ����
//    //@szSvrAuthKey�������·��ļ�Ȩ�룬�����жϴ˼�Ȩ���Ƿ�����һ���Ĺ���
//    //        ��������ʾ�������汾�ǶԵģ�������ԣ����豸�����ж�����
//    //        Ȼ���ٶ�szSvrAuthKey���м��ܷ��ش����ݸ�������
//    //        ��������szDevAuthKey���ݽ��н���ƥ�䣬����������������ж�����
//    //@szDevAuthKey�豸��szSvrAuthKey���м��ܺ󣬷��ظ�������������
//    //@nDevAuthKeyLen����ʾszDevAuthKey�ĳ���(������Ȳ�����260���ֽ�)
//    //�������ʧ�ܣ�����ж�����
//    virtual bool DoAuthentication(const char* szSvrAuthKey, char* szDevAuthKey, int nDevAuthKeyLen);
//    
//    //��ȡ��������������豸ʱʹ��
//    //@netParam: �������
//    virtual bool DoGetNetParam(TTXNetParam_S& netParam);
//
//    //ָ���
//    //TTS��������
    virtual bool DoTtsVoice(const char* szText);
//
//    //���յ�͸����������
//    virtual void DoRecvTransparentSerial(int nType, const unsigned char* pBuffer, int nLength);
//
//    //�ļ��ϴ����
//    //@szFile: �ļ�������·��
    virtual void DoFileUploadFinish(const char* szFile);
//
//    //���Ϳ���ָ��
//    //@nCtrlType: ��������
//    virtual bool DoControl(int nCtrlType);
//    
//    //��������͸��
//    //@nType: ��������
//    //@pInConfig: PC����Ĳ�����Ϣ
//    //@pOutConfig: �豸���صĲ�����Ϣ
//    virtual bool DoTransparentConfig(int nType, const LPTTXConfigData_S pInConfig, LPTTXConfigData_S pOutConfig);
//
//
public:
//    /*****************************************************************************
//    * @ ý��ҵ��
//    ******************************************************************************/
//    
//    /*****************************************************************************
//    //ȡ����Ƶͨ���ķֱ���
//    //@nChannel: ͨ���Ŵ�0��ʼ
//    //@nStreamType: �������ͣ�ý������Ϊ��Ƶʱ��ЧTTX_STREAM_TYPE_MAIN
//    //@nResolution: Ĭ�Ϸֱ���TTX_RESOLUTION_CIF
//    //@nFrameBufLen: ֡���ȷ���0ʱ������SDK���������С
//    //     QCIF��CIFΪ300K����
//    //    HD1��D1Ϊ1200K ����
//    //    720PΪ4800K����
//    //    1080PΪ19200K ����
//    ******************************************************************************/
    virtual bool GetVideoResolution(int nChannel, int nStreamType, int& nResolution, int& nFrameBufLen);
//
//    /*****************************************************************************
//    //��������Ƶ���룬����������ʵʱ��Ƶ����������ʱ�����ô˽ӿ�
//    //Ҳ��Ҫ֪����Ƶ�ĸ�ʽ����
//    //@nMediaType: ý�����ͣ�TTX_MEDIA_TYPE_AV ����TTX_MEDIA_TYPE_AUDIO
//    //@nChannel: ͨ���Ŵ�0��ʼ�����Ϊ��Ƶʱ��nChannel������Ϊ���ͨ��
//    //@nStreamType: �������ͣ�ý������Ϊ��Ƶʱ��Ч
//    //@pfnEncoderCB: ���ݻص�����
//    //@pEncUsr: ����ص������û��Զ�������
//    //@ppAVUsr: ��������û��Զ������ݣ����ظ�����⣬��StopAVEnc�����˲�������
//    //�ϲ㱣��pfnEncoderCB��pUsr���ڱ����������ʱ��ͨ���˽ӿڸ��������
//    //�ϲ㽫����Ƶ���ݰ�˳���͸������
//    //�����ģ�鲻������Ƶ���ݣ����ͻ���������Ƶ�󣬲ŷ�����Ƶ
//    ******************************************************************************/
    virtual bool StartAVEnc(int nMediaType, int nChannel, int nStreamType, TTXPfnAVEncoderCB pfnEncoderCB, void* pEncUsr, void** ppAVUsr);
//
//    /*****************************************************************************
//    //ֹͣ����Ƶ���룬������ֹͣʵʱ��Ƶ����������ʱ�����ô˽ӿ�
//    //@nMediaType: ý�����ͣ�TTX_MEDIA_TYPE_AV ����TTX_MEDIA_TYPE_AUDIO
//    //@nChannel: ͨ���Ŵ�0��ʼ
//    //@nStreamType: ��������
//    //@pAVUsr: ��StartAVEnc���������pAVUsr����
//    //���ô˽ӿں��ϲ����ֹͣ�������ݻص�����
//    ******************************************************************************/
    virtual bool StopAVEnc(int nMediaType, int nChannel, int nStreamType, void* pAVUsr);
//
//    /*****************************************************************************
//    //����I֡
//    //@nChannel: ͨ���Ŵ�0��ʼ
//    //@nStreamType: ��������
//    //��һ���µĿͻ������ӵ�ý�������ʱ��������Ҫ���豸���̲���һ��I֡����
//    //����3G���紫��I֡���һ�㶼�Ƚϳ�����ʱ����I֡�������ÿͻ��˼�ʱ������Ƶ
//    ******************************************************************************/
    virtual bool AVEncIFrame(int nChannel, int nStreamType);
//
//    /*****************************************************************************
//    //����˫��Խ�
//    //@nChannel: ͨ���Ŵ�0��ʼ����ʾ���ͨ������0��ʼ
//    //@pfnEncoderCB: ����ص�
//    //@pEncUsr: ����ص��û��Զ�������
//    //@ppDecUsr: �û�����ص������庯������
//    //˫��Խ�ʱ�����������ݲ�ͣͨ��pfnEncoderCB��֪ͨ�������
//    //�豸������Ƶ������
//    ******************************************************************************/
//    virtual bool StartTalkback(int nChannel, TTXPfnAVEncoderCB pfnEncoderCB, void* pEncUsr, void** ppTalkUsr);
//
//    /*****************************************************************************
//    //ֹͣ˫��Խ�
//    //@nChannel: ͨ���Ŵ�0��ʼ����ʾ���ͨ������0��ʼ
//    //@pTalkUsr: ��StartTalkback���������ppTalkUsr����
//    //�豸���Թر���Ƶ������
//    ******************************************************************************/
//    virtual bool StopTalkback(int nChannel, void* pTalkUsr);
//    
//    /*****************************************************************************
//    //���ý������Ƶ����
//    //@nChannel: ���ͨ��
//    //@nAudioType: ��Ƶ����TTX_AUDIO_TYPE_G726_40KBPS ��
//    //@nFrmLength: ÿ����Ƶ֡�����ݳ���
//    //@pTalkUsr: ��StartTalkback���������ppTalkUsr����
//    //���ô˽ӿں��ϲ����ֹͣ�������ݻص�����
//    ******************************************************************************/
//    virtual void TalkSetAudioParam(int nChannel, int nAudioType, int nFrmLength, void* pTalkUsr);
//
//    /*****************************************************************************
//    //����Խ�����
//    //@nLength: ��Ƶ����
//    //@u64Stamp: ʱ���
//    //@pData: ��Ƶ����
//    //@pTalkUsr: ��StartTalkback���������ppTalkUsr����
//    //���ô˽ӿں��ϲ����ֹͣ�������ݻص�����
//    ******************************************************************************/
//    virtual void TalkDecoder(int nChannel, int nLength, unsigned long long u64Stamp, const char* pData, void* pTalkUsr);
//
//
//    /*****************************************************************************
//    //�����ļ�����
//    //@nYear: ��
//    //@nMonth: ��
//    //@nDay: ��
//    //@nBeginTime: ��ʼʱ�䣬����Ϊ��λ
//    //@nEndTime: ����ʱ�䣬����Ϊ��λ
//    //@nRecType: ¼������
//    //@nChannel: ¼���Ӧ��ͨ��
//    //@pfnRecFindCB: �ļ��ص�����
//    //@pFindUsr: �ļ������û��Զ�������
//    //@pfnGetExitCB: �ж��Ƿ���Ҫ�˳�
//    //@pExitUsr: �ж��˳�����
//    //���������һ���ļ������̣߳�����¼���ļ�����
//    //�ļ����ҹ����У���Ҫ��ͣ����pfnGetExitCB�����ж��Ƿ���Ҫ�˳�
//    //���ҵ��ļ�����ʱ����pfnRecFindCB�������ϲ�
//    //���ҹ����У�ÿ ��ѭ��Ӧ������usleep(0)������CPUռ���ʸ�
//    ******************************************************************************/
//    virtual void FindRecFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nRecType, int nChannel
//                    , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr) ;
//                    
//    /*****************************************************************************
//    //����ͼƬ�ļ�����
//    //@nYear: ��
//    //@nMonth: ��
//    //@nDay: ��
//    //@nBeginTime: ��ʼʱ�䣬����Ϊ��λ
//    //@nEndTime: ����ʱ�䣬����Ϊ��λ
//    //@nType: �ļ�����
//    //@nChannel: ¼���Ӧ��ͨ��
//    //@pfnRecFindCB: �ļ��ص�����
//    //@pFindUsr: �ļ������û��Զ�������
//    //@pfnGetExitCB: �ж��Ƿ���Ҫ�˳�
//    //@pExitUsr: �ж��˳�����
//    //�ļ����ҹ����У���Ҫ��ͣ����pfnGetExitCB�����ж��Ƿ���Ҫ�˳�
//    //���ҵ��ļ�����ʱ����pfnRecFindCB�������ϲ�
//    ******************************************************************************/
//    virtual void FindJpegFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nType, int nChannel
//                    , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr) ;
//    /*****************************************************************************
//    //������־�ļ�
//    //@nYear: ��
//    //@nMonth: ��
//    //@nDay: ��
//    //@nBeginTime: ��ʼʱ�䣬����Ϊ��λ
//    //@nEndTime: ����ʱ�䣬����Ϊ��λ
//    //@nType: �ļ�����
//    //@nChannel: ¼���Ӧ��ͨ��
//    //@pfnRecFindCB: �ļ��ص�����
//    //@pFindUsr: �ļ������û��Զ�������
//    //@pfnGetExitCB: �ж��Ƿ���Ҫ�˳�
//    //@pExitUsr: �ж��˳�����
//    //�ļ����ҹ����У���Ҫ��ͣ����pfnGetExitCB�����ж��Ƿ���Ҫ�˳�
//    //���ҵ��ļ�����ʱ����pfnRecFindCB�������ϲ�
//    ******************************************************************************/
//    virtual void FindLogFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nType, int nChannel
//                    , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr);                    
//    /*****************************************************************************
//    //�豸����ͼƬץ�Ĳ���������ͼƬ���浽�ļ���
//    //�����ļ�·�����ظ������
//    //����⽫����õ�ͼƬ���͵���������
//    //@nChannel: ͨ����Ϣ
//    //@szFileName: ͼƬ�ļ����ƣ�ȫ·��
//    //@bDelete: ��ʾ�ļ��ϴ���ɺ��Ƿ�ִ��ɾ���ļ�����
//    //�豸���Խ�ͼƬ�洢��Ӳ���ϣ�Ҳ���Դ洢���ڴ���
//    //����豸û��Ӳ�̣�����洢���ڴ��ļ���
//    ******************************************************************************/
//    virtual bool Snapshot(int nChannel, char* szFileName, bool& bDelete) ;
//
//    /*****************************************************************************
//    //֪ͨ����¼��طŲ���
//    //@szFile: ¼���ļ�����
//    //@ppRecFile:�ϲ� ��Ҫ����¼������������෵�ظ�SDK��SDK���ô˶����ļ�������֡��Ϣ
//    //�������false�����ʾ�ļ�������
//    //��������
//    //    1����InitRecFile��ȡ���ļ���������
//    //     2��pRecFile->OpenFile�������ļ�����������ļ��ӿ�
//    //    3��pRecFile->GetFileInfo��ȡ���ļ���Ϣ
//    //    4��pRecFile->ReadFrame����ȡ֡����
//    ******************************************************************************/
//    virtual bool InitRecFile(CTTXRecFile** ppRecFile) ;
//    
//    /*****************************************************************************
//    //�ͷ��ļ���������
//    //@pRecFile: ¼��������󣬴˶�����InitRecFile �ӿڴ���
//    ******************************************************************************/
//    virtual void FreeRecFile(CTTXRecFile* pRecFile) ;
//
//
//    //�豸����
//    //У�������汾
//    virtual bool CheckUpgradeVer(const char* szVer);
//    //��ȡ�����ļ��洢·��
//    virtual bool GetUpgradeFile(char* szFileName);
//    //У�������ļ�
//    virtual bool CheckUpgradeFile(const char* szFileName);
//    //�����豸����
//    virtual void UpgradeDevice(const char* szFileName);
//
//    //��ȡ����汾��Ϣ
//    //@szVersion: �汾��Ϣ
//    //@nVerLen: szVersion����ĳ���, �ϲ㿽�����Ȳ��ó����˳���
//    virtual void GetSoftwareVersion(char* szVersion, int nVerLen) ;
//    //��ȡ��Ƶ״̬(��Ƶ��ʧ��¼��״̬)
//    //@nVideoLost: ��0λ��ʾͨ��1,  ֵΪ1��ʾ��Ƶ��ʧ
//    //@nVideoRecord: ��0λ��ʾͨ��1,  ֵΪ1��ʾ����¼��
//    virtual void GetVideoStatus(int& nVideoLost, int& nVideoRecord) ;
//    //��ȡ������Ϣ
//    //@nDiskCount: ������Ŀ
//    //@szDiskValue: 16000_8000_32000_8000 ��ʽ, ��λMB, 16000��ʾ���пռ�Ϊ16000MB, 8000��ʾʣ��ռ�Ϊ8000MB
//    //          ���0_0  ���ʾӲ�̳���
//    //        �м�ʹ��_   �ָ�
//    //@nDiskValLen: szDiskValue����ĳ���, �ϲ㿽�����Ȳ��ó����˳���
//    virtual void GetDiskInfo(int& nDiskCount, char* szDiskValue, int nDiskValLen) ;
//    
//    //��ȡ3G״̬
//    //@n3GStatus: 0��ʾ��Ч��1��ʾ��Ч
//    //@n3GType: ��������0��ʾ2G,  1��ʾEVDO,  2��ʾWCDMA, 3��ʾTD-WCDMA, 4 TD_LED , 5 FDD
//    //@sz3GAddress: 3G�κź�ĵ�ַ
//    
//    virtual void Get3GStatus(int &n3GStatus, int& n3GType, char* sz3GAddress, int n3GAddrLen) ;
//    //��ȡWIFI״̬
//    //@nWifiStatus: 0��ʾ��Ч��1��ʾ��Ч
//    //@szWifiAddress: WIFI  �������ַ
//    //@nWifiAddrLen: WIFI  �������ַ
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
	char	m_szWifiIP[64];//WifiIP��ַ
	char	m_sz3gIP[64];//3gIP��ַ
	char	m_szVersion[64];//�汾��Ϣ
	char	m_szDiskValue[64];//��������
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

