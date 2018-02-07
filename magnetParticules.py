def doubles(maxk, maxn):
    total = 0
    for k in range (1, maxk + 1):
        for n in range (1, maxn + 1):
            if k*(n+1)**(2*k) > 10000000:
                pass
            else:
                total += 1/(k*(n + 1)**(2*k))
    return total
