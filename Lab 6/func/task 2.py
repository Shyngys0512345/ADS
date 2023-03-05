def count(string):
    uppercase = sum(1 for c in string if c.isupper())
    lowercase = sum(1 for c in string if c.islower())
    return uppercase, lowercase

new = input("Enter a string: ")
result = count(new)
print("Uppercase:", result[0])
print("Lowercase:", result[1])