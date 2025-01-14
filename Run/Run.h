#ifndef RUN_H
#define RUN_H

#include <QDialog>
#include <QtCore5Compat>
#include "RunAlertDialog.h"

QT_BEGIN_NAMESPACE;
class QVBoxLayout;
class QHBoxLayout;
class QStackedWidget;
class QTableWidget;
class QToolButton;
class QLineEdit;
QT_END_NAMESPACE;

class RunPipline;
class RunHelper;
class MFlowStepParams;
class RunSettings;
class RunWebView;

class MFlowStepParamsOpenWeb;
class MFlowStepParamsClickEle;
class MFlowStepParamsExtract;
class MFlowStepParamsLoop;
class MFlowStepParamsInput;
class MFlowStepParamsSwitch;
class MFlowStepParamsMouse;

class ComLoadingLabel;
struct MTask;
struct MExtractSingleItem;

class  Run : public QDialog
{
    Q_OBJECT
public:
    explicit Run(MTask *task);
    ~Run();

protected:
    void closeEvent(QCloseEvent *) override;

private:
    QVBoxLayout *boxLayout;
    void initTopMenuUi();
    QLineEdit *addrLine;
    ComLoadingLabel *loadingLabel;
    void initWebViewUi();
    QStackedWidget *webViewStacked;

    void initBottomUi();
    QToolButton  *tableStateBtn;
    QTableWidget *tableWidget;
    QLabel *pageLabel;
    QLabel *pageLogLabel;
    QLabel *bottomLogLabel; // 采集过程日志
    QPushButton *exportBtn;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    void updateTurnPage(int num,bool isFinal);

    QStringList m_tbfields;
private:
    MTask *m_task;
    RunHelper *m_helper;
    RunPipline *m_pipline;
    RunAlertDialog *m_alert;
    RunSettings    *mRunSettings;

    void startNextStep(QString lastStepID);

    void startOpenWeb(MFlowStepParamsOpenWeb * params);// 01x
    void startClickEle(MFlowStepParamsClickEle * params);// 02x
    void startClickEleRoll(MFlowStepParamsClickEle * params,QString feedback);
    void startExtract(MFlowStepParamsExtract * params);// 03x
    void startInput(MFlowStepParamsInput * params);// 04x
    void startLoopHead(MFlowStepParamsLoop * params);// 07x
    void startLoopTail(QString loopStepID,QString loopInnerLastStepID);// 07x
    void startMouse(MFlowStepParamsMouse * params);// 08x

    void endOpenWeb(MFlowStepParamsOpenWeb *params);
    void endClickEle(MFlowStepParamsClickEle * params,bool next);
    void endExtract(MFlowStepParamsExtract * params,QString feedback);
    void endInput(MFlowStepParamsInput * params);
    void endMouse(MFlowStepParamsMouse * params);

    void sendStartJobCommand();
    void sendStopJobCommand(RunAlertDialog::MessageType messageType,const QString &msg);

    void loaddb(int p = 1);
    int  m_currentPage = 1;   // 当前页的页数
    int  m_totalPage = 0; // 当前总页数


signals:
    void notifyThreadPushData(QString stepID,QString res);

public slots:
    void onThreadPipline(int num,QStringList names,QStringList values);
    void onThreadInfo(int type,QString info);
    void onWebViewUrlChanged(const QString &url);
    void onChangeWebView(RunWebView *webView);//切换显示中的webView（不需要同步执行切换）


};

#endif // RUN_H
