import math
import time

number = int(input("Enter the number: "))
milliseconds = int(input("Enter the number of milliseconds: "))

time.sleep(milliseconds / 1000)
ans = math.sqrt(number)
print(f"Square root of {number} after {milliseconds} milliseconds is {ans}.")