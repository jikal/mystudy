#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
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


#endif // CLIENTSOCKET_H
