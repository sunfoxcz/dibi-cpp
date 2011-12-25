#include "dibi.h"

map<string,dibiDriver *> dibi::registry;
dibiDriver *dibi::conn;
string dibi::sql;

dibiDriver* dibi::connect(dibiConfig_t config)
{
    return dibi::connect(config, "default");
}

dibiDriver* dibi::connect(dibiConfig_t config, string name)
{
    string className = "dibi" + config.driver + "Driver";

    registry[name] = dibiDriver::createInstance(className, config);
    registry[name]->connect();
    conn = registry[name];

    return conn;
}

bool dibi::isConnected()
{
    return getConnection()->isConnected();
}

dibiDriver* dibi::getConnection()
{
    return conn;
}

dibiDriver* dibi::getConnection(string name)
{
    if (registry[name])
    {
        return registry[name];
    }

    return NULL;
}

void dibi::activate(string name)
{
    conn = registry[name];
}

int64 dibi::insertId()
{
    return getConnection()->getInsertId();
}

int64 dibi::affectedRows()
{
    return getConnection()->getAffectedRows();
}

dibiResult* dibi::nativeQuery(string query)
{
    sql = query;
    return conn->nativeQuery(query);
}
