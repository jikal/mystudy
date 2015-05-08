#ifndef SERVER_COMMON_H
#define SERVER_COMMON_H
#include <QString>
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
#endif // SERVER_COMMON_H
