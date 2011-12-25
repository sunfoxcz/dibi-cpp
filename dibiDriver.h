#ifndef DIBI_DRIVER_H
#define DIBI_DRIVER_H

#include "dibiDefine.h"
#include "dibiResult.h"

class dibiDriver
{
    protected:
        dibiConfig_t config;

    public:
        dibiDriver() {}
        dibiDriver(dibiConfig_t);
        static dibiDriver* createInstance(string, dibiConfig_t);
        virtual void connect() {}
        virtual bool isConnected() {}
        virtual string errorInfo() {}
        virtual int64 getInsertId() {}
        virtual int64 getAffectedRows() {}
        virtual dibiResult* nativeQuery(string) {}
};

#endif
