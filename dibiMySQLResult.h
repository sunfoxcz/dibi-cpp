#ifndef DIBI_MYSQL_RESULT_H
#define DIBI_MYSQL_RESULT_H

#include "dibiDefine.h"
#include "dibiResult.h"

class dibiMySQLResult : public dibiResult
{
    private:
        MYSQL_RES *result;
        int64 numRows;
        int32 numFields;
        dibiFields fieldNames;
        dibiRow row;

    public:
        dibiMySQLResult(MYSQL_RES *);
        ~dibiMySQLResult();
        bool fetch();
        string fetchSingle();
        dibiPairs fetchPairs(string, string);
        string getField(string);
        dibiRow getFields();
        dibiFields getFieldNames();
        int64 getNumRows();
        int32 getNumFields();

    protected:
        void doFetch();
};

#endif
