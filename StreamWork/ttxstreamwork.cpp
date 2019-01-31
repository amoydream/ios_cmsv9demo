//#include <stdio.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <sys/time.h>
//#include <dirent.h>
//#include <string.h>
//#include <time.h>
//
//#include "ttxstreamwork.h"
//#include "ttxvideoencoder.h"
//#include "ttxaudioencoder.h"
//#include "ttxlogger.h"
//#include "ttxpublic.h"
//#include "ttxtalkback.h"
//#include "md5.h"
//#include "base64.h"
//#include "ttxrecreader.h"
//#include "ttxfileapi.h"
//#include "ttxrecordwork.h"
//#include "ttxwebserver.h"
//#include "cJSON.h"
//#include "ttxrecfilesearch.h"
#include "ttxstreamwork.h"


CTTXStreamWork* CTTXStreamWork::g_pTTXNet = NULL;
CTTXStreamWork* TTXStreamIns()
{
    if (NULL == CTTXStreamWork::g_pTTXNet)
    {
        CTTXStreamWork::g_pTTXNet = new CTTXStreamWork();
    }
    return CTTXStreamWork::g_pTTXNet;
}

void DelTTXStream()
{
    if (NULL != CTTXStreamWork::g_pTTXNet)
    {
        delete CTTXStreamWork::g_pTTXNet;
        CTTXStreamWork::g_pTTXNet = NULL;
    }
}

CTTXStreamWork::CTTXStreamWork()
{
    memset(m_szDevIDNO, 0, sizeof(m_szDevIDNO));
    memset(m_szSvrIP, 0, sizeof(m_szSvrIP));
    m_usSvrPort = 0;
}

CTTXStreamWork::~CTTXStreamWork()
{
}

//bool CTTXStreamWork::DoAuthentication(const char* szSvrAuthKey, char* szDevAuthKey, int nDevAuthKeyLen)
//{
//    char szBase64Time[128] = {0};
//    char szMd5[128] = {0};
//    strncpy(szBase64Time, szSvrAuthKey, 6);
//    strncpy(szMd5, szSvrAuthKey + 6, 32);
//    strcat(szBase64Time, szSvrAuthKey + 6 + 32);
//    char* szTime = base64_decode(szBase64Time, strlen(szBase64Time));
//
//    char szTemp[64] = {0};
//    int j = 0;
//    for (int i = 0; i < 16; ++ i) {
//        szTemp[j ++] = szTime[i];
//        szTemp[j ++] = m_szDevIDNO[i];
//    }
//
//    char szMd5Encrypt[64] = {0};
//    MD5Encrypt(szTemp, szMd5Encrypt);
//    //TTXLOG_INFO("CTTXStreamWork::DoAuthentication szTemp:%s, time:%s, md5:%s, encrypt:%s", szTemp, szTime, szMd5, szMd5Encrypt);
//    bool ret = false;
//    if (strcasecmp(szMd5Encrypt, szMd5) == 0)
//    {
//        char szTimeMd5[64] = {0};
//        strncpy(szTimeMd5, szTime, 6);
//        MD5Encrypt(szTimeMd5, szDevAuthKey);
//        ret = true;
//        //TTXLOG_INFO("CTTXStreamWork::DoAuthentication timemd5:%s", szDevAuthKey);
//    }
//
//    free(szTime); szTime = NULL;
//    return ret;
//}
//
////获取网络参数，搜索设备时使用
////@netParam: 网络参数
//bool CTTXStreamWork::DoGetNetParam(TTXNetParam_S& netParam)
//{
//    strcpy(netParam.szWebUrl, "action/myaction?page=config.html");
//    netParam.usWebPort = TTX_WEB_SERVER_PORT;
//    return true;
//}
//
////指令处理
////TTS语音处理
bool CTTXStreamWork::DoTtsVoice(const char* szText)
{
//    CallBackTtsVoice(szText);
    return true;
}
//
//////控制指令指令处理
//bool CTTXStreamWork::DoControl(int nCtrlType)
//{
//    TTXLOG_INFO("CTTXStreamWork::DoControl nCtrlType;%d",nCtrlType);
//    CallBackDoControl(nCtrlType);
//    TTXLOG_INFO("CTTXStreamWork::DoControl end");
//    return true;
//
//}
//
////接收到透明串口数据
//void CTTXStreamWork::DoRecvTransparentSerial(int nType, const unsigned char* pBuffer, int nLength)
//{
//    TTXLOG_INFO("CTTXStreamWork::DoRecvTransparentSerial %d,%s", nLength, (char*)pBuffer);
//    CallBackTransparent(nType, (char*)pBuffer, nLength);
//    TTXLOG_INFO("CTTXStreamWork::DoRecvTransparentSerial end");
//}
//
////文件上传完成
////@szFile: 文件名绝对路径
void CTTXStreamWork::DoFileUploadFinish(const char* szFile)
{
    CallBackFileUploadFinished(szFile);
}
//
////参数处理透传
////@nType: 参数类型
////@pInConfig: PC传入的参数信息
////@pOutConfig: 设备返回的参数信息
//bool CTTXStreamWork::DoTransparentConfig(int nType, const LPTTXConfigData_S pInConfig, LPTTXConfigData_S pOutConfig)
//{
//    pOutConfig->nLength = sizeof(pOutConfig->cBuffer);
//    return CallBackConfig(nType, pInConfig->cBuffer, pOutConfig->cBuffer, pOutConfig->nLength);
//}
//回调视屏参数回去
//    //     QCIF和CIF为300K缓存
//    //    HD1和D1为1200K 缓存
//    //    720P为4800K缓存
//    //    1080P为19200K 缓存

