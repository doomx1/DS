﻿#ifndef INDEX_H
#define INDEX_H

#include <QWidget>
QT_BEGIN_NAMESPACE;
class QVBoxLayout;
QT_END_NAMESPACE;
class Report;
class Index : public QWidget
{
    Q_OBJECT
public:
    explicit Index(QWidget *parent);
    ~Index();
private:
    QVBoxLayout *mainLayout;
    void initUI();
    Report *mReport;

signals:
    void notifyCreateTask(const QString address);

public slots:
};

#endif // INDEX_H
