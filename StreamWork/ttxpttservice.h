#ifndef _TTX_PTT_SERVICE_H_
#define _TTX_PTT_SERVICE_H_

#include "ttxpttnetapi.h"
#include <stdio.h>
#define _TTX_PTT_SAVE_TALK_FILE_

class CTTXPttService : public CTTXPttWork
{
private:
	static CTTXPttService* g_pTTXPttWork;
	friend CTTXPttService* TTXPttWorkIns();
	friend void DelTTXPttWork();

private:
	CTTXPttService();
	virtual ~CTTXPttService();

public:


public:
//    //��¼��Ϣ
//    //@bSuc: ��¼�ɹ�����ʧ��
//    //@nGroupID����Ӧ�ĵ�ǰ��Ⱥ��ID
//    //@nTerminalID: ��Ϊ��¼�ɹ�ʱ, Ϊ���ն������ID
//    //@nError: ��ʾ����ԭ�򣬵�Ϊ����ʱ��ЧTTX_PTT_ERR_PASSWORD\TTX_PTT_ERR_NETWORK\TTX_PTT_ERR_ALREADY_LOGIN
//    virtual void DoLogin(bool bSuc, int nGroupID, int nTerminalID, int nError);
//
    //���յ�������Ƶ
    //@nTerminalID: �ն�ID����ʾ�Ǹ��ն��ڽ���
    //@bStart: true��ʾ��ʼ,false��ʾֹͣ
    virtual void DoTalk(int nGroupID, int nTerminalID, bool bStart);
//
//    //���յ�������Ƶ
//    //@nGroupID: Ⱥ��ID
//    //@nTerminalID: �ն�ID
//    //@nAudioIndex: ��Ƶ������ÿ�ν���ʱ����0��ʼ
//    //@pAudio: ��Ƶ����
//    //@nLength: ��Ƶ����
    virtual void DoRecvAudio(int nGroupID, int nTerminalID, int nAudioIndex, const char* pAudio, int nLength, _u64long u64Stamp);
//
//    //�л�Ⱥ��(��ǿ������ǿ��)
//    //@nGroupID: Ⱥ��ID
//    //@nTerminalID: �ն�ID������ն�IDΪ0��ʾ���ն��л�Ⱥ��
//    //@nEnter: ��������뿪
//    //@bForce: 1Ϊǿ��ǿ��0Ϊ�����뿪
    virtual void DoSwitchGroup(int nGroupID, int nTerminalID, int nEnter, int bForce);
//
//    //Ⱥ����Ϣ����
//    //@nGroupID: Ⱥ��ID
//    //@szUtf8Name: Ⱥ������
    virtual void DoUpdateGroupInfo(int nGroupID, const char* szUtf8Name, const char* szAnsiName);
//
//    //Ⱥ���Ա�����仯����Ҫ����ȥ��̨��ȡȺ���Ա��Ϣ
//    //���Ⱥ��ID�����ڣ�����Ҫȥ�������ϰ�Ⱥ����Ϣ����ˢ�»�����������ʱȺ��ʱ�������������
//    //@nGroupID: Ⱥ��ID
    virtual void DoUpdateGroupMember(int nGroupID);
//
//    //���û���ӵ�ĳ��С�� ����Ҫ����ȥ��̨��ȡȺ���Ա��Ϣ
//    //@nGroupID: Ⱥ��ID
//    //@bTempGroup: �Ƿ�Ϊ��ʱȺ��
    virtual void DoAppendToGroup(int nGroupID, int bTempGroup);
//
//    //��ЭͬС�����Ƴ�����Ⱥ����ɾ��
//    //@nGroupID: Ⱥ��ID
//    //@bTempGroup: �Ƿ�Ϊ��ʱȺ��
//    //@nTerminalID: �Ǹ��ն�ɾ����Ⱥ��
    virtual void DoRemoveFromGroup(int nGroupID, int bTempGroup, int nTerminalID);
//
//    //���յ�������Ϣ
//    //@nGroupID: Ϊ0ʱ��ʾ1��1������Ϣ����Ϊ0ʱ����ʾ��ĳ��Ⱥ����û�������Ϣ
//    //@nTerminalID: ��Ⱥ��IDΪ0ʱ��Ч����ʾ�����ն˷���������Ϣ
//    //@nType: ��ʱ��Ч
//    //@nSendTerID: ��ʾ�������ֵ��û�
//    //@szUtf8Text: ��������
    virtual void DoTts(int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUtf8Text);
//
//    //���յ��ļ���Ŀǰֻ֧����Ƶ�ļ�
//    //@pTm������ʱ��
//    //@nTotalSecond���ļ�ʱ��
//    //@nGroupID��Ϊ0ʱ��ʾ1��1������Ϣ����Ϊ0ʱ����ʾ��ĳ��Ⱥ����û�������Ϣ
//    //@nTerminalID����ʾ�������ֵ��û�
//    //@nType���ļ����ͣ�4��TTX_FILE_AUDIO����ʾ��Ƶ�ļ�
//    //@nSendTerID��������ID
//    //@szUrl���ļ�����
    virtual void DoFile(const struct tm* pTm, int nTotalSecond, int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUrl);
    
//    * @Description:����TTS
//    * @param:     nGroupID: Ⱥ��ID(Ϊ0ʱ����ʾ��ĳ���ն˷�������)
//nTerminalID: �ն�ID��Ⱥ��Ϊ0ʱ��Ч����ʾ��ĳ���ն˷�������
//nType: ���ͣ���ʱ��Ч��
//    szUtf8Text��������Ϣ, ���Ȳ�����512
//    * @return: 0��ʾ�ɹ�
//    virtual void PTTSendTts(int nGroupID, int nTerminalID, int nType, const char* szUtf8Text);

	
	
public:
	void	SetRequireTalk(bool bTalk);
	bool	IsRequireTalk() {	return m_bRequireTalk;	}
	bool 	SendTalkAacFrame(const char* pAccBuf, int nAccLen , _u64long u64Stamp);
	void PTTSendTts(int nGroupID, int nTerminalID, int nType, const char* szUtf8Text);
	
private:
	bool	m_bRequireTalk;
#ifdef _TTX_PTT_SAVE_TALK_FILE_
	FILE*	m_pSaveAacFile;
#endif
};

CTTXPttService* TTXPttWorkIns();
void DelTTXPttWork();

void CallBackPttAudioTalk(int nGroupID, int nTerminalID, int bTalk);
//void CallBackPttAudioFile(int nGroupID, int nTerminalID, int nTotalMinSecond, const char* szFile);
void CallBackPttAudioFrame(int nGroupID, int nTerminalID, int nAudioIndex, const char* pBuffer, int nLength);
void CallBackPttDoSwitchGroup(int nGroupID, int nTerminalID, int nEnter);
//void CallBackPttDoAppendToGroup(int nGroupID, int nCompanyID, int nType, int nCreate, const char*szName);
void CallBackPttDoRemoveFromGroup(int nGroupID, int bTempGroup, int nTerminalID);
void CallBackPttDoUpdateGroupMember(int nGroupID);
void CallBackPttDoAppendToGroup(int nGroupID, int nTerminalID);
//void CallBackTtsVoice(const char* szText);
void CallBackDoFile(const struct tm* pTm, int nTotalSecond, int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUrl);



#endif

