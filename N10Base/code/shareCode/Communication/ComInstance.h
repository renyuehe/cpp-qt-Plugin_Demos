#ifndef COMINSTANCE_H
#define COMINSTANCE_H

#include <QObject>
#include <QVariant>
#include <QDebug>

#include <QtCore/qglobal.h>


#if defined(COMMON_LIBRARY)
#  define D_COMMONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define D_COMMONSHARED_EXPORT Q_DECL_IMPORT
#endif

class D_COMMONSHARED_EXPORT ComInstance : public QObject{
    Q_OBJECT
private:
    static ComInstance* m_ComInstance;
    QString m_CurrentPluginName;

public:
    static ComInstance *GetInstance();

private:
    ComInstance();

public:
    /**
     * @brief SendMsg 消息发布接口
     * @param code
     * @param msg
     */
    void SendMsg(int code, const QVariant& msg);

signals:
    /**
     * @brief SendMsg 消息发布信号
     * @param code
     * @param msg
     */
    void SendMsgToManager(int code,const QVariant& msg);
};

#define SEND_MSG(code,msg)\
{\
    ComInstance* instance = ComInstance::GetInstance();\
    instance->SendMsg(code,msg);\
};


#endif // COMINSTANCE_H
