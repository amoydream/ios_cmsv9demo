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
//    //登录消息
//    //@bSuc: 登录成功或者失败
//    //@nGroupID：对应的当前的群组ID
//    //@nTerminalID: 当为登录成功时, 为本终端自身的ID
//    //@nError: 表示出错原因，当为出错时有效TTX_PTT_ERR_PASSWORD\TTX_PTT_ERR_NETWORK\TTX_PTT_ERR_ALREADY_LOGIN
//    virtual void DoLogin(bool bSuc, int nGroupID, int nTerminalID, int nError);
//
    //接收到讲话音频
    //@nTerminalID: 终端ID，表示那个终端在讲话
    //@bStart: true表示开始,false表示停止
    virtual void DoTalk(int nGroupID, int nTerminalID, bool bStart);
//
//    //接收到讲话音频
//    //@nGroupID: 群组ID
//    //@nTerminalID: 终端ID
//    //@nAudioIndex: 音频索引，每次讲话时，从0开始
//    //@pAudio: 音频数据
//    //@nLength: 音频长度
    virtual void DoRecvAudio(int nGroupID, int nTerminalID, int nAudioIndex, const char* pAudio, int nLength, _u64long u64Stamp);
//
//    //切换群组(被强拉或者强拆)
//    //@nGroupID: 群组ID
//    //@nTerminalID: 终端ID，如果终端ID为0表示本终端切换群组
//    //@nEnter: 进入或者离开
//    //@bForce: 1为强拉强拆，0为进入离开
    virtual void DoSwitchGroup(int nGroupID, int nTerminalID, int nEnter, int bForce);
//
//    //群组信息更新
//    //@nGroupID: 群组ID
//    //@szUtf8Name: 群组名称
    virtual void DoUpdateGroupInfo(int nGroupID, const char* szUtf8Name, const char* szAnsiName);
//
//    //群组成员发生变化，需要重新去后台获取群组成员信息
//    //如果群组ID不存在，则需要去服务器上把群组信息整个刷新回来，新增临时群组时，会出现这个情况
//    //@nGroupID: 群组ID
    virtual void DoUpdateGroupMember(int nGroupID);
//
//    //把用户添加到某个小组 ，需要重新去后台获取群组成员信息
//    //@nGroupID: 群组ID
//    //@bTempGroup: 是否为临时群组
    virtual void DoAppendToGroup(int nGroupID, int bTempGroup);
//
//    //从协同小组中移除，将群组结点删除
//    //@nGroupID: 群组ID
//    //@bTempGroup: 是否为临时群组
//    //@nTerminalID: 那个终端删除了群组
    virtual void DoRemoveFromGroup(int nGroupID, int bTempGroup, int nTerminalID);
//
//    //接收到文字信息
//    //@nGroupID: 为0时表示1对1发送消息，不为0时，表示给某个群组的用户发送消息
//    //@nTerminalID: 当群组ID为0时有效，表示给此终端发送文字信息
//    //@nType: 暂时无效
//    //@nSendTerID: 表示发送文字的用户
//    //@szUtf8Text: 语言内容
    virtual void DoTts(int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUtf8Text);
//
//    //接收到文件，目前只支持音频文件
//    //@pTm：发送时间
//    //@nTotalSecond：文件时长
//    //@nGroupID：为0时表示1对1发送消息，不为0时，表示给某个群组的用户发送消息
//    //@nTerminalID：表示发送文字的用户
//    //@nType：文件类型，4（TTX_FILE_AUDIO）表示音频文件
//    //@nSendTerID：发送者ID
//    //@szUrl：文件链接
    virtual void DoFile(const struct tm* pTm, int nTotalSecond, int nGroupID, int nTerminalID, int nType, int nSendTerID, const char* szUrl);
    
//    * @Description:发送TTS
//    * @param:     nGroupID: 群组ID(为0时，表示对某个终端发送文字)
//nTerminalID: 终端ID，群组为0时有效，表示对某个终端发送文字
//nType: 类型（暂时无效）
//    szUtf8Text：文字信息, 长度不超过512
//    * @return: 0表示成功
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