bool CTTXStreamWork::GetVideoResolution(int nChannel, int nStreamType, int& nResolution, int& nFrameBufLen)
{
//    printf("GetVideoResolution nChannel = %d nStreamType = %d nResolution = %d nFrameBufLen = %d\n",nChannel,nStreamType,nResolution,nFrameBufLen);
//    nResolution = TTX_RESOLUTION_D1;
//    nFrameBufLen = 1200*1000;
//    nResolution = 2;
//    nFrameBufLen = 307200;
    
    return false;
//    return TTXVideoEncoderIns()->GetVideoResolution(nChannel, nStreamType, nResolution, nFrameBufLen);
}

bool CTTXStreamWork::StartAVEnc(int nMediaType, int nChannel, int nStreamType, TTXPfnAVEncoderCB pfnEncoderCB, void* pEncUsr, void** ppAVUsr)
{
//      printf("StartAVEnc nMediaType = %d nChannel = %d nStreamType = %d \n",nMediaType,nChannel,nStreamType);
//    if (TTX_MEDIA_TYPE_AV == nMediaType)
//    {
        
//        return CallBackMediaStartAVEnc(nMediaType, nChannel, nStreamType, pfnEncoderCB, pEncUsr, ppAVUsr);
//        if (CallBackMedia(TTX_MEDIA_AV, nChannel, nStreamType, 1))
//        {
        
//            return TTXVideoEncoderIns()->StartAVEnc(nChannel, nStreamType, pfnEncoderCB, pEncUsr, ppAVUsr);
//        }
//    }
//    else if (TTX_MEDIA_TYPE_AUDIO == nMediaType)
//    {
//        if (CallBackMedia(TTX_MEDIA_LISTEN, nChannel, nStreamType, 1))
//        {
//            return TTXAudioEncoderIns()->StartListen(nChannel, pfnEncoderCB, pEncUsr, ppAVUsr);
//        }
//    }
    return false;
}
//
bool CTTXStreamWork::StopAVEnc(int nMediaType, int nChannel, int nStreamType, void* pAVUsr)
{
//    if (TTX_MEDIA_TYPE_AV == nMediaType)
//    {
//        CallBackMedia(TTX_MEDIA_AV, nChannel, nStreamType, 0);
//        return TTXVideoEncoderIns()->StopAVEnc(nChannel, nStreamType, pAVUsr);
//    }
//    else if (TTX_MEDIA_TYPE_AUDIO == nMediaType)
//    {
//        CallBackMedia(TTX_MEDIA_LISTEN, nChannel, nStreamType, 0);
//        return TTXAudioEncoderIns()->StopListen(nChannel);
//    }
      printf("StopAVEnc nMediaType = %d nChannel = %d nStreamType = %d \n",nMediaType,nChannel,nStreamType);
    return false;
}

