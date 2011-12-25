#include "dibiDriver.h"
#include "dibiMySQLDriver.h"

dibiDriver::dibiDriver(dibiConfig_t configSetting)
{
    config = configSetting;
}

dibiDriver* dibiDriver::createInstance(string className, dibiConfig_t config)
{
    if (className == "dibiMySQLDriver")
    {
        return new dibiMySQLDriver(config);
    }
    else
    {
        return NULL;
    }
}
