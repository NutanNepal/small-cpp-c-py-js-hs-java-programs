import time
def getprimefactors(denominator):
    """start getting factors of denominator"""
    factors = set()
    if not denominator % 2:
        factors.add(2)
        factors.add(denominator//2)
    divisor, j = 3, denominator / 2
    while divisor <= j:
        if not denominator % divisor:
            j = denominator//divisor
            factors.add(divisor)
            factors.add(j)
        divisor += 2
    #for prime factors. getting the list of composite factors
    #and subtracting it from factors
    primefactors = factors - set(x for x in factors for y in factors if y < x and not x % y)
    return primefactors

def isPrime(num):
    """check for the primality of the number to avoid further
    unnecessary calculations
    This function returns isPrime(2) as False"""
    if num == 2: return True
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
    """main function that checks if the prime factors
    of the denominator are its only factors.
    the reason to check this depends on following observation:
    15 = 5 * 3: 8
    75 = 5 * 5 * 3: 5 * proper_fractions(5 * 3) = 5 * 8 = 40
    Here proper_fractions(75) (the primefactors of 75 (3, 5) are not its only
    factors) depends on proper_fractions(15)
    But the primefactors of 15 are its only factors so it's independent.
    #till now
    """
    if denominator == 1:
        return 0

    if isPrime(denominator):
        #print("PRIME, baby!!")
        return denominator - 1
    primefactors = getprimefactors(denominator)
    multiply = 1
    relativeprimes = 1
    for prime in primefactors:
        multiply *= prime
        relativeprimes *= prime - 1
    if multiply == denominator:
        return relativeprimes
    else:
        return int(relativeprimes * (denominator/multiply))

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