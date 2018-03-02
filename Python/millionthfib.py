"""def fib(n):
    import math
    absolute = abs(n)
    if absolute == 0 or absolute == 1:
        returnval = absolute
    else:
        if absolute % 2:
            returnval = fib(absolute//2) ** 2 + fib(absolute//2 + 1) ** 2
        else:
            get = fib(int(absolute/2))
            returnval = int(get * get + 2 * get * fib(int(absolute/2 - 1)))
    if n < 0 and not absolute % 2:
        return -returnval
    return returnval"""

def fib(n):
  if n < 0: return (-1)**(n % 2 + 1) * fib(-n)
  a = b = x = 1
  c = y = 0
  while n:
    if n % 2 == 0:
      (a, b, c) = (a * a + b * b,
                   a * b + b * c,
                   b * b + c * c)
      n /= 2
    else:
      (x, y) = (a * x + b * y,
                b * x + c * y)
      n -= 1
  return y

import time
start = time.time()
for _ in range (1):
    print(fib(1000000))
end = time.time()
print("time = ", end - start)