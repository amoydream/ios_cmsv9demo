
#include "ttxpttservice.h"

CTTXPttService* CTTXPttService::g_pTTXPttWork = NULL;
CTTXPttService* TTXPttWorkIns()
{
	if (NULL == CTTXPttService::g_pTTXPttWork)
	{
		CTTXPttService::g_pTTXPttWork = new CTTXPttService();
	}
	return CTTXPttService::g_pTTXPttWork;
}

void DelTTXPttWork()
{
	if (NULL != CTTXPttService::g_pTTXPttWork)
	{
		delete CTTXPttService::g_pTTXPttWork;
		CTTXPttService::g_pTTXPttWork = NULL;
	}
}

CTTXPttService::CTTXPttService()
{	
	m_bRequireTalk = false;
#ifdef _TTX_PTT_SAVE_TALK_FILE_
	m_pSaveAacFile = NULL;
#endif
}

CTTXPttService::~CTTXPttService()
{
#ifdef _TTX_PTT_SAVE_TALK_FILE_
	if (m_pSaveAacFile != NULL)
	{
		fclose(m_pSaveAacFile);
		m_pSaveAacFile = NULL;
	}
#endif	
}

////��¼��Ϣ
////@bSuc: ��¼�ɹ�����ʧ��
////@nTerminalID: ��Ϊ��¼�ɹ�ʱ, Ϊ���ն������ID
////@nError: ��ʾ����ԭ�򣬵�Ϊ����ʱ��ЧTTX_PTT_ERR_PASSWORD\TTX_PTT_ERR_NETWORK\TTX_PTT_ERR_ALREADY_LOGIN
//void CTTXPttService::DoLogin(bool bSuc, int nGroupID, int nTerminalID, int nError)
//{
//}
//
////���յ�������Ƶ
////@nTerminalID: �ն�ID����ʾ�Ǹ��ն��ڽ���
////@bStart: true��ʾ��ʼ,false��ʾֹͣ
void CTTXPttService::DoTalk(int nGroupID, int nTerminalID, bool bStart)
{
    CallBackPttAudioTalk(nGroupID, nTerminalID, bStart);
}
//
////���յ�������Ƶ
////@nGroupID: Ⱥ��ID
////@nTerminalID: �ն�ID
////@nAudioIndex: ��Ƶ������ÿ�ν���ʱ����0��ʼ
////@pAudio: ��Ƶ����
////@nLength: ��Ƶ����
void CTTXPttService::DoRecvAudio(int nGroupID, int nTerminalID, int nAudioIndex, const char* pAudio, int nLength, _u64long u64Stamp)
{
    CallBackPttAudioFrame(nGroupID, nTerminalID, nAudioIndex, pAudio, nLength);
}
//
////�л�Ⱥ��(��ǿ������ǿ��)
////@nGroupID: Ⱥ��ID
////@nTerminalID: �ն�ID������ն�IDΪ0��ʾ���ն��л�Ⱥ��
////@nEnter: ��������뿪
void CTTXPttService::DoSwitchGroup(int nGroupID, int nTerminalID, int nEnter, int bForce)
{

       CallBackPttDoSwitchGroup(nGroupID, nTerminalID, nEnter);

}
//
////Ⱥ����Ϣ����
////@nGroupID: Ⱥ��ID
////@szUtf8Name: Ⱥ������
void CTTXPttService::DoUpdateGroupInfo(int nGroupID, const char* szUtf8Name, const char* szAnsiName)
{
    printf("DoUpdateGroupInfo nGroup = %d",nGroupID);
//    TTXLOG_INFO("CTTXPttService DoUpdateGroupInfo start");
}
//
////Ⱥ���Ա�����仯����Ҫ����ȥ��̨��ȡȺ���Ա��Ϣ
////@nGroupID: Ⱥ��ID
void CTTXPttService::DoUpdateGroupMember(int nGroupID)
{
    CallBackPttDoUpdateGroupMember(nGroupID);
}
////���û���ӵ�ĳ��С�� ����Ҫ����ȥ��̨��ȡȺ���Ա��Ϣ
////@nGroupID: Ⱥ��ID
////@bTempGroup: �Ƿ�Ϊ��ʱȺ��
void CTTXPttService::DoAppendToGroup(int nGroupID, int bTempGroup)
{
    CallBackPttDoAppendToGroup(nGroupID, bTempGroup);
}
//
////��ЭͬС�����Ƴ�����Ⱥ����ɾ��
////@nGroupID: Ⱥ��ID
void CTTXPttService::DoRemoveFromGroup(int nGroupID, int bTempGroup, int nTerminalID)
{
    CallBackPttDoRemoveFromGroup(nGroupID, bTempGroup, nTerminalID);

}
//
////���յ�������Ϣ
////@nGroupID: Ϊ0ʱ��ʾ1��1������Ϣ����Ϊ0ʱ����ʾ��ĳ��Ⱥ����û�������Ϣ
////@nTerminalID: ��Ⱥ��IDΪ0ʱ��Ч����ʾ�����ն˷���������Ϣ
////@nType: ��ʱ��Ч
////@nSendTerID: ��ʾ�������ֵ��û�
////@szUtf8Text: ��������
void CTTXPttService::DoTts(int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUtf8Text)
{
//�ȴ������ٴ���
//    CallBackTtsVoice(szUtf8Text);
}

