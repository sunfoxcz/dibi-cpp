#ifndef DIBIDEFINE_H
#define DIBIDEFINE_H

#include <mysql/mysql.h>
#include <sys/types.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef __int64_t   int64;
typedef __int32_t   int32;
typedef __int16_t   int16;
typedef __int8_t    int8;
typedef __uint64_t  uint64;
typedef __uint32_t  uint32;
typedef __uint16_t  uint16;
typedef __uint8_t   uint8;
typedef uint16      WORD;
typedef uint32      DWORD;
typedef uint64      OBJECT_HANDLE;

typedef struct _dibiConfig_t
{
    string driver;
    string host;
    string username;
    string password;
    string database;
    string charset;

    _dibiConfig_t() {};
    _dibiConfig_t(string Host, string Username, string Password, string Database,
            string Driver = "MySQL", string Charset = "utf8")
    {
        driver = Driver;
        host = Host;
        username = Username;
        password = Password;
        database = Database;
        charset = Charset;
    };
} dibiConfig_t;

typedef vector<string> dibiFields;
typedef map<string,string> dibiRow;
typedef map<string,string> dibiPairs;

#endif
