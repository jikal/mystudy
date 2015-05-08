#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
#include <QWidget>
#include "serverSocket.h"

namespace Ui {
class chat_Server;
}

class chat_Server:public QWidget
{
    Q_OBJECT

public:
    explicit chat_Server(QWidget *parent = 0);
    ~chat_Server();
private slots:
    void startServer();
private:
    Ui::chat_Server *ui;
    ServerSocket *serversocket;
};

#endif // CHAT_SERVER_H
