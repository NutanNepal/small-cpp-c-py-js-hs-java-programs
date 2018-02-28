def getpaths(n):
    path = [0, 2, 6]
    for i in range (3, n+1):
        nextpath = 2*path[i-1]+2 + (i-1)**2
        path.append(nextpath)
    return path[n]

print(getpaths(20))