ndx = 2
fibPrev = 1
fibCurr = 1
while len(str(fibCurr)) < 1000:
    fibNew = fibCurr+fibPrev
    fibPrev = fibCurr
    fibCurr = fibNew
    ndx = ndx + 1
print(ndx)