import os

path = input("Enter file path: ")

if not os.access(path, os.F_OK):
    print(f"File '{path}' does not exist")
elif not os.access(path, os.W_OK):
    print(f"File '{path}' cannot be deleted")
else:
    os.remove(path)
    print(f"File '{path}' deleted")