////���յ��ļ���Ŀǰֻ֧����Ƶ�ļ�
////@pTm������ʱ��
////@nTotalSecond���ļ�ʱ��
////@nGroupID��Ϊ0ʱ��ʾ1��1������Ϣ����Ϊ0ʱ����ʾ��ĳ��Ⱥ����û�������Ϣ
////@nTerminalID����ʾ�������ֵ��û�
////@nType���ļ����ͣ�4��TTX_FILE_AUDIO����ʾ��Ƶ�ļ�
////@nSendTerID��������ID
////@szUrl���ļ�����
void CTTXPttService::DoFile(const struct tm* pTm, int nTotalSecond, int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUrl)
{
    if (nType == TTX_FILE_AUDIO) {
        CallBackDoFile(pTm, nTotalSecond, nGroupID, nTerminalID, nType, nSendTerID , szUrl);
    }

}
//
bool CTTXPttService::SendTalkAacFrame(const char* pAccBuf, int nAccLen , _u64long u64Stamp)
{
    return TTXPTT_SendAudio(pAccBuf, nAccLen, u64Stamp);;
}
////�л�Ⱥ��(��ǿ������ǿ��)
////@nGroupID: Ⱥ��ID
////@nTerminalID: �ն�ID������ն�IDΪ0��ʾ���ն��л�Ⱥ��
////@nEnter: ��������뿪
void CTTXPttService::PTTSendTts(int nGroupID, int nTerminalID, int nType, const char* szUtf8Text)
{
//    TTXLOG_INFO("PTTSendTts szUtf8Text:%s", szUtf8Text);
    TTXPTT_SendTts(nGroupID, nTerminalID, nType, szUtf8Text);
}
//
void CTTXPttService::SetRequireTalk(bool bTalk)
{
//    m_bRequireTalk = bTalk;
//    if (m_bRequireTalk)
//    {
//        #ifdef _TTX_PTT_SAVE_TALK_FILE_
//        ttxFILEMakeAllDir("/mnt/sdcard/gdispatch/aac");
//        struct tm cur = ttxTIMEGetLocalTime();
//        char szFile[256] = {0};
//        sprintf(szFile, "/mnt/sdcard/gdispatch/aac/%04d-%02d-%02d %02d-%02d-%02d.aac", cur.tm_year + 1900
//            , cur.tm_mon + 1, cur.tm_mday, cur.tm_hour, cur.tm_min, cur.tm_sec);
//        m_pSaveAacFile = fopen(szFile, "wb");
//        #endif
//    }
//    else
//    {
//        #ifdef _TTX_PTT_SAVE_TALK_FILE_
//        if (m_pSaveAacFile != NULL)
//        {
//            fclose(m_pSaveAacFile);    m_pSaveAacFile = NULL;
//        }
//        #endif
//    }
}
//
//
