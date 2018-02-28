def fibfusc(n):
    if n == 0:
        return (1,0)
    elif n == 1:
        return (0,1)
    else:
        x, y = fibfusc(int(n//2))
        return (-y*(2*x+3*y), (x+2*y)*(x+4*y)) if n % 2 else ((x+y)*(x-y), y*(2*x+3*y))
