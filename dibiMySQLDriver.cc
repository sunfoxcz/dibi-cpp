#include "dibiMySQLDriver.h"

/**
 * Constructor
 */
dibiMySQLDriver::dibiMySQLDriver (dibiConfig_t configSetting)
    : dibiDriver(configSetting)
{
}

/**
 * Destructor
 */
dibiMySQLDriver::~dibiMySQLDriver ()
{
    if (isConnected())
    {
        mysql_close(resource);
    }
}

/**
 * Connects to database and sets charset
 */
void dibiMySQLDriver::connect()
{
    resource = mysql_init(NULL);

    mysql_options(resource, MYSQL_SET_CHARSET_NAME, config.charset.c_str());
    mysql_real_connect(
            resource,
            config.host.c_str(),
            config.username.c_str(),
            config.password.c_str(),
            config.database.c_str(),
            3306, NULL, 0);
}

/**
 * Returns True if database connected, else False
 */
bool dibiMySQLDriver::isConnected()
{
    if (resource)
    {
        return true;
    }

    return false;
}

/**
 * Returns last MySQL error
 */
string dibiMySQLDriver::errorInfo()
{
    stringstream error;
    error << mysql_errno(resource) << ": " << mysql_error(resource);
    return error.str();
}

/**
 * Returns last inserted id
 */
int64 dibiMySQLDriver::getInsertId()
{
    return insertId;
}

/**
 * Returns number of rows affected by query
 */
int64 dibiMySQLDriver::getAffectedRows()
{
    return affectedRows;
}

/**
 * Executes SQL query without parsing
 */
dibiMySQLResult* dibiMySQLDriver::nativeQuery(string sql)
{
    if (!resource)
    {
        return NULL;
    }

    MYSQL_RES *result;

    if (mysql_query(resource, sql.c_str()))
    {
        return NULL;
    }

    result = mysql_store_result(resource);
    if (!result)
    {
        return NULL;
    }

    // ulozime pocet ovlivnenych radku
    affectedRows = mysql_affected_rows(resource);
    if (!affectedRows)
    {
        mysql_free_result(result);
        return NULL;
    }

    // ulozime hodnotu klice posledniho vlozeneho zaznamu
    insertId = mysql_insert_id(resource);

    return new dibiMySQLResult(result);
}
