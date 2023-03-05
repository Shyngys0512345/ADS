def is_palindrome(string):
    return string == string[::-1]

my_str = input("Enter a string: ")
if is_palindrome(my_str):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")