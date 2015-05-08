#ifndef CONNECT_H
#define CONNECT_H
#include <QTcpSocket>
#define MESSAGE_LEN sizeof(MESSAGE)
typedef enum {
        MT_NULL,
        REGUSR,
        LOGINUSR,
        SENDMESSAGE
    }MsgType;
typedef struct message_t {
    MsgType msgtype;
    QString name;
    QString pass;
}MESSAGE;

class ConnectSocket : public QTcpSocket
{
    Q_OBJECT

public:
    ConnectSocket( QObject *parent = NULL );

signals:
    void closing(int sockfd);

protected:
    void sendData(const char *data, qint32 len);

    void requestRegusr();
    void requestLoginusr();
    void requestSendmessage();

private slots:
    void readMessage();
};




#endif // CONNECT_H
