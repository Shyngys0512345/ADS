import os

path = input("Enter a path: ")

if os.path.exists(path):
    print("Path exists.")
    dirname, filename = os.path.split(path)
    print("Directory:", dirname)
    print("Filename:", filename)
else:
    print("Path does not exist.")