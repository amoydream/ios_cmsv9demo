
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

////登录消息
////@bSuc: 登录成功或者失败
////@nTerminalID: 当为登录成功时, 为本终端自身的ID
////@nError: 表示出错原因，当为出错时有效TTX_PTT_ERR_PASSWORD\TTX_PTT_ERR_NETWORK\TTX_PTT_ERR_ALREADY_LOGIN
//void CTTXPttService::DoLogin(bool bSuc, int nGroupID, int nTerminalID, int nError)
//{
//}
//
////接收到讲话音频
////@nTerminalID: 终端ID，表示那个终端在讲话
////@bStart: true表示开始,false表示停止
void CTTXPttService::DoTalk(int nGroupID, int nTerminalID, bool bStart)
{
    CallBackPttAudioTalk(nGroupID, nTerminalID, bStart);
}
//
////接收到讲话音频
////@nGroupID: 群组ID
////@nTerminalID: 终端ID
////@nAudioIndex: 音频索引，每次讲话时，从0开始
////@pAudio: 音频数据
////@nLength: 音频长度
void CTTXPttService::DoRecvAudio(int nGroupID, int nTerminalID, int nAudioIndex, const char* pAudio, int nLength, _u64long u64Stamp)
{
    CallBackPttAudioFrame(nGroupID, nTerminalID, nAudioIndex, pAudio, nLength);
}
//
////切换群组(被强拉或者强拆)
////@nGroupID: 群组ID
////@nTerminalID: 终端ID，如果终端ID为0表示本终端切换群组
////@nEnter: 进入或者离开
void CTTXPttService::DoSwitchGroup(int nGroupID, int nTerminalID, int nEnter, int bForce)
{

       CallBackPttDoSwitchGroup(nGroupID, nTerminalID, nEnter);

}
//
////群组信息更新
////@nGroupID: 群组ID
////@szUtf8Name: 群组名称
void CTTXPttService::DoUpdateGroupInfo(int nGroupID, const char* szUtf8Name, const char* szAnsiName)
{
    printf("DoUpdateGroupInfo nGroup = %d",nGroupID);
//    TTXLOG_INFO("CTTXPttService DoUpdateGroupInfo start");
}
//
////群组成员发生变化，需要重新去后台获取群组成员信息
////@nGroupID: 群组ID
void CTTXPttService::DoUpdateGroupMember(int nGroupID)
{
    CallBackPttDoUpdateGroupMember(nGroupID);
}
////把用户添加到某个小组 ，需要重新去后台获取群组成员信息
////@nGroupID: 群组ID
////@bTempGroup: 是否为临时群组
void CTTXPttService::DoAppendToGroup(int nGroupID, int bTempGroup)
{
    CallBackPttDoAppendToGroup(nGroupID, bTempGroup);
}
//
////从协同小组中移除，将群组结点删除
////@nGroupID: 群组ID
void CTTXPttService::DoRemoveFromGroup(int nGroupID, int bTempGroup, int nTerminalID)
{
    CallBackPttDoRemoveFromGroup(nGroupID, bTempGroup, nTerminalID);

}
//
////接收到文字信息
////@nGroupID: 为0时表示1对1发送消息，不为0时，表示给某个群组的用户发送消息
////@nTerminalID: 当群组ID为0时有效，表示给此终端发送文字信息
////@nType: 暂时无效
////@nSendTerID: 表示发送文字的用户
////@szUtf8Text: 语言内容
void CTTXPttService::DoTts(int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUtf8Text)
{
//先传出来再处理
//    CallBackTtsVoice(szUtf8Text);
}

////接收到文件，目前只支持音频文件
////@pTm：发送时间
////@nTotalSecond：文件时长
////@nGroupID：为0时表示1对1发送消息，不为0时，表示给某个群组的用户发送消息
////@nTerminalID：表示发送文字的用户
////@nType：文件类型，4（TTX_FILE_AUDIO）表示音频文件
////@nSendTerID：发送者ID
////@szUrl：文件链接
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
////切换群组(被强拉或者强拆)
////@nGroupID: 群组ID
////@nTerminalID: 终端ID，如果终端ID为0表示本终端切换群组
////@nEnter: 进入或者离开
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
