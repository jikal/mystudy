#include "database.h"

database::database()
{

}

QSqlDatabase database::db = QSqlDatabase::addDatabase("QMYSQL");

bool database::Open()
{
    db.setHostName(QLatin1String("localhost"));
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("qqdb");

    if(!db.open())
    {
        return false;
    }
    return true;
}

void database::Close()
{
    db.close();
}
