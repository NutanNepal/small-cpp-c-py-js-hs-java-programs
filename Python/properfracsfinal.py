import time

def getprimefactors(denominator):
    """start getting factors of denominator"""
    factors = []
    divisor = 3
    if not denominator % 2:
        factors.append(2)
    while divisor <= denominator / 2:
        if not denominator % divisor:
            factors.append(divisor)
        divisor += 2
    #for prime factors. getting the list of composite factors
    #and subtracting it from factors
    primefactors = list(set(factors) - set([x for x in factors for y in factors if y < x and not x % y]))
    return primefactors

def isPrime(num):
    """check for the primality of the number to avoid further
    unnecessary calculations
    This function returns isPrime(2) as False"""
    if not num % 2:
        return False
    divisor = 3
    upperbound = num ** 0.5
    while divisor <= upperbound:
        if not num % divisor:
            return False
        divisor += 2
    return True

def proper_fractions(denominator):
    """random comment
    """
    if denominator == 1:
        return 0
    if isPrime(denominator):
        #print("PRIME, baby!!")
        return denominator - 1
    primefactors = getprimefactors(denominator)

    multiply = 1
    for prime in primefactors:
        multiply *= prime

    result = 1
    for primes in primefactors:
        result *= primes - 1

    if multiply == denominator:
        return result
    else:
        return result * int(denominator/multiply)

start = time.time()
for i in range (5):
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
print ("run time = ", end - start)

start2 = time.time()
for i in range (5):
    print(isPrime(5))
    print(getprimefactors(15895613))
    print(isPrime(895613))
    print(getprimefactors(81000156))
    print(getprimefactors(19889563))
    print(isPrime(19719719))
    print(getprimefactors(568956))
    print(getprimefactors(1532420))
    print(isPrime(500000003))
    print(getprimefactors(9999999))

end2 = time.time()
print ("run time = ", end2 - start2)

print(start - end - start2 + end2)