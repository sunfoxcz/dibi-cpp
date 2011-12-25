#include "dibiMySQLResult.h"

/**
 * Constructor.
 */
dibiMySQLResult::dibiMySQLResult(MYSQL_RES *res)
{
    result = res;
    numRows = mysql_num_rows(result);
    numFields = mysql_num_fields(result);

    // ziskame si z mysql nazvy sloupcu a ulozime je do vectoru
    MYSQL_FIELD *field;
    for (int32 i = 0; i < numFields; i++)
    {
        field = mysql_fetch_field(result);
        fieldNames.push_back(field->name);
    }
}

/**
 * Destructor.
 */
dibiMySQLResult::~dibiMySQLResult()
{
    mysql_free_result(result);
}

/**
 * Fetches one row, returns False if there are no more rows
 */
bool dibiMySQLResult::fetch()
{
    doFetch();

    if (row.size() > 0)
    {
        return true;
    }

    return false;
}

/**
 * Fetches one row and returns first column value
 */
string dibiMySQLResult::fetchSingle()
{
    doFetch();

    if (row.size() == 0)
    {
        return string();
    }

    dibiRow::iterator it;
    it = row.begin();

    return (*it).second;
}

/**
 * Iterates over all rows and returns map of entered key and value
 */
dibiPairs dibiMySQLResult::fetchPairs(string key, string value)
{
    dibiPairs pairs;

    while (fetch())
    {
        pairs[getField(key)] = getField(value);
    }

    return pairs;
}

/**
 * Returns one column of entered name from row
 */
string dibiMySQLResult::getField(string name)
{
    return row[name];
}

/**
 * Returns map of all columns where key is name of column
 * and value is real column value
 */
dibiRow dibiMySQLResult::getFields()
{
    return row;
}

/**
 * Returns vector with table column names
 */
dibiFields dibiMySQLResult::getFieldNames()
{
    return fieldNames;
}

/**
 * Returns number of query results
 */
int64 dibiMySQLResult::getNumRows()
{
    return numRows;
}

/**
 * Returns number of row columns
 */
int32 dibiMySQLResult::getNumFields()
{
    return numFields;
}

/**
 * Fetches row from database and maps columns to internal map
 * by column names
 */
void dibiMySQLResult::doFetch()
{
    row.clear();

    MYSQL_ROW res;
    if (res = mysql_fetch_row(result))
    {
        for (int32 i = 0; i < numFields; i++)
        {
            row[fieldNames[i]] = res[i];
        }
    }
}
