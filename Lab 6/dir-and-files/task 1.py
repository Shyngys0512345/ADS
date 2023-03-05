import os

s = str(input("Enter a path: "))

print("directories")
print([item for item in os.listdir(s) if os.path.isdir(os.path.join(s, item))])

print("files")
print([item for item in os.listdir(s) if os.path.isfile(os.path.join(s, item))])

print("files and directories")
print(os.listdir(s))