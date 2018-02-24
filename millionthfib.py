def fib(n):
    import math
    fibonacci = [0, 1]
    absolute = abs(n)
    if absolute >= 0 and absolute <= 1:
        returnval = fibonacci[n]
    else:
        if absolute % 2:
            returnval = int(fib(math.trunc(absolute/2)) ** 2 + fib(math.trunc(absolute/2) + 1) ** 2)
        else:
            get = fib(int(absolute/2))
            returnval = int(get * get + 2 * get * fib(int(absolute/2 - 1)))

    if n < 0 and not absolute % 2:
        return -1 * returnval
    return returnval

print(fib(500000))