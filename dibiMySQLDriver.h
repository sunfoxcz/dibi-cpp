#ifndef DIBI_MYSQL_DRIVER_H
#define DIBI_MYSQL_DRIVER_H

#include "dibiDefine.h"
#include "dibiDriver.h"
#include "dibiMySQLResult.h"

class dibiMySQLDriver : public dibiDriver
{
    private:
        MYSQL *resource;
        int64 affectedRows;
        int64 insertId;

    public:
        dibiMySQLDriver(dibiConfig_t);
        ~dibiMySQLDriver();
        virtual void connect();
        virtual bool isConnected();
        virtual string errorInfo();
        virtual int64 getInsertId();
        virtual int64 getAffectedRows();
        virtual dibiMySQLResult* nativeQuery(string);
};

#endif
