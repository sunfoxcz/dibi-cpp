#include "test_example.h"

int main ()
{
    /* first we need to create configuration object */
    dibiConfig_t config("localhost", "root", "", "mysql");
    dibi::connect(config);
    
    if (!dibi::isConnected())
    {
        /* if connect failed, return an error */
        printf("MySQL Error %s\n", dibi::getConnection()->errorInfo().c_str());
        return 1;
    }

    /* execute raw query */
    res = dibi::nativeQuery("SELECT Host, User FROM user ORDER BY User, Host");
    printf("SQL: %s\n", dibi::sql.c_str());

    if (!res)
    {
        /* error occured, print it */
        printf("MySQL Error %s\n", dibi::getConnection()->errorInfo().c_str());
        return 1;
    }

    /* print insert id and affected rows */
    printf("Insert Id: %i\n", dibi::insertId());
    printf("Affected Rows: %i\n", dibi::affectedRows());

    /* iterate result field names */
    fieldNames = res->getFieldNames();
    for (it = fieldNames.begin(); it != fieldNames.end(); it++)
    {
        printf(": %s", it->c_str());
    }
    printf("\n");

    /* iterate result */
    while (res->fetch())
    {
        fields = res->getFields();
        for (iv = fields.begin(); iv != fields.end(); iv++)
        {
            printf(": %s", iv->second.c_str());
        }
        printf("\n");
    }

    return 0;
}
