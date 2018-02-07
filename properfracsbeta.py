"""def proper_fractions(denominator):
    if denominator == 1:
        return 0
    factors = [x for x in range(2, denominator) if not denominator % x]
    if not factors:
        return denominator - 1
    primefactors = list(set(factors) - set([x for x in factors for y in factors if y < x and not x % y]))
    if denominator % 2:
        allnumsexceptone = [x for x in range (2, denominator)]
    else:
        allnumsexceptone = [x for x in range (3, denominator, 2)]
    tosubtract = [x for x in allnumsexceptone for y in primefactors if not x % y]
    return len(allnumsexceptone) - len(set(tosubtract)) + 1

print(proper_fractions(19719719))"""

def getprimefactors(denominator):
    """"start getting factors of denominator"""
    factors = []
    divisor = 3
    if not denominator % 2:
        factors.append(2)
    while divisor <= denominator / 2:
        if not denominator % divisor:
            factors.append(divisor)
        divisor += 2

    primefactors = list(set(factors) - set([x for x in factors for y in factors if y < x and not x % y]))
    return primefactors

def isPrime(num):
    if not num % 2:
        return False
    divisor = 3
    upperbound = num
    while divisor <= upperbound:
        if not num % divisor:
            return False
        upperbound = num / divisor
        divisor += 2
    return True
        
def proper_fractions(denominator):
    if isPrime(denominator):
        return denominator - 1
    primefactors = getprimefactors(denominator)
    
    multiply = 1
    for x in primefactors:
        multiply *= x
    if multiply == denominator:
        return mainproper(denominator, primefactors)
    else:
        lesserval = mainproper(multiply, primefactors)
        return int(lesserval * (denominator/multiply))

def mainproper(denominator, primefactors):
    if denominator == 1:
        return 0
    if denominator % 2:
        tosubtract = [x for x in range(2, denominator) for y in primefactors if not x % y]
    else:
        tosubtract = [x for x in range(3, denominator, 2) for y in primefactors if not x % y]
    return denominator - len(set(tosubtract)) - 1 if denominator % 2 else int(denominator/2) - len(set(tosubtract))