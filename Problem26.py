highestNumber = 1
highestRepeating = 0

for i in range(1,1001):
    val = i
    while val % 2 == 0:
        val //= 2
    while val % 5 == 0:
        val //= 5
    done = False
    nines = 0
    count = 0
    if val > 1:
        while not done:
            count = count + 1
            nines = nines * 10 + 9
            if nines % val == 0:
                done = True
    if count > highestRepeating:
        highestRepeating = count
        highestNumber = i

print(highestNumber, highestRepeating)



