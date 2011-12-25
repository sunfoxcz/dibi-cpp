#ifndef DIBI_RESULT_H
#define DIBI_RESULT_H

#include "dibiDefine.h"

class dibiResult
{
    public:
        virtual bool fetch() {};
        virtual string fetchSingle() {};
        virtual dibiPairs fetchPairs(string, string) {};
        virtual string getField(string) {};
        virtual dibiRow getFields() {};
        virtual dibiFields getFieldNames() {};
        virtual int64 getNumRows() {};
        virtual int32 getNumFields() {};

    protected:
        virtual void doFetch() {};
};

#endif
