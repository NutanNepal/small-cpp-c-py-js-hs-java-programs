def dbl_linear(n):
    u = [1]
    def into(a,b):
        c = []
        if len(a) > n:
            pass
        else:
            for x in b:
                _1 = 2*x+1
                _2 = 3*x+1
                flag1 = False
                flag2 = False
                for y in a:
                    if (y == _1):
                        flag1 = True
                    if (y == _2):
                        flag2 = True
                if flag1 == False:
                    c.append(_1)
                if flag2 == False:
                    c.append(_2)
            a += c
            into(a, c)
    into(u,u)
    u.sort()
    print(u)
    return u[n]
print(dbl_linear(50))
