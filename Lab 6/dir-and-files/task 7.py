s = str(input("File name: "))

fileread = open(s, "r")

new = str(input("New file name: "))
filewrite = open(new, "w")
filewrite.write(fileread.read())