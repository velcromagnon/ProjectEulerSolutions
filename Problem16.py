# Problem 16
# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#
# What is the sum of the digits of the number 2^1000?
strVal = str(2 ** 1000);
total = 0
for c in strVal:
    total = total + int(c) - int('0');

print(total);
