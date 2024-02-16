import time


def proper_fractions(n):
    x = 1
    for i in range(2, n):
        for j in range(2, i + 1):
            if not (i % j == 0 or n % j == 0):
                x += 1
    return x


start = time.time()

for i in range(2):
    print(proper_fractions(5))
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
print("run time = ", end - start)

