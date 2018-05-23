from sys import stdin

# Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

val = 0
for line in stdin:
  val = val + int(line)
print(str(val)[0:10])