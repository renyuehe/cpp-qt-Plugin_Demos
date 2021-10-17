#include "ComInstance.h"
#include <QDebug>

ComInstance* ComInstance::m_ComInstance = Q_NULLPTR;
ComInstance *ComInstance::GetInstance()
{
    if(!m_ComInstance){
        m_ComInstance = new ComInstance();
    }
    return m_ComInstance;
}

ComInstance::ComInstance()
{

}

/**
 * @brief SendMsg 消息发布接口
 * @param code
 * @param msg
 */
void ComInstance::SendMsg(int code, const QVariant& msg)
{
    if(code == 10000)
        m_CurrentPluginName = msg.toString();

    emit SendMsgToManager(code,msg);
}
