from functools import reduce

numbers = input("Enter a list of numbers: ")
numbers = [int(n) for n in numbers.split()]

def multiply(numbers):
    return reduce(lambda x, y: x * y, numbers)

result = multiply(numbers)
print(result)