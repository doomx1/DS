﻿#ifndef M_CUSTOMTASK_BRIDGE_H
#define M_CUSTOMTASK_BRIDGE_H


#include <QObject>

class MCustomTaskBridge : public QObject{
    Q_OBJECT
public:
    explicit MCustomTaskBridge(QObject *parent);
signals:
    void sendClickSignalToQt(const QString &eachp2,const QString &nodeName,const QString &nodeCode,const QString &loopXpath);
public slots:
    void clickSignalToQt(const QString &eachp2,const QString &nodeName,const QString &nodeCode,const QString &loopXpath);

};



//struct CompareXpathResult{
//    QString maxRepeatStr;
//    QString s1NotRepeatStr;
//    QString s2NotRepeatStr;

//    bool allowXpathObjMerge;
//};

#endif // M_CUSTOMTASK_BRIDGE_H