bool CTTXStreamWork::AVEncIFrame(int nChannel, int nStreamType)
{
    printf("AVEncIFrame nChannel = %d nStreamType = %d",nChannel,nStreamType);
    return true;
//    return TTXVideoEncoderIns()->AVEncIFrame(nChannel, nStreamType);
}
//
///*****************************************************************************
////启动双向对讲
////@nChannel: 通道号从0开始，表示麦克通道，从0开始
////@pfnEncoderCB: 编码回调
////@pEncUsr: 编码回调用户自定义数据
////@ppDecUsr: 用户解码回调自字义函数，在
////双向对讲时，将编码数据不停通过pfnEncoderCB，通知给网络层
////设备启动音频解码器
//******************************************************************************/
//bool CTTXStreamWork::StartTalkback(int nChannel, TTXPfnAVEncoderCB pfnEncoderCB, void* pEncUsr, void** ppTalkUsr)
//{
//    //TTXLOG_INFO("CTTXStreamWork::StartTalkback");
//    if (CallBackMedia(TTX_MEDIA_TALKBACK, nChannel, 0, 1))
//    {
//        TTXTalkbackIns()->SetEncoderCB(pfnEncoderCB, pEncUsr);
//        return true;
//    }
//    else
//    {
//        TTXLOG_INFO("CTTXStreamWork::StartTalkback failed");
//        return false;
//    }
//}
//
///*****************************************************************************
////停止双向对讲
////@nChannel: 通道号从0开始，表示麦克通道，从0开始
////@pTalkUsr: 在StartTalkback里面输入的ppTalkUsr参数
////设备可以关闭音频解码器
//******************************************************************************/
//bool CTTXStreamWork::StopTalkback(int nChannel, void* pTalkUsr)
//{
//    //TTXLOG_INFO("CTTXStreamWork::StopTalkback");
//    CallBackMedia(TTX_MEDIA_TALKBACK, nChannel, 0, 0);
//    TTXTalkbackIns()->SetEncoderCB(NULL, NULL);
//    return true;
//}
//
///*****************************************************************************
////设置解码的音频参数
////@nChannel: 麦克通道
////@nAudioType: 音频类型TTX_AUDIO_TYPE_G726_40KBPS 等
////@nFrmLength: 每个音频帧的数据长度
////@pTalkUsr: 在StartTalkback里面输入的ppTalkUsr参数
////调用此接口后，上层必须停止调用数据回调函数
//******************************************************************************/
//void CTTXStreamWork::TalkSetAudioParam(int nChannel, int nAudioType, int nFrmLength, void* pTalkUsr)
//{
//    TTXTalkbackIns()->SetAudioParam(nAudioType, nFrmLength);
//}
//
///*****************************************************************************
////解码对讲数据
////@nLength: 音频长度
////@u64Stamp: 时间戳
////@pData: 音频数据
////@pTalkUsr: 在StartTalkback里面输入的ppTalkUsr参数
////调用此接口后，上层必须停止调用数据回调函数
//******************************************************************************/
//void CTTXStreamWork::TalkDecoder(int nChannel, int nLength, unsigned long long u64Stamp, const char* pData, void* pTalkUsr)
//{
//    TTXTalkbackIns()->TalkDecoder(nLength, u64Stamp, pData);
//}
//
///*****************************************************************************
////启动文件查找
////@nYear: 年
////@nMonth: 月
////@nDay: 日
////@nBeginTime: 开始时间，以秒为单位
////@nEndTime: 结束时间，以秒为单位
////@nRecType: 录像类型
////@nChannel: 录像对应的通道
////@pfnRecFindCB: 文件回调函数
////@pFindUsr: 文件查找用户自定义数据
////@pfnGetExitCB: 判断是否需要退出
////@pExitUsr: 判断退出函数
////网络库启动一个文件查找线程，进行录像文件查找
////文件查找过程中，需要不停调用pfnGetExitCB，来判断是否需要退出
////查找到文件，及时调用pfnRecFindCB，调用上层
////查找过程中，每 个循环应当调用usleep(0)，避免CPU占用率高
//******************************************************************************/
//void CTTXStreamWork::FindRecFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nRecType, int nChannel
//                , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr)
//{
//
//    if (m_FactoryType == 46) // 友浩
//    {
//        yh_search_file(nYear, nMonth, nDay, nBeginTime, nEndTime, nRecType, nChannel
//                , pfnRecFindCB, pFindUsr, pfnGetExitCB, pExitUsr);
//
//    }
//    else if(m_FactoryType == 50) //海信
//    {
//        qdhx_search_file(nYear, nMonth, nDay, nBeginTime, nEndTime, nRecType, nChannel
//                , pfnRecFindCB, pFindUsr, pfnGetExitCB, pExitUsr);
//    }
//    else if(m_FactoryType == 51) //武汉纽硕
//    {
//        whnk_search_file(nYear, nMonth, nDay, nBeginTime, nEndTime, nRecType, nChannel
//                , pfnRecFindCB, pFindUsr, pfnGetExitCB, pExitUsr);
//    }
//    else if(m_FactoryType == 35 || m_FactoryType == 43)
//    {
//        //示例查找当前目录下的record目录
//        char szDir[256] = {0};
//
//        strncpy(szDir, TTXRecordWorkIns()->GetRecPath(), sizeof(szDir) - 1);
//        TTXLOG_INFO("CTTXNetService::FindRecFile  szDir:%s",szDir);
//
//        if (strlen(szDir) <= 0)
//        {
//            return ;
//        }
//
//        int nLastPos = strlen(szDir) - 1;
//        if (szDir[nLastPos] == '/')
//        {
//            szDir[nLastPos] = '\0';
//        }
//
//        //暂时只考虑通道0
//        if (TTX_CHANNEL_ALL == nChannel || TTX_CHANNEL_ALL_EX == nChannel|| 0 == nChannel)
//        {
//            if (TTX_RECTYPE_ALL == nRecType || TTX_RECTYPE_NORMAL == nRecType)
//            {
//                //目录
//                DIR * dir = NULL;
//                //目录环境
//                struct dirent *dir_env;
//                //文件描述
//                struct stat stat_file;
//                //打开目录
//                dir = opendir(szDir);
//                if (dir != NULL)
//                {
//                    while( (dir_env = readdir(dir)) != NULL )//读文件描述表
//                    {
//                        //判断是否需要退出
//                        if (pfnGetExitCB(pExitUsr))
//                        {
//                            TTXLOG_INFO("CTTXNetService::FindRecFile pfnGetExitCB true");
//                            break;
//                        }
//
//                        //放弃CPU占用
//                        ttxSleep(0);
//
//                        //排除.和..
//                        if(strcmp(dir_env->d_name,".")==0  || strcmp(dir_env->d_name,"..")==0)
//                        {
//                            continue;
//                        }
//
//                        TTXRecFile_S RFile;
//                        memset(&RFile, 0, sizeof(RFile));
//                        //把文件全名保存到新变量
//                        strcpy(RFile.szFileName, szDir);
//                        strcat(RFile.szFileName, "/");
//                        strcat(RFile.szFileName, dir_env->d_name);
//                        const char* pRecType = RFile.szFileName + strlen(RFile.szFileName) - 3;
//
//                        if(0 == strcmp(pRecType, ".ts"))
//                        {
//                            TTXLOG_INFO("CTTXNetService::FindRecFile @@szFileName %s", RFile.szFileName);
//
//                        }else
//                        {
//                            //TTXLOG_INFO("CTTXNetService::FindRecFile szFileName %s", RFile.szFileName);
//                            continue;
//                        }
//
//                        //获取文件描述信息
//                        int ret = stat(RFile.szFileName, &stat_file);
//                        if (ret >= 0)
//                        {
//                            if( !S_ISDIR(stat_file.st_mode))
//                            {
//                                RFile.uiFileLen = stat_file.st_size;
//
//                                long lReader = 0;
//                                TtxFileInfo_S FInfo = {0};
//                                int recBegTime = 0;
//                                int recEndTime = 0;
//
//                                if(m_FactoryType == 43) //后视镜厂家 43
//                                {
//
//                                    TTXLOG_INFO("CTTXNetService::FindRecFile GetFactoryRecTime readdir:%s",RFile.szFileName);
//
//                                    if(CheckFactoryRecordName(RFile.szFileName))
//                                    {
//                                        GetFactoryRecTime(RFile.szFileName, RFile);
//                                        ///FInfo.nTotalMinSecond = RFile.uiFileTime;
//                                        //FInfo.nChannel = RFile.Channel;
//
//                                        recBegTime = RFile.Hour * 3600 + RFile.Minute * 60 + RFile.Second;
//                                        recEndTime = recBegTime + RFile.uiFileTime;
//
//                                        TTXLOG_INFO("CTTXNetService::FindRecFile readdir %s, %d,%d,%d %d:%d:%d nTotalMinSecond:%d channle:%d %d:%d:%d",
//                                        RFile.szFileName, RFile.Year, RFile.Month, RFile.Day,RFile.Hour,RFile.Minute,RFile.Second,
//                                        RFile.uiFileTime,RFile.Channel, nYear, nMonth, nDay);
//                                        if (recEndTime > 86400)
//                                        {
//                                            recEndTime = 86400;
//                                        }
//                                        if (RFile.Year  == (nYear - 2000) && RFile.Month == nMonth && RFile.Day == nDay
//                                         && ( ( recBegTime >= nBeginTime && recBegTime <= nEndTime)
//                                            || ( recEndTime >= nBeginTime && recEndTime <= nEndTime )
//                                            || ( recBegTime <= nBeginTime && recEndTime >= nEndTime ) ))
//                                        {
//                                            //是否正在录像状态待确定
//                                            TTXLOG_INFO("CTTXNetService::FindRecFile pfnRecFindCB %d:%d:%d", nYear, nMonth, nDay);
//                                            RFile.bStream = false;
//                                            RFile.Type = 0;
//                                            pfnRecFindCB(&RFile, pFindUsr);
//                                        }
//                                    }
//
//                                }
//                                else
//                                {
//                                    TTXFILE_OpenReader(&lReader, RFile.szFileName);
//                                    if (TTX_S_OK == TTXFILE_ReadFileInfo(lReader, &FInfo))
//                                    {
//                                        TtxTime_S& tmBeg = FInfo.tmBegin;
//                                        //TTXLOG_INFO("CTTXNetService::FindRecFile readdir %s, %d,%d,%d %d:%d:%d nTotalMinSecond:%d",
//                                        //RFile.szFileName, tmBeg.wYear, tmBeg.wMonth, tmBeg.wDay,tmBeg.wHour,tmBeg.wMinute,tmBeg.wSecond,FInfo.nTotalMinSecond);
//                                        const char* pType = RFile.szFileName + strlen(RFile.szFileName) - 4;
//                                        if(0 == strcmp(pType, "grec"))
//                                        {
//                                            tmBeg.wYear += 2000;
//                                        }
//                                        //tmBeg.wYear += 2000;
//                                        recBegTime = tmBeg.wHour * 3600 + tmBeg.wMinute * 60 + tmBeg.wSecond;
//                                        recEndTime = recBegTime + FInfo.nTotalMinSecond/1000;
//
//                                        if (recEndTime > 86400)
//                                        {
//                                            recEndTime = 86400;
//                                        }
//
//                                        if (tmBeg.wYear  == nYear && tmBeg.wMonth == nMonth && tmBeg.wDay == nDay
//                                            && ( ( recBegTime >= nBeginTime && recBegTime <= nEndTime)
//                                            || ( recEndTime >= nBeginTime && recEndTime <= nEndTime )
//                                            || ( recBegTime <= nBeginTime && recEndTime >= nEndTime ) ) )
//                                        {
//                                            RFile.uiFileTime = FInfo.nTotalMinSecond/1000;
//                                            RFile.Channel = 0;
//                                            RFile.Year = tmBeg.wYear - 2000;
//                                            RFile.Month = tmBeg.wMonth;
//                                            RFile.Day = tmBeg.wDay;
//                                            RFile.Hour = tmBeg.wHour;
//                                            RFile.Minute = tmBeg.wMinute;
//                                            RFile.Second = tmBeg.wSecond;
//                                            RFile.bRecording = TTXRecordWorkIns()->IsFileRecording(RFile.szFileName);
//                                            RFile.bStream = false;
//                                            RFile.Type = 0;
//
//                                            pfnRecFindCB(&RFile, pFindUsr);
//                                        }
//                                    }
//                                    TTXFILE_CloseReader(lReader);    lReader = 0;
//                                }
//
//                            }
//                        }
//                    }
//                    closedir(dir);    dir = NULL;
//                }
//            }
//        }
//    }
//    else
//    {
//        //yh_search_file();
//    }
//
//}
//
//const char* CTTXStreamWork::CheckFactoryRecordName(const char* szFactoryRecFile)
//{
//    const char* p = strrchr(szFactoryRecFile, '/');
//    if(NULL == p)
//    {
//        p = strrchr(szFactoryRecFile, '\\');
//    }
//
//    if (p)
//    {
//        p = p + 1;
//    }
//
//    //TTXLOG_INFO("CTTXStreamWork::CheckFactoryRecordName %s, %d, 8:%c 16:%c 21:%c",
//    //    p, (int)strlen(p), p[8], p[16], p[21]);
//    if(!p || ((static_cast<int> (strlen(p)) > 30) && (static_cast<int> (strlen(p)) < 29) )
//        || p[8] != '_' || p[16] != '_' || p[21] != '_')
//    {
//        return NULL;
//    }
//    else
//    {
//        return p;
//    }
//}
//
//bool CTTXStreamWork::GetFactoryRecTime(const char* szFactoryRecFile, TTXRecFile_S& RFile)
//{
//    /**
//    *年月日_时分秒A_录像时间_录像像素+.ts
//    *A代表前置摄像头，B代表后置摄像头;录像时间有1min,2min,3min;像素有720P和1080P
//    *20171114_110231A_1min_1080P.ts
//    */
//    const char* p = CheckFactoryRecordName(szFactoryRecFile);
//    if (p)
//    {
//        int nTemp = 0;
//        const char *Tempch = p;
//        sscanf( Tempch, "%4d", &nTemp);
//        RFile.Year = nTemp - 2000;
//
//        Tempch += 4;
//        sscanf( Tempch, "%2d", &nTemp);
//        RFile.Month = nTemp;
//
//        Tempch += 2;
//        sscanf( Tempch, "%2d", &nTemp);
//        RFile.Day = nTemp;
//
//        Tempch += 3;
//        sscanf( Tempch, "%2d", &nTemp);
//        RFile.Hour = nTemp;
//
//        Tempch += 2;
//        sscanf( Tempch, "%2d", &nTemp);
//        RFile.Minute = nTemp;
//
//        Tempch += 2;
//        sscanf( Tempch, "%2d", &nTemp);
//        RFile.Second = nTemp;
//
//        Tempch += 2;
//        if(0 == strncasecmp(Tempch, "A", 1)) // 前置
//        {
//            RFile.Channel = 0;
//        }else if(0 == strncasecmp(Tempch, "B", 1)) // 后置
//        {
//            RFile.Channel = 1;
//        }
//        TTXLOG_INFO("CTTXNetService::FindRecFile GetFactoryRecTime nTemp:%d Tempch:%s",nTemp,Tempch);
//
//        Tempch += 2;
//        sscanf( Tempch, "%2d", &nTemp);
//        //TTXLOG_INFO("CTTXNetService::FindRecFile GetFactoryRecTime nTemp:%d Tempch:%s",nTemp,Tempch);
//        RFile.uiFileTime = nTemp * 60;
//
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//const char* CTTXStreamWork::CheckJpgFileName(const char* szJpgFile)
//{
//    const char* p = strrchr(szJpgFile, '/');
//    if(NULL == p)
//    {
//        p = strrchr(szJpgFile, '\\');
//    }
//
//    if (p)
//    {
//        p = p + 1;
//    }
//
//    if(m_FactoryType == 43)//后视镜厂家
//    {
//        TTXLOG_INFO("CTTXStreamWork::CheckJpgFileName 50 %s, %d, 3:%c 12:%c", p, (int)strlen(p), p[3],p[12]);
//        if(!p || static_cast<int> (strlen(p)) != 24 || p[3] != '_' || p[12] != '_')
//        {
//            return NULL;
//        }
//        else
//        {
//            return p;
//        }
//    }else
//    {
//        TTXLOG_INFO("CTTXStreamWork::CheckJpgFileName!50 %s, %d, 8:%c ", p, (int)strlen(p), p[8]);
//        if(!p || static_cast<int> (strlen(p)) != 19 || p[8] != '_')
//        {
//            return NULL;
//        }
//        else
//        {
//            return p;
//        }
//    }
//
//}
//
//bool CTTXStreamWork::GetJpgFileTime(const char* szJpgFile, TTXRecFile_S& RFile)
//{
//    const char* p = CheckJpgFileName(szJpgFile);
//    if (p)
//    {
//        int nTemp = 0;
//        const char *Tempch = p;
//        if(m_FactoryType == 43) //后视镜厂家 43
//        {
//            Tempch += 4;
//            sscanf( Tempch, "%4d", &nTemp);
//            RFile.Year = nTemp - 2000;
//
//            Tempch += 4;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Month = nTemp;
//
//            Tempch += 2;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Day = nTemp;
//
//            Tempch += 3;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Hour = nTemp;
//
//            Tempch += 2;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Minute = nTemp;
//
//            Tempch += 2;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Second = nTemp;
//            Tempch += 2;
//            if(0 == strncasecmp(Tempch, "A", 1)) // 前置
//            {
//                RFile.Channel = 0;
//            }else if(0 == strncasecmp(Tempch, "B", 1)) // 后置
//            {
//                RFile.Channel = 1;
//            }
//            TTXLOG_INFO("CTTXNetService::FindJpgFile GetJpgFileTime nTemp:%d Tempch:%s",nTemp,Tempch);
//
//        }
//        else
//        {
//            sscanf( Tempch, "%4d", &nTemp);
//            RFile.Year = nTemp - 2000;
//
//            Tempch += 4;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Month = nTemp;
//
//            Tempch += 2;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Day = nTemp;
//
//            Tempch += 3;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Hour = nTemp;
//
//            Tempch += 2;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Minute = nTemp;
//
//            Tempch += 2;
//            sscanf( Tempch, "%2d", &nTemp);
//            RFile.Second = nTemp;
//        }
//
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//
//
///*****************************************************************************
////启动图片文件查找
////@nYear: 年
////@nMonth: 月
////@nDay: 日
////@nBeginTime: 开始时间，以秒为单位
////@nEndTime: 结束时间，以秒为单位
////@nType: 文件类型
////@nChannel: 录像对应的通道
////@pfnRecFindCB: 文件回调函数
////@pFindUsr: 文件查找用户自定义数据
////@pfnGetExitCB: 判断是否需要退出
////@pExitUsr: 判断退出函数
////文件查找过程中，需要不停调用pfnGetExitCB，来判断是否需要退出
////查找到文件，及时调用pfnRecFindCB，调用上层
//******************************************************************************/
//void CTTXStreamWork::FindJpegFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nType, int nChannel
//                , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr)
//{
//    if(m_FactoryType == 46)
//    {
//        yh_search_jpg_file(nYear, nMonth, nDay, nBeginTime, nEndTime, nType, nChannel, pfnRecFindCB, pFindUsr, pfnGetExitCB, pExitUsr);
//    }
//    else
//    {
//        //示例查找当前目录下的record目录
//        char szDir[256] = {0};
//        #if 0
//        if(m_FactoryType == 43) // :/DCIM/Camera/IMG_20171207_173627A.jpg  后视镜厂家
//        {
//            //strncpy(szDir, TTXRecordWorkIns()->GetLogPath(), sizeof(szDir) - 1);
//            snprintf(szDir, 256,"%s", TTXRecordWorkIns()->GetJpgPath());
//            TTXLOG_INFO("CTTXNetService::FindJpegFile  szDir:%s",szDir);
//
//        }else{
//            strncpy(szDir, TTXRecordWorkIns()->GetJpgPath(), sizeof(szDir) - 1);
//
//        }
//        #endif
//        strncpy(szDir, TTXRecordWorkIns()->GetJpgPath(), sizeof(szDir) - 1);
//        TTXLOG_INFO("CTTXNetService::FindJpegFile  szDir:%s",szDir);
//        if (strlen(szDir) <= 0)
//        {
//            return ;
//        }
//
//        int nLastPos = strlen(szDir) - 1;
//        if (szDir[nLastPos] == '/')
//        {
//            szDir[nLastPos] = '\0';
//        }
//        //暂时只考虑通道0
//        if (TTX_CHANNEL_ALL == nChannel || TTX_CHANNEL_ALL_EX == nChannel|| 0 == nChannel)
//        {
//            if (TTX_RECTYPE_ALL == nType || TTX_RECTYPE_NORMAL == nType)
//            {
//                //目录
//                DIR * dir = NULL;
//                //目录环境
//                struct dirent *dir_env;
//                //文件描述
//                struct stat stat_file;
//                //打开目录
//                dir = opendir(szDir);
//                if (dir != NULL)
//                {
//                    while( (dir_env = readdir(dir)) != NULL )//读文件描述表
//                    {
//                        //判断是否需要退出
//                        if (pfnGetExitCB(pExitUsr))
//                        {
//                            TTXLOG_INFO("CTTXStreamWork::FindJpegFile pfnGetExitCB true");
//                            break;
//                        }
//
//                        //放弃CPU占用
//                        ttxSleep(0);
//
//                        //排除.和..
//                        if(strcmp(dir_env->d_name,".")==0  || strcmp(dir_env->d_name,"..")==0)
//                        {
//                            continue;
//                        }
//
//                        TTXRecFile_S RFile;
//                        memset(&RFile, 0, sizeof(RFile));
//                        //把文件全名保存到新变量
//                        strcpy(RFile.szFileName, szDir);
//                        strcat(RFile.szFileName, "/");
//                        strcat(RFile.szFileName, dir_env->d_name);
//
//                        //获取文件描述信息
//                        int ret = stat(RFile.szFileName, &stat_file);
//                        if (ret >= 0)
//                        {
//                            if( !S_ISDIR(stat_file.st_mode) && CheckJpgFileName(RFile.szFileName))
//                            {
//                                RFile.uiFileLen = stat_file.st_size;
//                                GetJpgFileTime(RFile.szFileName, RFile);
//
//                                int jpgTime = RFile.Hour * 3600 + RFile.Minute * 60 + RFile.Second;
//                                TTXLOG_INFO("CTTXStreamWork::GetJpgFileTime %d,%d,%d,%d,%d,%d %d %d %d channel:%d jpgTime:%d nBeginTime;%d nEndTime:%d",
//                                RFile.Year, RFile.Month, RFile.Day, RFile.Hour, RFile.Minute, RFile.Second,
//                                nYear, nMonth, nDay, RFile.Channel, jpgTime, nBeginTime, nEndTime);
//                                if (RFile.Year == (nYear - 2000) && RFile.Month == nMonth && RFile.Day == nDay
//                                    && ( jpgTime >= nBeginTime && jpgTime <= nEndTime)  )
//                                {
//                                    //RFile.Channel = 0;
//                                    RFile.Type = 0;
//                                    pfnRecFindCB(&RFile, pFindUsr);
//                                }
//
//                            }
//                        }
//                    }
//                    closedir(dir);    dir = NULL;
//                }
//            }
//        }
//    }
//
//}
//
///*****************************************************************************
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
//void CTTXStreamWork::FindLogFile(int nYear, int nMonth, int nDay, int nBeginTime, int nEndTime, int nType, int nChannel
//                    , TTXPfnRecFindCB pfnRecFindCB, void* pFindUsr, TTXPfnGetExitCB pfnGetExitCB, void* pExitUsr)
//{
//    //示例查找当前Sd目录下的日志
//    char szDir[256] = {0};
//    strncpy(szDir, TTXRecordWorkIns()->GetLogPath(), sizeof(szDir) - 1);
//    if (strlen(szDir) <= 0)
//    {
//        return ;
//    }
//
//    int nLastPos = strlen(szDir) - 1;
//    if (szDir[nLastPos] == '/')
//    {
//        szDir[nLastPos] = '\0';
//    }
//    //暂时只考虑通道0
//    if (TTX_CHANNEL_ALL == nChannel || TTX_CHANNEL_ALL_EX == nChannel|| 0 == nChannel)
//    {
//        if (TTX_RECTYPE_ALL == nType || TTX_RECTYPE_NORMAL == nType)
//        {
//            //目录
//            DIR * dir = NULL;
//            //目录环境
//            struct dirent *dir_env;
//            //文件描述
//            struct stat stat_file;
//            //打开目录
//            dir = opendir(szDir);
//            if (dir != NULL)
//            {
//                while( (dir_env = readdir(dir)) != NULL )//读文件描述表
//                {
//                    //判断是否需要退出
//                    if (pfnGetExitCB(pExitUsr))
//                    {
//                        TTXLOG_INFO("CTTXStreamWork::FindLogFile pfnGetExitCB true");
//                        break;
//                    }
//
//                    //放弃CPU占用
//                    ttxSleep(0);
//                    //排除.和..
//                    if(strcmp(dir_env->d_name,".")==0  || strcmp(dir_env->d_name,"..")==0 )
//                    {
//                        continue;
//                    }
//                    //仅仅保留gdispatch.log和remotegdispatch.log
//                    if(strcmp(dir_env->d_name,"gdispatch.log") ==0 || strcmp(dir_env->d_name,"remotegdispatch.log") ==0)
//                    {
//                        //TTXLOG_INFO("CTTXStreamWork::FindLogFile start dir_env->d_name:%s", dir_env->d_name);
//                    }else
//                    {
//                        continue;
//                    }
//                    TTXRecFile_S RFile;
//                    memset(&RFile, 0, sizeof(RFile));
//                    //把文件全名保存到新变量
//                    strcpy(RFile.szFileName, szDir);
//                    strcat(RFile.szFileName, "/");
//                    strcat(RFile.szFileName, dir_env->d_name);
//                    //TTXLOG_INFO("CTTXStreamWork::FindLogFile start szFileName:%s dir_env->d_name:%s", RFile.szFileName, dir_env->d_name);
//                    //获取文件描述信息
//                    int ret = stat(RFile.szFileName, &stat_file);
//                    if (ret >= 0)
//                    {
//                        if( !S_ISDIR(stat_file.st_mode))
//                        {
//
//                            time_t        st_atime = stat_file.st_mtime; //最后访问时间
//                            struct tm* t = NULL;
//                            t = localtime(&st_atime);
//                            if (t)
//                            {
//                                RFile.Year = t->tm_year - 100;
//                                RFile.Month = t->tm_mon + 1;
//                                RFile.Day = t->tm_mday;
//                                RFile.Hour = t->tm_hour;
//                                RFile.Minute = t->tm_min;
//                                RFile.Second = t->tm_sec;
//                            }
//                            RFile.uiFileLen = stat_file.st_size;
//                            TTXLOG_INFO("CTTXStreamWork::FindLogFile %d,%d,%d,%d,%d,%d fileLen;%d",
//                                RFile.Year, RFile.Month, RFile.Day, RFile.Hour, RFile.Minute, RFile.Second,    RFile.uiFileLen);
//                            int jpgTime = RFile.Hour * 3600 + RFile.Minute * 60 + RFile.Second;
//                            if ((RFile.Year + 2000) == nYear && RFile.Month == nMonth && RFile.Day == nDay
//                                && ( jpgTime >= nBeginTime && jpgTime <= nEndTime)  )
//                            {
//                                RFile.Channel = 0;
//                                RFile.Type = 0;
//                                pfnRecFindCB(&RFile, pFindUsr);
//                            }
//
//                        }
//                    }
//                }
//                closedir(dir);    dir = NULL;
//            }
//        }
//    }
//
//}
//
///*****************************************************************************
////设备进行图片抓拍操作，并将图片保存到文件中
////并将文件路径返回给网络库
////网络库将保存好的图片传送到服务器上
////@nChannel: 通道信息
////@szFileName: 图片文件名称，全路径
////@bDelete: 表示文件上传完成后，是否执行删除文件操作
////设备可以将图片存储到硬盘上，也可以存储到内存中
////如果设备没有硬盘，则建议存储到内存文件中
//******************************************************************************/
//bool CTTXStreamWork::Snapshot(int nChannel, char* szFileName, bool& bDelete)
//{
//    bDelete = false;
//    return CallBackSnapshot(nChannel, szFileName);
//}
//
///*****************************************************************************
////通知进行录像回放操作
////@szFile: 录像文件名称
////@ppRecFile:上层 需要创建录像解析对象子类返回给SDK，SDK调用此对象将文件解析成帧信息
////如果返回false，则表示文件不存在
////调用流程
////    1、先InitRecFile，取得文件解析对象
////     2、pRecFile->OpenFile，调用文件解析对象打开文件接口
////    3、pRecFile->GetFileInfo，取得文件信息
////    4、pRecFile->ReadFrame，读取帧数据
//******************************************************************************/
//bool CTTXStreamWork::InitRecFile(CTTXRecFile** ppRecFile)
//{
//    *ppRecFile = new CTtxRecReader();
//    return true;
//}
//
///*****************************************************************************
////释放文件解析对象
////@pRecFile: 录像解析对象，此对象由InitRecFile 接口创建
//******************************************************************************/
//void CTTXStreamWork::FreeRecFile(CTTXRecFile* pRecFile)
//{
//    TTX_SAFE_DELETE_OBJECT(pRecFile);
//}
//
//bool CTTXStreamWork::CheckUpgradeVer(const char* szVer)
//{
//    TTXLOG_INFO("CTTXStreamWork::CheckUpgradeVer szVer:%s",szVer);
//    strncpy(mszVer,szVer,sizeof(mszVer) - 1);
//    return true;
//}
//
///***返回升級路徑*****/
//bool CTTXStreamWork::GetUpgradeFile(char* szFileName)
//{
//    //TTXLOG_INFO("CTTXStreamWork::GetUpgradeFile mUpdateFilePath:%s",mUpdateFilePath);
//    strncpy(szFileName, mUpdateFilePath, sizeof(mUpdateFilePath) - 1);
//    //snprintf(szFileName,64,"%s",mszVer);
//    //strncpy(szFileName + sizeof(mUpdateFilePath) - 1,mszVer,sizeof(mszVer) - 1);
//    strcat(szFileName, mszVer);
//    strcat(szFileName, ".apk");
//    //TTXLOG_INFO("CTTXStreamWork::GetUpgradeFile szFileName:%s",szFileName);
//    return true;
//}
//
//bool CTTXStreamWork::CheckUpgradeFile(const char* szFileName)
//{
//    TTXLOG_INFO("CTTXStreamWork::CheckUpgradeFile true szFileName:%s",szFileName);
//    return true;
//}
//
//void CTTXStreamWork::UpgradeDevice(const char* szFileName)
//{
//    //TTXLOG_INFO("CTTXStreamWork::UpgradeDevice true szFileName:%s",szFileName);
//    //TTXLOG_INFO("CTTXStreamWork::UpgradeDevice true mszVer:%s",mszVer);
//    CallBackUpgradeDev(szFileName);
//}
//
//
//
////获取软件版本信息
////@szVersion: 版本信息
////@nVerLen: szVersion缓存的长度, 上层拷贝长度不得超过此长度
//void CTTXStreamWork::GetSoftwareVersion(char* szVersion, int nVerLen)
//{
//    TTXLOG_INFO("CTTXStreamWork::GetSoftwareVersion");
//    char szOut[1024] = {0};
//    int nOutLen = sizeof(szOut);
//    CallBackDevInfo(200001, "", szOut, nOutLen); //CallBackDevInfo
//    cJSON *json = cJSON_Parse(szOut);
//    if (json != NULL)
//    {
//        //{\"Version\":\"123456\"}
//        strncpy(m_szVersion, cJSON_GetObjectItemString(json, "Version"), sizeof(m_szVersion) - 1);
//        nVerLen =  strlen(m_szVersion) + 1;
//        strncpy(szVersion, m_szVersion, nVerLen);
//        cJSON_Delete(json);
//    }
//    TTXLOG_INFO("CTTXStreamWork::GetSoftwareVersion szVersion:%s nVerLen:%d",szVersion,nVerLen);
//}
//
////获取3G状态
////@n3GStatus: 0表示无效，1表示有效
////@n3GType: 网络类型0表示2G,  1表示EVDO,  2表示WCDMA, 3表示TD-WCDMA, 4 TD_LED , 5 FDD
////@sz3GAddress: 3G拔号后的地址
//void CTTXStreamWork::Get3GStatus(int &n3GStatus, int& n3GType, char* sz3GAddress, int n3GAddrLen)
//{
//    TTXLOG_INFO("CTTXStreamWork::Get3GStatus");
//    char szOut[1024] = {0};
//    int nOutLen = sizeof(szOut);
//    CallBackDevInfo(200002, "", szOut, nOutLen); //CallBackDevInfo
//    cJSON *json = cJSON_Parse(szOut);
//    if (json != NULL)
//    {
//        //{\"netstatus\":\"1\",\"netstandard\":\"1\",\"ip\":\"192.168.1.22\"}
//        int Status = cJSON_GetObjectItemInteger(json, "netstatus");
//        if(Status != 3)
//        {
//            n3GStatus = 0;
//            cJSON_Delete(json);
//            return;
//        }
//        n3GStatus = 1;
//        n3GType = cJSON_GetObjectItemInteger(json, "netstandard");
//
//        strncpy(m_sz3gIP, cJSON_GetObjectItemString(json, "ip"), n3GAddrLen);
//        n3GAddrLen = strlen(m_sz3gIP) + 1;
//        strncpy(sz3GAddress, m_sz3gIP, n3GAddrLen);
//        cJSON_Delete(json);
//    }
//    TTXLOG_INFO("CTTXStreamWork::Get3GStatus sz3GAddress:%s n3GAddrLen:%d",sz3GAddress,n3GAddrLen);
//}
//
////获取WIFI状态
////@nWifiStatus: 0表示无效，1表示有效
////@szWifiAddress: WIFI  的网络地址
////@nWifiAddrLen: WIFI  的网络地址
//void CTTXStreamWork::GetWifiStatus(int &nWifiStatus, char* szWifiAddress, int nWifiAddrLen)
//{
//    /***netstatus 0 都无效 1：wifi 3: 3G
//     * netstandard 3G状态赋值解析
//     * ip IP地址
//     * */
//    TTXLOG_INFO("CTTXStreamWork::GetWifiStatus");
//    char szOut[1024] = {0};
//    int nOutLen = sizeof(szOut);
//    CallBackDevInfo(200003, "", szOut, nOutLen); //CallBackDevInfo
//    cJSON *json = cJSON_Parse(szOut);
//    if (json != NULL)
//    {
//        //{\"netstatus\":\"1\",\"netstandard\":\"1\",\"ip\":\"192.168.1.22\"}
//        int Status = cJSON_GetObjectItemInteger(json, "netstatus");
//        if(Status != 1)
//        {
//            nWifiStatus = 0;
//            cJSON_Delete(json);
//            return ;
//        }
//        nWifiStatus = 1;
//
//        strncpy(m_szWifiIP, cJSON_GetObjectItemString(json, "ip"), sizeof(m_szWifiIP) - 1);
//        nWifiAddrLen = strlen(m_szWifiIP) + 1;
//        strncpy(szWifiAddress, m_szWifiIP, nWifiAddrLen);
//        cJSON_Delete(json);
//    }
//    TTXLOG_INFO("CTTXStreamWork::GetWifiStatus szWifiAddress:%s nWifiAddrLen:%d",szWifiAddress,nWifiAddrLen);
//}
//
////获取磁盘信息
//    //@nDiskCount: 磁盘数目
//    //@szDiskValue: 16000_8000_32000_8000 格式, 单位MB, 16000表示所有空间为16000MB, 8000表示剩余空间为8000MB
//    //          如果0_0  则表示硬盘出错
//    //        中间使用_   分隔
//    //@nDiskValLen: szDiskValue缓存的长度, 上层拷贝长度不得超过此长度
//void CTTXStreamWork::GetDiskInfo(int& nDiskCount, char* szDiskValue, int nDiskValLen)
//{
//
//    TTXLOG_INFO("CTTXStreamWork::GetDiskInfo");
//    char szOut[1024] = {0};
//    int nOutLen = sizeof(szOut);
//    CallBackDevInfo(200004, "", szOut, nOutLen); //CallBackDevInfo
//    cJSON *json = cJSON_Parse(szOut);
//    if (json != NULL)
//    {
//        //{\"diskcount\":\"1\",\"diskvalue\":\"16000_8000\"}
//        nDiskCount = cJSON_GetObjectItemInteger(json, "diskcount");
//
//        strncpy(m_szDiskValue, cJSON_GetObjectItemString(json, "diskvalue"), sizeof(m_szDiskValue) - 1);
//        nDiskValLen = strlen(m_szDiskValue) + 1;
//        strncpy(szDiskValue, m_szDiskValue, nDiskValLen);
//        cJSON_Delete(json);
//    }
//    TTXLOG_INFO("CTTXStreamWork::GetDiskInfo szDiskValue:%s nDiskValLen:%d nDiskCount:%d",szDiskValue,nDiskValLen,nDiskCount);
//}
//
//void CTTXStreamWork::GetVideoStatus(int & nVideoLost, int & nVideoRecord)
//{
//    TTXLOG_INFO("CTTXStreamWork::GetVideoStatus");
//    char szOut[1024] = {0};
//    int nOutLen = sizeof(szOut);
//    CallBackDevInfo(200005, "", szOut, nOutLen); //CallBackDevInfo
//    cJSON *json = cJSON_Parse(szOut);
//    if (json != NULL)
//    {
//        //{\"videolost\":\"1\",\"videorecord\":\"1\"}
//        nVideoLost = cJSON_GetObjectItemInteger(json, "videolost");
//        nVideoRecord = cJSON_GetObjectItemInteger(json, "videorecord");
//        cJSON_Delete(json);
//    }
//    TTXLOG_INFO("CTTXStreamWork::GetVideoStatus nVideoLost:%d nVideoRecord:%d",nVideoLost,nVideoRecord);
//}
