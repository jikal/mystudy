#ifndef PUBLICTHREAD_H
#define PUBLICTHREAD_H

#include <QWidget>
#include "mainwindow.h"
#include <QThread>
class MainWindow;
class publicthread : public QThread
{
    Q_OBJECT
public:
    publicthread(MainWindow *pMainWindow);
    void run();
    MainWindow *_pMainWindow;
signals:
    void tellClientSend();
public slots:
    void iwilltell();
};

#endif // PUBLICTHREAD_H



