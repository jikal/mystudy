#ifndef _DATABASE_H
#define _DATABASE_H

#include <QSqlDatabase>

class database
{
public:
    database();
    static QSqlDatabase db;
    static bool Open();
    static void Close();
};

#endif
