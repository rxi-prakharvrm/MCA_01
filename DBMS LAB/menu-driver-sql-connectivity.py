import pymysql
from decimal import Decimal

conn = pymysql.connect(host="127.0.0.1", user="root", password="")
cur = conn.cursor()

dbSelected = "No"
def createDatabase():
    try:
        dbname = input("\nEnter database name: ")
        cur.execute(f'CREATE DATABASE IF NOT EXISTS {dbname}')
        conn.commit()
        print(f"\n>>> {dbname} database created! <<<")
        print("\n---------------------------------------")
    except:
        print("!!!!!!! SOME ERROR OCCURRED !!!!!!!")
        conn.rollback()

def showDatabases():
    try:
        cur.execute(f'SHOW DATABASES')
        rows = cur.fetchall()
        print("\n >>> Databases <<< \n")
        for row in rows:
            print(row)
        print("\n---------------------------------------")
    except:
        print("\n!!!!!!! SOME ERROR OCCURRED !!!!!!!")
        print("\n---------------------------------------")
        conn.rollback()

def useDatabase():
    try:
        global dbSelected
        dbname = input("\nEnter database name: ")
        cur.execute(f'USE {dbname}')
        conn.commit()
        dbSelected = dbname
        print(f"\n>>> {dbname} database is selected! <<<")
        print("\n---------------------------------------")
    except:
        print("\n!!!!!!! SOME ERROR OCCURRED !!!!!!!")
        print("\n---------------------------------------")
        conn.rollback()

# def createTable():

def showTables():
    try:
        cur.execute(f'SHOW TABLES')
        rows = cur.fetchall()
        print("\n >>> Tables <<< \n")
        for row in rows:
            print(row)
        print("\n---------------------------------------")
    except:
        print("\n!!!!!!! SOME ERROR OCCURRED !!!!!!!")
        print("\n---------------------------------------")
        conn.rollback()

def DescribeTable():
    try:
        tname = input("\nEnter table name: ")
        cur.execute(f'DESC {tname}')
        rows = cur.fetchall()
        print("\n >>> Rows <<< \n")
        for row in rows:
            print(row)
        print("\n---------------------------------------")
    except:
        print("\n!!!!!!! SOME ERROR OCCURRED !!!!!!!")
        print("\n---------------------------------------")
        conn.rollback()
        
def insertRecords():
    try:
        tname = input("\nEnter table name: ")
        query = f"SELECT COLUMN_NAME, DATA_TYPE FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '{tname}';"
        cur.execute(query)
        rows = cur.fetchall()
        attributeNames = [attributeName[0] for attributeName in rows]
        attributeTypes = [attributeType[1] for attributeType in rows]
        query = f"INSERT INTO {tname} VALUES("

        for i in range(0, len(rows)):
            if(attributeTypes[i] == "int"):
                query += f'{input(f"{attributeNames[i]} = ")}' + ", "
                
            elif(attributeTypes[i] == "decimal"):
                query += f'{Decimal(input(f"{attributeNames[i]} = "))}' + ", "

            else:
                query += f"'{input(f"{attributeNames[i]} = ")}'" + ", "

        query = query[0:len(query)-2]
        query += ");"
        print(query)
        cur.execute(f'{query}')
        conn.commit()
        print("Record pupulated successfully!")
        print("\n---------------------------------------")
    except:
        print("\n!!!!!!! SOME ERROR OCCURRED !!!!!!!")
        print("\n---------------------------------------")
        conn.rollback()

isContinue = True
while isContinue:
    print("\n================================================")
    print(f">>>>> {dbSelected} database is selected! <<<<<<")
    print("================================================\n")

    print("1. Create Database")
    print("2. Show Databases")
    print("3. Use Database")
    print("4. Create Table")
    print("5. Show Tables")
    print("6. Describe Table")
    print("7. Update Table")
    print("8. Drop Table")
    print("9. Insert Records")
    print("10. Select Records")
    print("11. Update Records")
    print("12. Delete Records")
    print("13. Exit Program")

    choice = int(input("\nEnter your choice: "))
    print("\n---------------------------------------")
    
    if choice == 1:
        createDatabase()

    elif choice == 2:
        showDatabases()

    elif choice == 3:
        useDatabase()

    elif choice == 4:
        createTable()

    elif choice == 5:
        showTables()
        
    elif choice == 6:
        DescribeTable()

    elif choice == 7:
        updateTable()

    elif choice == 8:
        dropTable()

    elif choice == 9:
        insertRecords()

    elif choice == 10:
        selectRecords()

    elif choice == 11:
        updateRecords()

    elif choice == 12:
        deleteRecords()
    
    elif choice == 13:
        isContinue = False
        
    else:
        print("Invalid Choice!")


