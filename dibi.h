#ifndef DIBI_H
#define DIBI_H

#include "dibiDefine.h"
#include "dibiDriver.h"

class dibi
{
    public:
        static map<string,dibiDriver *> registry;
        static dibiDriver *conn;
        static string sql;

    public:
        static dibiDriver* connect(dibiConfig_t);
        static dibiDriver* connect(dibiConfig_t, string);
        static bool isConnected();
        static dibiDriver* getConnection();
        static dibiDriver* getConnection(string);
        static void activate(string);
        static int64 insertId();
        static int64 affectedRows();
        static dibiResult* nativeQuery(string);
};

#endif
