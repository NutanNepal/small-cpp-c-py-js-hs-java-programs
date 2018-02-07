def explosion(n):
    if n == 0 or n == 1:
        return 1
    if n < 0:
        return 0
    else:
        sequence = getpentagonal(n)
        i = 0
        pn = 0
        t=2
        global explosionlist
        explosionlist = {}
        while t > -1:
            t = n - sequence[i][1]
            pn += (-1)**(abs(sequence[i][0])-1) * explosion(t)
            i += 1
        return pn

def getpentagonal(n):
    j, k = 2, 1
    sequence = [[1, 1]]
    while n >= sequence[len(sequence)-1][1]:
        k += (-1)**((j % 2) +1) * j
        sequence.append([k, int((3*k**2-k)/2)])
        j += 1
    return sequence
