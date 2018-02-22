import time
def proper_fractions(denominator):
    numproperfracs = denominator
    if not denominator % 2:
        numproperfracs -= numproperfracs//2
    stack = [2]
    i=3
    while (numproperfracs > 0) and (i < denominator//2):
        flag = True
        for y in stack:
            if not i % y:
                flag = False
        if flag:
            if not denominator % i:
                numproperfracs -= numproperfracs//i
            stack.append(i)
        print(stack)
        i += 2

    if numproperfracs == denominator:
        return numproperfracs - 1
    return numproperfracs

#9999999 should get 6637344
print(proper_fractions(15))
print(proper_fractions(9999999))
'''start = time.time()
for i in range (5):
    print(proper_fractions(15))
    print(proper_fractions(15895613))
    print(proper_fractions(895613))
    print(proper_fractions(81000156))
    print(proper_fractions(19889563))
    print(proper_fractions(19719719))
    print(proper_fractions(568956))
    print(proper_fractions(1532420))
    print(proper_fractions(500000003))
    print(proper_fractions(9999999))

end = time.time()
print ("run time = ", end - start)'''