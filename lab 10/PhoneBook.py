import psycopg2
import csv

conn = psycopg2.connect(
    host="localhost",
    database="python",
    user="postgres",
    password="ulytau05"
)

cur = conn.cursor()

def create_table():
    command = """
    CREATE TABLE IF NOT EXISTS phonebook(
        Name VARCHAR(255) NOT NULL,
        Surname VARCHAR(255),
        Phone VARCHAR(255) NOT NULL,
        Email VARCHAR(255)
    )
    """
    try:
        cur.execute(command)
        conn.commit()
    except (Exception, psycopg2.DatabaseError) as error:
        print(error)

def upload_data_from_csv(filename):
    with open(filename, 'r') as f:
        reader = csv.reader(f)
        for row in reader:
            cur.execute(
                "INSERT INTO PhoneBook (Name, Surname, Phone, Email) VALUES (%s, %s, %s, %s)",
                (row[0], row[1], row[2], row[3])
            )
        conn.commit()
        print("Data uploaded successfully from", filename)


def update_data(value, name):
    cur.execute(
        "UPDATE PhoneBook SET Phone = %s WHERE Name = %s",
        (value, name)
    )
    conn.commit()
    print("Data updated successfully")


def insert_data_from_console():
    first_name = input("Enter first name: ")
    last_name = input("Enter last name: ")
    phone = input("Enter phone number: ")
    email = input("Enter email address: ")
    cur.execute(
        "INSERT INTO PhoneBook (Name, Surname, Phone, Email) VALUES (%s, %s, %s, %s)",
        (first_name, last_name, phone, email)
    )
    conn.commit()
    print("Data inserted successfully")


def query_data(key, value):
    cur.execute(
        f"SELECT * FROM PhoneBook WHERE {key} = %s",
        (value,)
    )
    rows = cur.fetchall()
    if len(rows) == 0:
        print("No records found")
    else:
        for row in rows:
            print(row)


def delete_data(key, value):
    cur.execute(
        f"DELETE FROM PhoneBook WHERE {key} = %s",
        (value,)
    )
    conn.commit()
    print("Data deleted successfully")

create_table()
action = input("[1]Insert contact directly, [2]Insert contacts from csv file, [3]find and update the contact, [4]Querry phonebook, [5]REmove contact \n Choose the command:  ")
if action == '1':
    insert_data_from_console()
elif action == '2':
    upload_data_from_csv('data.csv')
elif action == '3':
    name = input('Name: ')
    value = input('New Phone number: ')
    update_data(value, name)
elif action == '4':
    key = None
    act = input('By [n]ame, [s]urname or [p]hone: ').strip().lower()
    if act == 'n':
        key = 'Name'

    elif act == 's':
        key = 'Surname'
    elif act == 'p':
        key = 'Phone'
    value = input(f'{key}: ')
    query_data(key, value)
elif action == '5':
    act = input('By [n]ame, [s]urname or [p]hone: ').strip().lower()
    if act == 'n':
        key = 'Name'

    elif act == 's':
        key = 'Surname'
    elif act == 'p':
        key = 'Phone'
    value = input(f'{key}: ')
    delete_data(key, value)
else:
    print('Command is not defined!')
    exit()

cur.close()
conn.close()

